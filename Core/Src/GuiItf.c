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
#define EEP_RTC_IS_SET_ADDR      0x0010

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

    /*** Backlight ***/
    EepromU32Read(EEP_BACKLIGHT_ADDR, &value);
    BacklightSet(value);

    /*** KARUNA CTRL ***/
    EepromU32Read(EEP_KARUNA_CTRL_ADDR, &value);
    Device.Karuna.DO = value;
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
  Device.Karuna.DO = value;

  /*** RTC ***/
  value = 0x01;
  EepromU32Write(EEP_RTC_IS_SET_ADDR, value);
  RtcSet(22, 6, 10, 13, 45, 30);

  /*** Magic Word ***/
  value = MAGIC_WORD;
  EepromU32Write(EEP_MAGICWORD_ADDR, value);
  return GUIITF_OK;
}

/* GUI -----------------------------------------------------------------------*/
/*
 * fw:  220510_2157               size: DEVICE_FW_SIZE
 * uid: 66DFF323530505243052936   size: DEVICE_UID_SIZE
 * pcb: V00                       size: DEVICE_PCB_SIZE
 */
uint8_t GuiItfGetVersion(char *fw, char *uid, char *pcb)
{
  fw = DEVICE_FW;
  uid = "?";
  pcb = DEVICE_PCB;
  return GUIITF_OK;
}

uint32_t GuiItfGetBootupCnt(void)
{
  return Device.Diag.BootUpCnt;
}

uint32_t GuiItfUpTimSec(void)
{
  return Device.Diag.UpTimeSec;
}

/* Karuna --------------------------------------------------------------------*/
/*
 * fw:  220510_2157               size: DEVICE_FW_SIZE
 * uid: 66DFF323530505243052936   size: DEVICE_UID_SIZE
 * pcb: V00                       size: DEVICE_PCB_SIZE
 */
uint8_t GuiItfGetKarunaVersion(char *fw, char *uid, char *pcb)
{
  fw = Device.Karuna.FW;
  uid = Device.Karuna.UID;
  pcb = Device.Karuna.PCB;
  return GUIITF_OK;
}

uint32_t GuiItfGetKarunaUptimeCnt(void)
{
  return Device.Karuna.UpTimeSec;
}

uint8_t GuiItfGetKarunaStatus(void)
{
  return Device.Karuna.DI;
}

uint8_t GuiItfKarunaControl(uint8_t output)
{
  Device.Karuna.DO = output;
  EepromU32Write(EEP_KARUNA_CTRL_ADDR, output);
  return GUIITF_OK;
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

void GuiItfBacklightEnable(void)
{
  BacklightEnable();
}

void GuiItfBacklightDisable(void)
{
  BacklightDisable();
}

/* DasClock -----------------------------------------------------------------*/
/*
 * fw:  220510_2157               size: DEVICE_FW_SIZE
 * uid: 66DFF323530505243052936   size: DEVICE_UID_SIZE
 * pcb: V00                       size: DEVICE_PCB_SIZE
 */
uint8_t GuiItfGetDasClockVersion(char *fw, char *uid, char *pcb)
{
  fw = Device.DasClock.FW;
  uid = Device.DasClock.UID;
  pcb = Device.DasClock.PCB;
  return GUIITF_OK;
}

uint32_t GuiItfGetDasClockUptimeCnt(void)
{
  return Device.DasClock.UpTimeSec;
}

double GuiItfGetDasClockMV341Temp(void)
{
  return Device.DasClock.AI[DAS_AI_MV341_TEMP];
}

uint8_t GuiItfGetDasClockStatusLock1(void)
{
  return Device.DasClock.DI & DAS_DI_LOCK1;
}

uint8_t GuiItfGetDasClockStatusLock2(void)
{
  return Device.DasClock.DI & DAS_DI_LOCK2;
}
uint8_t GuiItfGetDasClockIsExt(void)
{
  return Device.DasClock.DI & DAS_DI_EXT_IS_EN;
}

/* RTC -----------------------------------------------------------------------*/
/*
 * year:  0..99
 * month: 1..12
 * days:  1..31
 * hours: 0..23
 * mins:  0..59
 * secs:  0..59
 */
uint8_t GuiItfSetRtc(uint8_t year, uint8_t month, uint8_t days, uint8_t hours, uint8_t mins, uint8_t secs)
{
  return RtcSet(year, month, days, hours, mins, secs);
}
uint8_t GuiItfGetRtc(uint8_t *year, uint8_t *month, uint8_t *days, uint8_t *hours, uint8_t *mins, uint8_t *secs)
{
  return  RtcGet(year, month, days, hours, mins, secs);
}
