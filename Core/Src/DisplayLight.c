/*
 * DisplayLight.c
 *
 *  Created on: Jan 26, 2022
 *      Author: Margit Robert
 */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"
#include "DisplayLight.h"

/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
Backlight_t _backLight;

static TIM_HandleTypeDef *_htim;
/* Private function prototypes -----------------------------------------------*/
/* Private user code ---------------------------------------------------------*/

void BacklightInit(TIM_HandleTypeDef *htim)
{
  _htim = htim;
  HAL_TIM_PWM_Start(_htim,TIM_CHANNEL_4);
  BacklightSet(10);
}

uint8_t BacklightSet(uint8_t percent)
{
  _backLight.LightPercent = percent;
  percent = 100 - percent;
  uint32_t arr = __HAL_TIM_GET_AUTORELOAD(_htim);
  uint32_t ccr = (arr * percent) / 100;
  __HAL_TIM_SET_COMPARE(_htim,TIM_CHANNEL_4, ccr);

  return DISPLAY_LIGHT_OK;
}

uint8_t BacklightGet(void)
{
  return  _backLight.LightPercent;
}


void BacklightEnable(){
  HAL_GPIO_WritePin(DISP_EN_GPIO_Port, DISP_EN_Pin, GPIO_PIN_SET);
}
void BacklightDisable(){
  HAL_GPIO_WritePin(DISP_EN_GPIO_Port, DISP_EN_Pin, GPIO_PIN_RESET);
}

/************************ (C) COPYRIGHT KonvolucioBt ***********END OF FILE****/
