/*//
 * GuiItf.h
 *
 *  Created on: 2022. máj. 14.
 *      Author: Margit Robert
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _GUIITF_H_
#define _GUIITF_H_


#define GUIITF_OK             0x00
#define GUIITF_FAIL           0x01
#define GUIITF_OUT_OF_RANGE   0x02

/*** KARUNA ***/
//Host:0, Device:1
#define KRN_HOST_TX_ADDR        0x01  // Host->Device 0->1
#define KRN_HOST_RX_ADDR        0x10
#define KRN_STAT_A0             (uint8_t)1<<0
#define KRN_STAT_A1             (uint8_t)1<<1
#define KRN_STAT_A2             (uint8_t)1<<2
#define KRN_STAT_A3             (uint8_t)1<<3
#define KRN_STAT_DSD_PCM        (uint8_t)1<<4
#define KRN_STAT_H51            (uint8_t)1<<5
#define KRN_STAT_H53            (uint8_t)1<<6

#define KRN_CTRL_RCA            (uint8_t)1<<0
#define KRN_CTRL_BNC            (uint8_t)1<<1
#define KRN_CTRL_XLR            (uint8_t)1<<2
#define KRN_CTRL_I2S            (uint8_t)1<<3

/*** DAS Clock ***/
//Host:0, Device:2
#define DAS_HOST_TX_ADDR        0x02
#define DAS_HOST_RX_ADDR        0x20
#define DAS_AI_CHANNELS         7

#define DAS_DI_LOCK1        (uint8_t) 1<<0
#define DAS_DI_LOCK2        (uint8_t) 1<<1
#define DAS_DI_EXT_IS_EN    (uint8_t) 1<<2
#define DAS_DI_MV1_IS_EN    (uint8_t) 1<<3
#define DAS_DI_MV2_IS_EN    (uint8_t) 1<<4

#define DAS_DO_MV1_EN       (uint8_t) 1<<0
#define DAS_DO_MV2_EN       (uint8_t) 1<<1

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
uint8_t GuiItfKarunaControl(uint8_t p_Output);
uint32_t GuiItfGetKarunaUptimeCnt(void);

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
void GuiItfBacklightEnable(void);
void GuiItfBacklightDisable(void);

/* RTC -----------------------------------------------------------------------*/
uint8_t GuiItfSetRtc(uint8_t year, uint8_t month, uint8_t day, uint8_t hours, uint8_t mins, uint8_t secs);
uint8_t GuiItfGetRtc(uint8_t *year, uint8_t *month, uint8_t *day, uint8_t *hours, uint8_t *mins, uint8_t *secs);

/* Log -----------------------------------------------------------------------*/
uint32_t GuiItfLogGetLasPageAddr(void);
void GuiItfLogIncPageAddr(void);

#endif /* _GUIITF_H_ */
