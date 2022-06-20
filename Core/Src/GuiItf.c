/*
 * GuiItf.c
 *
 *  Created on: 2022. máj. 14.
 *      Author: Margit Robert
 */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "Log.h"
#include "DisplayLight.h"
#include "GuiItf.h"
#include "EEPROM.h"

#define EEP_MAGICWORD_ADDR                  0x0000
#define EPP_BOOTUP_CNT_ADDR                 0x0004
#define EEP_BACKLIGHT_ADDR                  0x0008
#define EEP_KARUNA_SAVED_DO_ADDR            0x000C
#define EEP_RTC_IS_SET_ADDR                 0x0010
#define EEP_LOG_LAST_PAGE_ADDR              0x0014
#define EEP_KARUNA_SAVED_FLAGS_ADDR         0x0018
#define EEP_BACKLIGHT_AUTO_OFF_ADDR         0x0030

#define MAGIC_WORD                          0x55AA55AA


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
    Device.Gui.BootUpCnt = value;
    Device.Gui.BootUpCnt++;
    EepromU32Write(EPP_BOOTUP_CNT_ADDR, Device.Gui.BootUpCnt);

    /*** Backlight ***/
    EepromU32Read(EEP_BACKLIGHT_ADDR, &value);
    BacklightSet(value);

    EepromU32Read(EEP_BACKLIGHT_AUTO_OFF_ADDR, &value);
    Device.Backlight.AutoOffSec = value;

    /*** Karuna ***/
    EepromU32Read(EEP_KARUNA_SAVED_FLAGS_ADDR, &value);
    Device.Karuna.SavedFlags = value;

    if(Device.Karuna.SavedFlags & KRN_FLAG_ALL_OUT_EN_AT_STARTUP)
      Device.Karuna.DO = KRN_DO_RCA_EN | KRN_DO_BNC_EN | KRN_DO_XLR_EN | KRN_DO_I2S_EN;
    else
    {
      EepromU32Read(EEP_KARUNA_SAVED_DO_ADDR, &value);
      Device.Karuna.DO = value;
    }

    if(Device.Karuna.SavedFlags & KRN_FLAG_MSTR_CLK_ON_I2S_EN)
      Device.Karuna.DO |= KRN_DO_MCLK_I2S_EN;
    else
      Device.Karuna.DO &= ~KRN_DO_MCLK_I2S_EN;

    /*** Log ***/
    EepromU32Read(EEP_LOG_LAST_PAGE_ADDR, &value);
    Device.Log.LastAddress = value;

  }
  return GUIITF_OK;
}


uint8_t GuiItfSetDefault(void)
{
  uint32_t value = 0;

  /*** Boot Up counter ***/
  value = 0;
  EepromU32Write(EPP_BOOTUP_CNT_ADDR, value);
  Device.Gui.BootUpCnt = value;

  /*** Backlight ***/
  value = 50;
  EepromU32Write(EEP_BACKLIGHT_ADDR, value);
  BacklightSet((uint8_t)value);

  value = 0;
  EepromU32Write(EEP_BACKLIGHT_AUTO_OFF_ADDR, value);
  Device.Backlight.AutoOffSec = value;

  /*** Karuna ***/
  value = KRN_DO_RCA_EN | KRN_DO_BNC_EN | KRN_DO_XLR_EN | KRN_DO_I2S_EN;
  EepromU32Write(EEP_KARUNA_SAVED_DO_ADDR, value);
  Device.Karuna.DO = value;

  value = KRN_FLAG_ALL_OUT_EN_AT_STARTUP;
  EepromU32Write(EEP_KARUNA_SAVED_FLAGS_ADDR, value);
  Device.Karuna.SavedFlags = value;

  /*** RTC ***/
  value = 0x01;
  EepromU32Write(EEP_RTC_IS_SET_ADDR, value);

  struct tm tm_info;
  tm_info.tm_year = 2022 - 1900; // 2022
  tm_info.tm_mon = 6 - 1; //Junius
  tm_info.tm_mday = 1;
  tm_info.tm_hour = 2;
  tm_info.tm_min = 3;
  tm_info.tm_sec = 4;
  tm_info.tm_isdst = 0;
  DeviceRtcSet(mktime(&tm_info));

  /*** Log ***/
  value = 0;
  EepromU32Write(EEP_LOG_LAST_PAGE_ADDR, value);
  Device.Log.LastAddress = value;

  LogFlashErase(); //Here we have to wait for a long time....


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
uint8_t GuiItfGetVersion(char **fw, char **uid, char **pcb)
{
  *fw = Device.Gui.FW;
  *uid = Device.Gui.UID;
  *pcb = Device.Gui.PCB;
  return GUIITF_OK;
}

uint32_t GuiItfGetBootupCnt(void)
{
  return Device.Gui.BootUpCnt;
}

uint32_t GuiItfUpTimSec(void)
{
  return Device.Gui.UpTimeSec;
}

void GuiItfFacotryReset(void)
{
  GuiItfSetDefault();
  NVIC_SystemReset();
}

/* Karuna --------------------------------------------------------------------*/
/*
 * fw:  220510_2157               size: DEVICE_FW_SIZE
 * uid: 66DFF323530505243052936   size: DEVICE_UID_SIZE
 * pcb: V00                       size: DEVICE_PCB_SIZE
 */
uint8_t GuiItfGetKarunaVersion(char **fw, char **uid, char **pcb)
{
  *fw = Device.Karuna.FW;
  *uid = Device.Karuna.UID;
  *pcb = Device.Karuna.PCB;
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

void GuiItfSetKarunaHdmi(uint8_t onoff)
{
  if(onoff)
    Device.Karuna.DO |= KRN_DO_I2S_EN;
  else
    Device.Karuna.DO &= ~KRN_DO_I2S_EN;
  EepromU32Write(EEP_KARUNA_SAVED_DO_ADDR, Device.Karuna.DO);

  if(onoff)
    LogWriteLine("GuiItfSetKarunaHdmi: On");
  else
    LogWriteLine("GuiItfSetKarunaHdmi: Off");
}

uint8_t GuitIfGetKarunaIsHdmiSet(void)
{
  return (Device.Karuna.DI & KRN_DI_I2S) == KRN_DI_I2S;
}

void GuiItfSetKarunaRca(uint8_t onoff)
{
  if(onoff)
    Device.Karuna.DO |= KRN_DO_RCA_EN;
  else
    Device.Karuna.DO &= ~KRN_DO_RCA_EN;

  EepromU32Write(EEP_KARUNA_SAVED_DO_ADDR, Device.Karuna.DO);

  if(onoff)
    LogWriteLine("GuiItfSetKarunaRca: On");
  else
    LogWriteLine("GuiItfSetKarunaRca: Off");
}

uint8_t GuitIfGetKarunaIsRcaSet(void)
{
  return (Device.Karuna.DI & KRN_DI_RCA) == KRN_DI_RCA;
}

void GuiItfSetKarunaBnc(uint8_t onoff)
{
  if(onoff)
    Device.Karuna.DO |= (KRN_DO_BNC_EN);
  else
    Device.Karuna.DO &= ~KRN_DO_BNC_EN;

  EepromU32Write(EEP_KARUNA_SAVED_DO_ADDR, Device.Karuna.DO);

  if(onoff)
    LogWriteLine("GuiItfSetKarunaBnc: On");
  else
    LogWriteLine("GuiItfSetKarunaBnc: Off");
}

uint8_t GuitIfGetKarunaIsBncSet(void)
{
  return (Device.Karuna.DI & KRN_DI_BNC) == KRN_DI_BNC;
}

void GuiItfSetKarunaXlr(uint8_t onoff)
{
  if(onoff)
    Device.Karuna.DO |= KRN_DO_XLR_EN;
  else
    Device.Karuna.DO &= ~KRN_DO_XLR_EN;

  EepromU32Write(EEP_KARUNA_SAVED_DO_ADDR, Device.Karuna.DO);

  if(onoff)
    LogWriteLine("GuiItfSetKarunaXlr: On");
  else
    LogWriteLine("GuiItfSetKarunaXlr: Off");
}

uint8_t GuitIfGetKarunaIsXlrSet()
{
  return (Device.Karuna.DI & KRN_DI_XLR) == KRN_DI_XLR;
}

uint8_t GuiItfGetKarunaOutputsAllEnabledAfterStart(void)
{
  return Device.Karuna.SavedFlags & KRN_FLAG_ALL_OUT_EN_AT_STARTUP;
}

void GuiItfSetKarunaOutputsAllEnabledAfterStart(uint8_t onoff)
{
  if(onoff)
    Device.Karuna.SavedFlags |= KRN_FLAG_ALL_OUT_EN_AT_STARTUP;
  else
    Device.Karuna.SavedFlags &= ~KRN_FLAG_ALL_OUT_EN_AT_STARTUP;

  EepromU32Write(EEP_KARUNA_SAVED_FLAGS_ADDR, Device.Karuna.SavedFlags);

  if(onoff)
    LogWriteLine("GuiItfSetKarunaOutputsAllEnabledAfterStart: On");
  else
    LogWriteLine("GuiItfSetKarunaOutputsAllEnabledAfterStart: Off");
}

void GuiItfSetKarunaMasterClkOnI2S(uint8_t onoff)
{
  if(onoff)
  {
    Device.Karuna.DO |= KRN_DO_MCLK_I2S_EN;
    Device.Karuna.SavedFlags |= KRN_FLAG_MSTR_CLK_ON_I2S_EN;
  }
  else
  {
    Device.Karuna.DO &= ~KRN_DO_MCLK_I2S_EN;
    Device.Karuna.SavedFlags &= ~KRN_FLAG_MSTR_CLK_ON_I2S_EN;
  }
  EepromU32Write(EEP_KARUNA_SAVED_FLAGS_ADDR, Device.Karuna.SavedFlags);

  if(onoff)
    LogWriteLine("GuiItfSetKarunaMasterClkOnI2S: On");
  else
    LogWriteLine("GuiItfSetKarunaMasterClkOnI2S: Off");
}

uint8_t GuiItfGetKarunaMasterClkOnI2SIsEnabled(void)
{
  return Device.Karuna.SavedFlags & KRN_FLAG_MSTR_CLK_ON_I2S_EN;
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
  return Device.Backlight.LightPercent;
}

void GuiItfSetBacklightEn(uint8_t onoff)
{
  BacklightEn(onoff);
}

/*
 * 0  -> Off
 * 60 -> 1min
 */
void GuiItfSetBackLightAutoOff(uint32_t sec)
{
  Device.Backlight.AutoOffSec = sec;
  EepromU32Write(EEP_BACKLIGHT_AUTO_OFF_ADDR, sec);
  if(sec!= 0)
    DeviceBacklightOffTimerReset();
}

uint32_t GuiItfGetBacklightAutoOff(void)
{
  return Device.Backlight.AutoOffSec;
}

uint32_t GuiItfGetRemainingTimeToOff(void)
{
  return Device.Backlight.RemainingTimeToOff;
}

uint8_t GuiItfGetBacklightIsEnabled(void)
{
  return BacklightIsEnabled();
}

/* DasClock -----------------------------------------------------------------*/
/*
 * fw:  220510_2157               size: DEVICE_FW_SIZE
 * uid: 66DFF323530505243052936   size: DEVICE_UID_SIZE
 * pcb: V00                       size: DEVICE_PCB_SIZE
 */
uint8_t GuiItfGetDasClockVersion(char **fw, char **uid, char **pcb)
{
  *fw = Device.DasClock.FW;
  *uid = Device.DasClock.UID;
  *pcb = Device.DasClock.PCB;
  return GUIITF_OK;
}

uint32_t GuiItfGetDasClockUptimeCnt(void)
{
  return Device.DasClock.UpTimeSec;
}

float GuiItfGetDasClockMV341Temp(void)
{
  return Device.DasClock.AI[DAS_AI_MV341_TEMP];
}

float GuiItfGetDasClockMVOCX1Temp(void)
{
  return Device.DasClock.AI[DAS_AI_MV205_1_TEMP];
}
float GuiItfGetDasClockMVOCX2Temp(void)
{
  return Device.DasClock.AI[DAS_AI_MV205_2_TEMP];
}

float GuiItfGetDasClockMV341Current(void)
{
  return Device.DasClock.AI[DAS_AI_MV341_I_MA];
}

float GuiItfGetDasClockMVOCX1Current(void)
{
  return Device.DasClock.AI[DAS_AI_MV205_1_I_MA];
}

float GuiItfGetDasClockMVOCX2Current(void)
{
  return Device.DasClock.AI[DAS_AI_MV205_2_I_MA];
}

float GuiItfGetDasClockMainVoltage(void)
{
  return Device.DasClock.AI[DAS_AI_U_MAIN];
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
 * Example Set RTC:
 * struct tm tm_info;
 * tm_info.tm_year = 2022 - 1900; // 2022
 * tm_info.tm_mon = 6 - 1; //Juni
 * tm_info.tm_mday = 1;
 * tm_info.tm_hour = 2;
 * tm_info.tm_min = 3;
 * tm_info.tm_sec = 4;
 * tm_info.tm_isdst = 0;
 *
 * DeviceRtcSet(mktime(&tm_info));
 */
void GuiItfSetRtc(time_t dt)
{
  DeviceRtcSet(dt);
}

/*
 * Example Get RTC:
 * time_t dt;
 * GuiItfGetRtc(&dt);
 * struct tm *tm_info = gmtime(&dt);
 *
 * uint16_t year = tm_info->tm_year + 1900;
 * uint8_t mon = tm_info->tm_mon + 1;
 * uint8_t day = tm_info->tm_mday;
 *
 * uint8_t hour = tm_info->tm_hour;
 * uint8_t min = tm_info->tm_min;
 * uint8_t sec = tm_info->tm_sec;
 */
void GuiItfGetRtc(time_t *dt)
{
  *dt = Device.DateTime.PosixTime;
}

/* Log -----------------------------------------------------------------------*/
/* *** Example - Read Log ***
 * char buf[256];
 * for(uint32_t i = 0; i < GuiItfLogGetLastAddress(); i++)
 * {
 *  GuitItfLogGetLine(i, buf, sizeof(buf));
 *   printf( "%s\n", buf);
 * }
 *
 * *** Example 2 - Write to Log ***
 *
 * LogWriteLine("Hello World);
 *
 */
uint32_t GuiItfLogGetLastAddress(void)
{
  return Device.Log.LastAddress;
}

void GuitItfLogGetLine(uint32_t address, char *line, uint32_t size)
{
  LogFlashRead(address, (uint8_t*)line, size);
}

/*
 * Only for backend...
 */
void GuiItfLogIncPage(void)
{
  Device.Log.LastAddress++;
  if(Device.Log.LastAddress > LOG_FLASH_MAX_LINE)
    Device.Log.LastAddress = 0;
  EepromU32Write(EEP_LOG_LAST_PAGE_ADDR, Device.Log.LastAddress);
}


