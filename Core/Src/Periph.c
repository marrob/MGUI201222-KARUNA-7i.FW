/*
 * Periph.c
 *
 *  Created on: 2022. máj. 14.
 *      Author: Margit Robert
 */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "Periph.h"
#include "stdio.h"
#include <string.h>
#include "GuiItf.h"


/*** MCP3208 ***/
#define MCP320X_CH0          0
#define MCP320X_CH1          1
#define MCP320X_CH2          2
#define MCP320X_CH3          3
#define MCP320X_CON_SINGLE_END  (1<<3)

static void Spi2TransmittReceive(uint8_t *tx, uint8_t *rx, uint32_t length);
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

float PeriphReadTemp(uint8_t channel)
{
  uint16_t adc = Mcp320xGetValue(MCP320X_CON_SINGLE_END | channel /* MCP320X_CH0*/);
  float volts = adc * 2.5/1024;
  float temp = (-2.3654*volts*volts) + (-78.154*volts) + 153.857;
  return temp;
}

/* DIO -----------------------------------------------------------------------*/
uint16_t PeriphReadInputs(void)
{
  uint16_t retval = 0;
  uint16_t mask = 0x8000;

  /*** Chip Select ***/
  HAL_GPIO_WritePin(DIO_CS_GPIO_Port, DIO_CS_Pin, GPIO_PIN_RESET);

  /*** Load ***/
  HAL_GPIO_WritePin(DIO_LD_GPIO_Port, DIO_LD_Pin, GPIO_PIN_RESET);

    /*** Clcok ***/
    HAL_GPIO_WritePin(SPI2_CLK_GPIO_Port, SPI2_CLK_Pin, GPIO_PIN_SET);
    DelayUs(2);
    HAL_GPIO_WritePin(SPI2_CLK_GPIO_Port, SPI2_CLK_Pin, GPIO_PIN_RESET);
    DelayUs(2);

  HAL_GPIO_WritePin(DIO_LD_GPIO_Port, DIO_LD_Pin, GPIO_PIN_SET);

  for(uint8_t j = 0; j < 16; j++)
  {
    if(HAL_GPIO_ReadPin(SPI2_MISO_GPIO_Port, SPI2_MISO_Pin) == GPIO_PIN_SET)
      retval|= mask;
    else
      retval&=~mask;
    mask >>=1;

    /*** Clcok ***/
    HAL_GPIO_WritePin(SPI2_CLK_GPIO_Port, SPI2_CLK_Pin, GPIO_PIN_SET);
    DelayUs(2);
    HAL_GPIO_WritePin(SPI2_CLK_GPIO_Port, SPI2_CLK_Pin, GPIO_PIN_RESET);
    DelayUs(2);
  }
  /*** Chip Select ***/
  HAL_GPIO_WritePin(DIO_CS_GPIO_Port, DIO_CS_Pin, GPIO_PIN_SET);
  return retval;
}

void PeriphWriteOutputs(uint8_t data)
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

    /*** Clcok ***/
    HAL_GPIO_WritePin(SPI2_CLK_GPIO_Port, SPI2_CLK_Pin, GPIO_PIN_SET);
    DelayUs(2);
    HAL_GPIO_WritePin(SPI2_CLK_GPIO_Port, SPI2_CLK_Pin, GPIO_PIN_RESET);
    DelayUs(2);
  }

  /*** Update ***/
  HAL_GPIO_WritePin(DIO_WR_GPIO_Port, DIO_WR_Pin, GPIO_PIN_SET);
  DelayUs(1);
  HAL_GPIO_WritePin(DIO_WR_GPIO_Port, DIO_WR_Pin, GPIO_PIN_RESET);
}

