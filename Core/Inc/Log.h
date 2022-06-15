/*
 * GuiItf.h
 *
 *  Created on: 2022. máj. 14.
 *      Author: Margit Robert
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _LOG_H_
#define _LOG_H_

#define LOG_OK            0
#define LOG_FAIL          1
#define LOG_ARG_ERROR     2
#define LOG_OUT_OF_RNG    3
#define LOG_TIMEOUT       4

/* Exported functions prototypes ---------------------------------------------*/


/* LogFlash ------------------------------------------------------------------*/
uint8_t LogFlashReadId (uint8_t *data, uint32_t size);
uint8_t LogErase(void);
uint8_t LogWriteLine(uint32_t addr, uint8_t *data, uint32_t size);
uint8_t LogReadLine(uint32_t line, uint8_t *data, uint32_t size);

#endif /* _LOG_H_ */
