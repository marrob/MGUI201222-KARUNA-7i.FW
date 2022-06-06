/*
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
#define KRN_ADDR                0x01
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
#define DAS_ADDR                0x02


/* Exported functions prototypes ---------------------------------------------*/
uint8_t GuiItfLoad(void);
uint8_t GuiItfSetDefault(void);

/* Karuna --------------------------------------------------------------------*/
uint8_t GuiItfGetKarunaVersion(char *ver, char *uid);
uint8_t GuiItfKarunaControl(uint8_t p_Output);
uint32_t GuiItfGetKarunaUptimeCnt(void);

/* DasClock-------------------------------------------------------------------*/
uint32_t GuiItfGetDasUptimeCnt(void);
uint8_t GuiItfGetDasVersion(char *ver, char *uid);

/* Backlight -----------------------------------------------------------------*/
uint8_t GuiItfSetBacklight(uint8_t percent);
uint8_t GuiItfGetBacklight(void);





#endif /* _GUIITF_H_ */
