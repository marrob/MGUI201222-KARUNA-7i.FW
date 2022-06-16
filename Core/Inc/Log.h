/*
 * GuiItf.h
 *
 *  Created on: 2022. máj. 14.
 *      Author: Margit Robert
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _LOG_H_
#define _LOG_H_

#define LOG_OK              0
#define LOG_FAIL            1
#define LOG_ARG_ERROR       2
#define LOG_OUT_OF_RNG      3
#define LOG_TIMEOUT         4

#define LOG_FLASH_PAGE_SIZE 256
#define LOG_FLASH_MAX_LINE  32000000/LOG_FLASH_PAGE_SIZE


/* Exported functions prototypes ---------------------------------------------*/


/* LogFlash ------------------------------------------------------------------*/
uint8_t LogFlashReadId (uint8_t *data, uint32_t size);
uint8_t LogFlashErase(void);
uint8_t LogFlashWrite(uint32_t addr, uint8_t *data, uint32_t size);
uint8_t LogFlashRead(uint32_t addr, uint8_t *line, uint32_t size);
uint8_t LogWriteLine(char *line);

#endif /* _LOG_H_ */
