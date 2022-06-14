/*
 * GuiItf.c
 *
 *  Created on: 2022. máj. 14.
 *      Author: Margit Robert
 */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "Peri.h"
#include "stdio.h"
#include <string.h>
#include "GuiItf.h"

/*** MCP3208 ***/
#define MCP320X_CH0          0
#define MCP320X_CH1          1
#define MCP320X_CH2          2
#define MCP320X_CH3          3
#define MCP320X_CON_SINGLE_END  (1<<3)


/*** Log Flash ***/
#define LOG_FLASH_PAGE_SIZE     256
#define LOG_FLASH_PP_CMD_SZIE   5

static uint8_t LogFlashPageWrite(uint32_t addr, uint8_t *data, uint32_t size);
static void Spi2TransmittReceive(uint8_t *tx, uint8_t *rx, uint32_t length);
static void Spi2Transmitt(uint8_t *data, uint32_t size);
static void Spi2Receive(uint8_t *data, uint32_t size);
static void Clock(void);

/* Private user code ---------------------------------------------------------*/

/* Commmon--------------------------------------------------------------------*/
void Spi2TransmittReceive(uint8_t *tx, uint8_t *rx, uint32_t size)
{
  for(uint32_t j=0; j < size; j++)
  {
    uint8_t rx_mask = 0x80;
    uint8_t tx_mask = 0x80;
    for(uint8_t i = 0; i<8;i++)
    {
      HAL_GPIO_WritePin(SPI2_CLK_GPIO_Port, SPI2_CLK_Pin, GPIO_PIN_RESET);
      if(tx[j] & tx_mask)
        HAL_GPIO_WritePin(SPI2_MOSI_GPIO_Port, SPI2_MOSI_Pin, GPIO_PIN_SET);
      else
        HAL_GPIO_WritePin(SPI2_MOSI_GPIO_Port, SPI2_MOSI_Pin, GPIO_PIN_RESET);
      tx_mask>>=1;
      DelayUs(1);
      if(HAL_GPIO_ReadPin(SPI2_MISO_GPIO_Port, SPI2_MISO_Pin) == GPIO_PIN_SET)
        rx[j] |= rx_mask;
      else
        rx[j] &= ~rx_mask;
      rx_mask>>=1;
      HAL_GPIO_WritePin(SPI2_CLK_GPIO_Port, SPI2_CLK_Pin, GPIO_PIN_SET);
      DelayUs(1);
    }
    HAL_GPIO_WritePin(SPI2_CLK_GPIO_Port, SPI2_CLK_Pin, GPIO_PIN_RESET);
  }
}

static void Spi2Transmitt(uint8_t *data, uint32_t size)
{
  for(uint32_t j=0; j < size; j++)
  {
    uint8_t mask = 0x80;
    for(uint8_t i=0; i<8; i++)
    {
      if(data[j] & mask)
        HAL_GPIO_WritePin(SPI2_MOSI_GPIO_Port, SPI2_MOSI_Pin, GPIO_PIN_SET);
      else
        HAL_GPIO_WritePin(SPI2_MOSI_GPIO_Port, SPI2_MOSI_Pin, GPIO_PIN_RESET);
      mask>>=1;

      HAL_GPIO_WritePin(SPI2_CLK_GPIO_Port, SPI2_CLK_Pin, GPIO_PIN_SET);
      DelayUs(1);
      HAL_GPIO_WritePin(SPI2_CLK_GPIO_Port, SPI2_CLK_Pin, GPIO_PIN_RESET);
      DelayUs(1);
    }
  }

}

void Spi2Receive(uint8_t *data, uint32_t size)
{
  for(uint32_t j=0; j < size; j++)
  {
    uint16_t mask = 0x80;
    for(uint8_t i = 0; i < 8; i++)
    {
      HAL_GPIO_WritePin(SPI2_CLK_GPIO_Port, SPI2_CLK_Pin, GPIO_PIN_SET);
      DelayUs(1);

      if(HAL_GPIO_ReadPin(SPI2_MISO_GPIO_Port, SPI2_MISO_Pin) == GPIO_PIN_SET)
        data[j]|= mask;
      else
        data[j]&=~mask;
      mask >>=1;

      HAL_GPIO_WritePin(SPI2_CLK_GPIO_Port, SPI2_CLK_Pin, GPIO_PIN_RESET);
      DelayUs(1);
    }
  }
}

static void Clock(void)
{
  HAL_GPIO_WritePin(SPI2_CLK_GPIO_Port, SPI2_CLK_Pin, GPIO_PIN_SET);
  DelayUs(5);
  HAL_GPIO_WritePin(SPI2_CLK_GPIO_Port, SPI2_CLK_Pin, GPIO_PIN_RESET);
  DelayUs(5);
}

/* Temperature  --------------------------------------------------------------*/
#define MACP320X_ARRAY_SIZE 3
uint8_t result[MACP320X_ARRAY_SIZE];
uint8_t param[MACP320X_ARRAY_SIZE];
/*
 *
 *config:
 *   MSB                          LSB
 *   0  | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
 *   X  | X | X | X |S/D|D2 |D1 |D0 |
 */
uint16_t Mcp320xGetValue(uint8_t config)
{
  uint16_t value = 0;
  param[0] = 0x01;
  param[1] = config << 0x04;
  param[2] = 0;
  HAL_GPIO_WritePin(AIN_CS_GPIO_Port, AIN_CS_Pin, GPIO_PIN_RESET);
  Spi2TransmittReceive(param, result, MACP320X_ARRAY_SIZE);
  HAL_GPIO_WritePin(AIN_CS_GPIO_Port, AIN_CS_Pin, GPIO_PIN_SET);
  value = (result[1]&0x03)<<8;
  value |= result[2];
  return value;
}

double PeriGetTemperature(uint8_t channel)
{
  uint16_t adc = Mcp320xGetValue(MCP320X_CON_SINGLE_END | channel /* MCP320X_CH0*/);
  double volts = adc * 2.5/1024;
  double temp = (-2.3654*volts*volts) + (-78.154*volts) + 153.857;
  return temp;
}

/* DIO -----------------------------------------------------------------------*/
uint16_t PeriGetInputs(void)
{
  uint16_t retval = 0;
  uint16_t mask = 0x8000;

  /*** Chip Select ***/
  HAL_GPIO_WritePin(DIO_CS_GPIO_Port, DIO_CS_Pin, GPIO_PIN_RESET);

  /*** Load ***/
  HAL_GPIO_WritePin(DIO_LD_GPIO_Port, DIO_LD_Pin, GPIO_PIN_RESET);
  Clock();
  HAL_GPIO_WritePin(DIO_LD_GPIO_Port, DIO_LD_Pin, GPIO_PIN_SET);

  for(uint8_t j = 0; j < 16; j++)
  {
    if(HAL_GPIO_ReadPin(SPI2_MISO_GPIO_Port, SPI2_MISO_Pin) == GPIO_PIN_SET)
      retval|= mask;
    else
      retval&=~mask;
    mask >>=1;
    Clock();
  }
  /*** Chip Select ***/
  HAL_GPIO_WritePin(DIO_CS_GPIO_Port, DIO_CS_Pin, GPIO_PIN_SET);
  return retval;
}

void PeriSetOutputs(uint8_t data)
{
  uint8_t mask = 0x80;
  /*** Write ***/
  for(uint8_t i=0; i<8; i++)
  {
    if(data & mask)
      HAL_GPIO_WritePin(SPI2_MOSI_GPIO_Port, SPI2_MOSI_Pin, GPIO_PIN_SET);
    else
      HAL_GPIO_WritePin(SPI2_MOSI_GPIO_Port, SPI2_MOSI_Pin, GPIO_PIN_RESET);
    mask>>=1;
    Clock();
  }
  /*** Update ***/
  HAL_GPIO_WritePin(DIO_WR_GPIO_Port, DIO_WR_Pin, GPIO_PIN_SET);
  DelayUs(1);
  HAL_GPIO_WritePin(DIO_WR_GPIO_Port, DIO_WR_Pin, GPIO_PIN_RESET);
}


/* LogFlash ------------------------------------------------------------------*/
/*
 * A flash 256Mbit-es, ez 32MByte (32000000Byte)
 * Egy page mérete 256Byte, ez igy 32000000/256 = 125000 ez "125 000 Line"
 * 0x00 00 00 00 -> Page 0 (Line) Start
 * 0x00 00 00 FF -> Page 1 (Line) End
 *
 * 0x00 00 01 00 -> Page 2 Start
 * 0x00 00 01 FF -> Page 2 End
 * ha leveszem a page-en belül címeket, akkor:
 * 0x00 00 00 .. FF FF FF ez 0-tól 16777215-ig terjedo cimtartomány (ehhez kell a 4 bájtos címzés)
 */
void LogFlashReadId (void)
{
  uint8_t id[] = {0x00, 0x00};

  /*** RDID - read identification***/
  HAL_GPIO_WritePin(FLS_CS_GPIO_Port, FLS_CS_Pin, GPIO_PIN_RESET);
  Spi2Transmitt((uint8_t[]){0x9F}, 1);
  Spi2Receive(id,sizeof(id));
  HAL_GPIO_WritePin(FLS_CS_GPIO_Port, FLS_CS_Pin, GPIO_PIN_SET);
}



static uint8_t LogFlashPageWrite(uint32_t addr, uint8_t *data, uint32_t size)
{

  if((addr % LOG_FLASH_PAGE_SIZE) !=0 )
    return PERIPH_ARG_ERROR;

  if(addr > 0xFFFFFF)
    return PERIPH_OUT_OF_RNG;

  /*** WREN - Write Enable***/
  HAL_GPIO_WritePin(FLS_CS_GPIO_Port, FLS_CS_Pin, GPIO_PIN_RESET);
  //Spi2Transmitt((uint8_t){0x06}, 1);
  HAL_GPIO_WritePin(FLS_CS_GPIO_Port, FLS_CS_Pin, GPIO_PIN_SET);

  /*** EN4B - Enter 4 Byte mode***/
  HAL_GPIO_WritePin(FLS_CS_GPIO_Port, FLS_CS_Pin, GPIO_PIN_RESET);
  Spi2Transmitt((uint8_t[]){0xB7}, 1);
  HAL_GPIO_WritePin(FLS_CS_GPIO_Port, FLS_CS_Pin, GPIO_PIN_SET);

  /*** PP - Page Program***/
  uint8_t cmd[LOG_FLASH_PP_CMD_SZIE];
  cmd[0] = 0x06;
  cmd[1] = addr;
  cmd[2] = addr >> 8;
  cmd[3] = addr >> 16;
  cmd[4] = addr >> 24;
  HAL_GPIO_WritePin(FLS_CS_GPIO_Port, FLS_CS_Pin, GPIO_PIN_RESET);
  Spi2Transmitt(cmd, LOG_FLASH_PP_CMD_SZIE);
  Spi2Transmitt(data, size);
  HAL_GPIO_WritePin(FLS_CS_GPIO_Port, FLS_CS_Pin, GPIO_PIN_SET);

  /*** WRDI - Write Disable ***/
  HAL_GPIO_WritePin(FLS_CS_GPIO_Port, FLS_CS_Pin, GPIO_PIN_RESET);
  Spi2Transmitt((uint8_t[]){0x04}, 1);
  HAL_GPIO_WritePin(FLS_CS_GPIO_Port, FLS_CS_Pin, GPIO_PIN_SET);

  return PERIPH_OK;
}

uint8_t LogFlashWriteLine(char *str)
{
  uint32_t page_addr = Device.LogLastPageAddress * 256;
  if (str == NULL)
    return PERIPH_ARG_ERROR;
  uint32_t size = strlen(str);
  if (size > 256 || size == 0)
    return PERIPH_ARG_ERROR;
  LogFlashPageWrite(page_addr, (uint8_t*)str, size );
  GuiItfLogIncPageAddr();
  return PERIPH_OK;
}

static char str[LOG_FLASH_PAGE_SIZE];

uint8_t LogFlashReadLine(uint32_t addr, char *data)
{
  uint32_t page_addr = Device.LogLastPageAddress * 256;

  if((page_addr % LOG_FLASH_PAGE_SIZE) !=0 )
    return PERIPH_ARG_ERROR;

  if(addr > 0xFFFFFF)
    return PERIPH_OUT_OF_RNG;

  /*** EN4B - Enter 4 Byte mode***/
  HAL_GPIO_WritePin(FLS_CS_GPIO_Port, FLS_CS_Pin, GPIO_PIN_RESET);
  Spi2Transmitt((uint8_t[]){0xB7}, 1);
  HAL_GPIO_WritePin(FLS_CS_GPIO_Port, FLS_CS_Pin, GPIO_PIN_SET);

  /*** READ4B - Read Data Byte by 4 byte address ***/
  HAL_GPIO_WritePin(FLS_CS_GPIO_Port, FLS_CS_Pin, GPIO_PIN_RESET);
  Spi2Transmitt((uint8_t[]){0x13}, 1);
  Spi2Receive((char*)str,LOG_FLASH_PAGE_SIZE);
  //uint32_t size = strlen(str);
  strcpy(data, str);

  HAL_GPIO_WritePin(FLS_CS_GPIO_Port, FLS_CS_Pin, GPIO_PIN_SET);
  return PERIPH_OK;
}
