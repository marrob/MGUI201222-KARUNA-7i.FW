/*
 * GuiItf.c
 *
 *  Created on: 2022. máj. 14.
 *      Author: Margit Robert
 */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "DisplayLight.h"
#include "GuiItf.h"
#include "EEPROM.h"

#define EEP_MAGICWORD_ADDR       0x0000
#define EPP_BOOTUP_CNT_ADDR      0x0004
#define EEP_BACKLIGHT_ADDR       0x0008
#define EEP_KARUNA_CTRL_ADDR     0x000C
#define MAGIC_WORD               0x55AA55AA

/* Private user code ---------------------------------------------------------*/

uint8_t GuiItfLoad(void)
{
  uint32_t value = 0;
  HAL_StatusTypeDef status = HAL_OK;
  status = EepromU32Read(EEP_MAGICWORD_ADDR, &value);

  //If EPPROM does not have Magic Word then it is the first Start...
  //We have to write default values and the Magic Word
  if(status!= HAL_OK || value != MAGIC_WORD)
  {
    GuiItfSetDefault();
  }
  else
  {

    /*** Boot Up counter ***/
    EepromU32Read(EPP_BOOTUP_CNT_ADDR, &value);
    Device.Diag.BootUpCnt = value;
    Device.Diag.BootUpCnt++;
    EepromU32Write(EPP_BOOTUP_CNT_ADDR, Device.Diag.BootUpCnt);

    DelayMs(10);

    /*** Backlight ***/
    EepromU32Read(EEP_BACKLIGHT_ADDR, &value);
    BacklightSet(value);

    /*** KARUNA CTRL ***/
    EepromU32Read(EEP_KARUNA_CTRL_ADDR, &value);
    Device.Karuna.Outputs = value;
  }

  return GUIITF_OK;
}


uint8_t GuiItfSetDefault(void)
{
  uint32_t value = 0;

  /*** Boot Up counter ***/
  value = 0;
  EepromU32Write(EPP_BOOTUP_CNT_ADDR, value);
  Device.Diag.BootUpCnt = value;

  /*** Backlight ***/
  value = 100;
  EepromU32Write(EEP_BACKLIGHT_ADDR, value);
  BacklightSet((uint8_t)value);

  /*** KARUNA CTRL ***/
  value = (KRN_CTRL_RCA) | (KRN_CTRL_BNC) | (KRN_CTRL_XLR) | (KRN_CTRL_I2S);
  EepromU32Write(EEP_KARUNA_CTRL_ADDR, value);
  Device.Karuna.Outputs = value;

  /*** Magic Word ***/
  value = MAGIC_WORD;
  EepromU32Write(EEP_MAGICWORD_ADDR, value);
  return GUIITF_OK;
}

/* Karuna --------------------------------------------------------------------*/
uint8_t GuiItfGetKarunaStatus(void)
{
  return Device.Karuna.Status;
}

uint8_t GuiItfKarunaControl(uint8_t output)
{
  Device.Karuna.Outputs = output;
  EepromU32Write(EEP_KARUNA_CTRL_ADDR, output);
  return GUIITF_OK;
}

uint32_t GuiItfGetKarunaUptimeCnt(void)
{
  return Device.Karuna.UpTimeSec;
}

/* Backlight -----------------------------------------------------------------*/
uint8_t GuiItfSetBacklight(uint8_t percent)
{
  if(percent > 100)
    return GUIITF_OUT_OF_RANGE;
  BacklightSet(percent);
  EepromU32Write(EEP_BACKLIGHT_ADDR, percent);
  return GUIITF_OK;
}

uint8_t GuiItfGetBacklight(void)
{
    return BacklightGet();
}
