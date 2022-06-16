/*//
 * GuiItf.h
 *
 *  Created on: 2022. máj. 14.
 *      Author: Margit Robert
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _GUIITF_H_
#define _GUIITF_H_

#include <time.h>

#define GUIITF_OK             0x00
#define GUIITF_FAIL           0x01
#define GUIITF_OUT_OF_RANGE   0x02

/*** Karuna ***/
//Host:0, Device:1
#define KRN_HOST_TX_ADDR        0x01  // Host->Device 0->1
#define KRN_HOST_RX_ADDR        0x10
#define KRN_DI_A0             ((uint32_t)1<<0)
#define KRN_DI_A1             ((uint32_t)1<<1)
#define KRN_DI_A2             ((uint32_t)1<<2)
#define KRN_DI_A3             ((uint32_t)1<<3)
#define KRN_DI_DSD_PCM        ((uint32_t)1<<4)
#define KRN_DI_H51            ((uint32_t)1<<5)
#define KRN_DI_H53            ((uint32_t)1<<6)
#define KRN_DI_RCA            ((uint32_t)1<<7)
#define KRN_DI_BNC            ((uint32_t)1<<8)
#define KRN_DI_XLR            ((uint32_t)1<<9)
#define KRN_DI_I2S            ((uint32_t)1<<10)
#define KRN_DI_MCLK_I2S       ((uint32_t)1<<11)

#define KRN_DO_RCA_EN         ((uint32_t)1<<0)
#define KRN_DO_BNC_EN         ((uint32_t)1<<1)
#define KRN_DO_XLR_EN         ((uint32_t)1<<2)
#define KRN_DO_I2S_EN         ((uint32_t)1<<3)
#define KRN_DO_MCLK_I2S_EN    ((uint32_t)1<<4)

/*** Saved Flags for Karuna ***/
#define KRN_FLAG_ALL_OUT_EN_AT_STARTUP    ((uint32_t)1<<0)
#define KRN_FLAG_MSTR_CLK_ON_I2S_EN       ((uint32_t)1<<1)

/*** DasClock ***/
//Host:0, Device:2
#define DAS_HOST_TX_ADDR        0x02
#define DAS_HOST_RX_ADDR        0x20
#define DAS_AI_CHANNELS         7

#define DAS_DI_LOCK1        ((uint32_t) 1<<0)
#define DAS_DI_LOCK2        ((uint32_t) 1<<1)
#define DAS_DI_EXT_IS_EN    ((uint32_t) 1<<2)
#define DAS_DI_MV1_IS_EN    ((uint32_t) 1<<3)
#define DAS_DI_MV2_IS_EN    ((uint32_t) 1<<4)

#define DAS_DO_MV1_EN       ((uint32_t) 1<<0)
#define DAS_DO_MV2_EN       ((uint32_t) 1<<1)

#define DAS_AI_MV341_I_MA     0
#define DAS_AI_MV205_1_I_MA   1
#define DAS_AI_MV205_2_I_MA   2
#define DAS_AI_U_MAIN         3
#define DAS_AI_MV341_TEMP     4
#define DAS_AI_MV205_1_TEMP   5
#define DAS_AI_MV205_2_TEMP   6

/* Exported functions prototypes ---------------------------------------------*/
/* GUI -----------------------------------------------------------------------*/
uint8_t GuiItfLoad(void);
uint8_t GuiItfSetDefault(void);
uint8_t GuiItfGetVersion(char **fw, char **uid, char **pcb);

/* Karuna --------------------------------------------------------------------*/
uint8_t GuiItfGetKarunaVersion(char **fw, char **uid, char **pcb);
uint8_t GuiItfGetKarunaStatus(void);
void GuiItfSetKarunaHdmi(uint8_t onfoff);
uint8_t GuitIfGetKarunaIsHdmiSet(void);
void GuiItfSetKarunaRca(uint8_t onfoff);
uint8_t GuitIfGetKarunaIsRcaSet(void);
void GuiItfSetKarunaBnc(uint8_t onfoff);
uint8_t GuitIfGetKarunaIsBncSet(void);
void GuiItfSetKarunaXlr(uint8_t onfoff);
uint8_t GuitIfGetKarunaIsXlrSet(void);
uint32_t GuiItfGetKarunaUptimeCnt(void);
uint8_t GuiItfGetKarunaOutputsAllEnabledAfterStart(void);
void GuiItfSetKarunaOutputsAllEnabledAfterStart(uint8_t onoff);
void GuiItfSetKarunaMasterClkOnI2S(uint8_t onoff);
uint8_t GuiItfGetKarunaMasterClkOnI2SIsEnabled(void);

/* DasClock-------------------------------------------------------------------*/
uint8_t GuiItfGetDasClockVersion(char **fw, char **uid, char **pcb);
uint32_t GuiItfGetDasClockUptimeCnt(void);
float GuiItfGetDasClockMV341Temp(void);
float GuiItfGetDasClockMVOCX1Temp(void);
float GuiItfGetDasClockMVOCX2Temp(void);
float GuiItfGetDasClockMV341Current(void);
float GuiItfGetDasClockMVOCX1Current(void);
float GuiItfGetDasClockMVOCX2Current(void);
float GuiItfGetDasClockMainVoltage(void);
uint8_t GuiItfGetDasClockStatusLock1(void);
uint8_t GuiItfGetDasClockStatusLock2(void);
uint8_t GuiItfGetDasClockIsExt(void);

/* Backlight -----------------------------------------------------------------*/
uint8_t GuiItfSetBacklight(uint8_t percent);
uint8_t GuiItfGetBacklight(void);
void GuiItfSetBacklightEn(uint8_t onoff);
void GuiItfSetBackLightAutoOff(uint32_t sec);
uint32_t GuiItfGetBaclightAutoOff(void);
/* RTC -----------------------------------------------------------------------*/
void GuiItfSetRtc(time_t dt);
void GuiItfGetRtc(time_t *dt);
/* Log -----------------------------------------------------------------------*/
uint32_t GuiItfLogGetLastAddress(void);
void GuitItfLogGetLine(uint32_t address, char *line, uint32_t size);
void GuiItfLogIncPage(void);

#endif /* _GUIITF_H_ */
