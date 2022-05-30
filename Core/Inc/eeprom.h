/*
 * memory.h
 *
 *  Created on: 2020. márc. 6.
 *      Author: Margit Robert
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef INC_EEPROM_H_
#define INC_EEPROM_H_
/* Includes ------------------------------------------------------------------*/
#include "stm32f7xx_hal.h"

/* Exported constants --------------------------------------------------------*/

#define EEP_FIRST_CONTENT         "I'M ALIVE"
#define EEP_TEST_CONTENT          "This is a Test"
#define EEP_DEV_ADDRESS           0x50
#define EEP_DEV_PAGE_SIZE         64
#define EEP_DEV_TIMEOUT_MS        100

/* Exported macro ------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/


/* Exported functions ------------------------------------------------------- */
void EepromInit(I2C_HandleTypeDef *hi2c);
HAL_StatusTypeDef EepromWrite(uint16_t address, void *data, size_t size);
HAL_StatusTypeDef EepromRead(uint16_t memAddr, void *pData, size_t size);

#endif /* INC_EEPROM_H_ */

/************************ (C) COPYRIGHT KonvolucioBt ***********END OF FILE****/
