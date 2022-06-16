/*
 * GuiItf.c
 *
 *  Created on: 2022. máj. 14.
 *      Author: Margit Robert
 */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "Log.h"
#include "stdio.h"
#include <string.h>
#include "GuiItf.h"

/*** Log Flash ***/
static void Spi2Transmitt(uint8_t *data, uint32_t size);
static void Spi2Receive(uint8_t *data, uint32_t size);
static uint16_t FlashReadStatusReg(void);

/* Private user code ---------------------------------------------------------*/

/* Commmon--------------------------------------------------------------------*/
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

/* Log -----------------------------------------------------------------------*/
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
uint8_t LogFlashReadId (uint8_t *data, uint32_t size)
{
  /*** RDID - read identification***/
  HAL_GPIO_WritePin(FLS_CS_GPIO_Port, FLS_CS_Pin, GPIO_PIN_RESET);
  Spi2Transmitt((uint8_t[]){0x9F}, 1);
  Spi2Receive(data, size);
  HAL_GPIO_WritePin(FLS_CS_GPIO_Port, FLS_CS_Pin, GPIO_PIN_SET);
  return LOG_OK;
}

uint8_t LogFlashWriteLine(uint32_t line, uint8_t *data, uint32_t size)
{
  if(line > 0xFFFFFF)
    return LOG_OUT_OF_RNG;

  if(size == 0)
    return 0;

  uint32_t page = line * LOG_FLASH_PAGE_SIZE;

  /*** WREN - Write Enable***/
  HAL_GPIO_WritePin(FLS_CS_GPIO_Port, FLS_CS_Pin, GPIO_PIN_RESET);
  Spi2Transmitt((uint8_t[]){0x06}, 1);
  HAL_GPIO_WritePin(FLS_CS_GPIO_Port, FLS_CS_Pin, GPIO_PIN_SET);

  /*** EN4B - Enter 4 Byte mode***/
  HAL_GPIO_WritePin(FLS_CS_GPIO_Port, FLS_CS_Pin, GPIO_PIN_RESET);
  Spi2Transmitt((uint8_t[]){0xB7}, 1);
  HAL_GPIO_WritePin(FLS_CS_GPIO_Port, FLS_CS_Pin, GPIO_PIN_SET);

  /*** PP4B - Page Program***/
  uint8_t cmd[5];
  cmd[0] = 0x12;
  cmd[1] = page;
  cmd[2] = page >> 8;
  cmd[3] = page >> 16;
  cmd[4] = page >> 24;
  HAL_GPIO_WritePin(FLS_CS_GPIO_Port, FLS_CS_Pin, GPIO_PIN_RESET);
  Spi2Transmitt(cmd, sizeof(cmd));
  Spi2Transmitt(data, size);
  HAL_GPIO_WritePin(FLS_CS_GPIO_Port, FLS_CS_Pin, GPIO_PIN_SET);

  /*** WRDI - Write Disable ***/
  HAL_GPIO_WritePin(FLS_CS_GPIO_Port, FLS_CS_Pin, GPIO_PIN_RESET);
  Spi2Transmitt((uint8_t[]){0x04}, 1);
  HAL_GPIO_WritePin(FLS_CS_GPIO_Port, FLS_CS_Pin, GPIO_PIN_SET);

  return LOG_OK;
}

uint8_t LogFlashReadLine(uint32_t line, uint8_t *data, uint32_t size)
{
  uint32_t page = line * LOG_FLASH_PAGE_SIZE;

  if(line > 0xFFFFFF)
    return LOG_OUT_OF_RNG;

  if(size > 256)
    return LOG_OUT_OF_RNG;

  if(size == 0)
    return 0;

  memset(data, 0x00, size);

  /*** EN4B - Enter 4 Byte mode***/
  HAL_GPIO_WritePin(FLS_CS_GPIO_Port, FLS_CS_Pin, GPIO_PIN_RESET);
  Spi2Transmitt((uint8_t[]){0xB7}, 1);
  HAL_GPIO_WritePin(FLS_CS_GPIO_Port, FLS_CS_Pin, GPIO_PIN_SET);

  /*** READ4B - Read Data Byte by 4 byte address ***/
  uint8_t cmd[5];
  cmd[0] = 0x13;
  cmd[1] = page;
  cmd[2] = page >> 8;
  cmd[3] = page >> 16;
  cmd[4] = page >> 24;
  HAL_GPIO_WritePin(FLS_CS_GPIO_Port, FLS_CS_Pin, GPIO_PIN_RESET);
  Spi2Transmitt(cmd, sizeof(cmd));
  Spi2Receive(data, size);
  HAL_GPIO_WritePin(FLS_CS_GPIO_Port, FLS_CS_Pin, GPIO_PIN_SET);

  for(uint32_t i = 0; i < size; i++ )
    if(data[i]==255)
      data[i]=0;

  return LOG_OK;
}

uint8_t LogFlashErase(void)
{
  /*** WREN - Write Enable***/
  HAL_GPIO_WritePin(FLS_CS_GPIO_Port, FLS_CS_Pin, GPIO_PIN_RESET);
  Spi2Transmitt((uint8_t[]){0x06}, 1);
  HAL_GPIO_WritePin(FLS_CS_GPIO_Port, FLS_CS_Pin, GPIO_PIN_SET);

  /*** CE - Chip Erase ***/
  HAL_GPIO_WritePin(FLS_CS_GPIO_Port, FLS_CS_Pin, GPIO_PIN_RESET);
  Spi2Transmitt((uint8_t[]){0x60}, 1);
  HAL_GPIO_WritePin(FLS_CS_GPIO_Port, FLS_CS_Pin, GPIO_PIN_SET);

  uint32_t timestamp = HAL_GetTick();
  uint8_t status = 0;
  do
  {
    if(HAL_GetTick() - timestamp > 160000)
      return LOG_TIMEOUT;
    status = FlashReadStatusReg();
  }while((status & 0x01)); /*Write In Progress*/

  return LOG_OK;
}

uint16_t FlashReadStatusReg(void)
{
  uint8_t status = 0;

  /*** RDSR - Read Status Register ***/
  HAL_GPIO_WritePin(FLS_CS_GPIO_Port, FLS_CS_Pin, GPIO_PIN_RESET);
  Spi2Transmitt((uint8_t[]){0x05}, 1);
  Spi2Receive(&status, sizeof(status));
  HAL_GPIO_WritePin(FLS_CS_GPIO_Port, FLS_CS_Pin, GPIO_PIN_SET);

  return status;
}


