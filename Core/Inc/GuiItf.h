/*
 * GuiItf.h
 *
 *  Created on: 2022. máj. 14.
 *      Author: Margit Robert
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _GUIITF_H_
#define _GUIITF_H_


/*** KARUNA ***/
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


/* Exported functions prototypes ---------------------------------------------*/
uint8_t GuiItfGetKarunaStatus(void);
void GuiItfKarunaControl(uint8_t p_Output);
uint32_t GuiItfGetKarunaUptimeCnt(void);



#endif /* _GUIITF_H_ */
