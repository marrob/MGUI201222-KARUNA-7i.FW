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
#define EEP_DEV_ADDRESS           0xA0
#define EEP_DEV_PAGE_SIZE         4
#define EEP_DEV_TIMEOUT_MS        100

/* Exported macro ------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/


/* Exported functions ------------------------------------------------------- */
void EepromInit(I2C_HandleTypeDef *hi2c);
HAL_StatusTypeDef EepromU32Read(uint16_t address, uint32_t *data);
HAL_StatusTypeDef EepromU32Write(uint8_t address, uint32_t data);

#endif /* INC_EEPROM_H_ */

/************************ (C) COPYRIGHT KonvolucioBt ***********END OF FILE****/
