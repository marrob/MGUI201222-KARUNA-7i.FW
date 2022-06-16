/*
 * DisplayLight.h
 *
 *  Created on: Jan 26, 2022
 *      Author: Margit Robert
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef APPLICATION_USER_CORE_INC_DISPLAYLIGHT_H_
#define APPLICATION_USER_CORE_INC_DISPLAYLIGHT_H_
/* Includes ------------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/
#define DISPLAY_LIGHT_OK  0
/* Exported functions ------------------------------------------------------- */

void BacklightInit(TIM_HandleTypeDef *htim);
uint8_t BacklightSet(uint8_t percent);
void BacklightEn(uint8_t onoff);

#endif /* APPLICATION_USER_CORE_INC_DISPLAYLIGHT_H_ */

/************************ (C) COPYRIGHT KonvolucioBt ***********END OF FILE****/
