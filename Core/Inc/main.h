/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "DisplayLight.h"
#include "PowerLed.h"
#include "GuiItf.h"
#include "Periph.h"
#include "eeprom.h"
#include <time.h>

#include "cmsis_os.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */


/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/*** DEVICE ***/
#define DEVICE_OK             0
#define DEVICE_FAIL           1


#ifdef KARUNA_7i
#define DEVICE_NAME           "MGUI201222-KARUNA-7i"
#endif
#ifdef KARUNA_43i
#define DEVICE_NAME           "MGUI201222-KARUNA-4.3i"
#endif
#define DEVICE_FW             "220720_1111"
#define DEVICE_PCB            "VA01"
#define DEVICE_MNF            "KONVOLUCIO"
#define DEVICE_MNF_SIZE       sizeof(DEVICE_MNF)

#define DEVICE_NAME_SIZE      25
#define DEVICE_FW_SIZE        25
#define DEVICE_UID_SIZE       25
#define DEVICE_PCB_SIZE       5

/*** RS485 ***/
#define RS485_BUFFER_SIZE     40
#define RS485_TX_HOLD_MS      1
#define RS485_CMD_LENGTH      35
#define RS485_ARG1_LENGTH     35
#define RS485_ARG2_LENGTH     35

#define USB_BUFFER_SIZE       40

/*** YYMMDD-HHmmss ***/
#define DEVICE_DT_STR_SIZE    20

typedef struct _DiagTypeDef
{
  uint32_t UsbUartErrorCnt;
  uint32_t RS485UartErrorCnt;
  uint32_t RS485RequestCnt;
  uint32_t RS485UnknownCnt;
  uint32_t RS485ResponseCnt;
  uint32_t RS485RdyCnt;
  uint32_t PowerLedTaskCounter;
}Diag_t;

typedef struct _AppTypeDef
{
  Diag_t Diag;
  struct _Gui
  {
    char FW[DEVICE_FW_SIZE];
    char UID[DEVICE_UID_SIZE];
    char PCB[DEVICE_PCB_SIZE];
    uint32_t BootUpCnt;
    uint64_t UpTimeSec;
    float Temps[4];
    uint32_t DO;
    uint32_t DI;
    uint8_t ScreenSaverIsEnabled;
  }Gui;
  struct _Karuna
  {
    char FW[DEVICE_FW_SIZE];
    char UID[DEVICE_UID_SIZE];
    char PCB[DEVICE_PCB_SIZE];
    uint32_t OkCnt;
    uint32_t UnknownCnt;
    uint32_t DI;
    uint32_t DO;
    uint32_t UpTimeSec;
    uint32_t SavedFlags;
    uint32_t UartErrorCnt;
  }Karuna;
  struct _DasClock
  {
    char FW[DEVICE_FW_SIZE];
    char UID[DEVICE_UID_SIZE];
    char PCB[DEVICE_PCB_SIZE];
    uint32_t HeatedTemp;
    uint32_t OkCnt;
    uint32_t UnknownCnt;
    uint32_t DO;
    uint32_t DI;
    double AI[DAS_AI_CHANNELS];
    uint32_t UpTimeSec;
    uint32_t UartErrorCnt;
  }DasClock;
  struct
  {

  }Periph;

  struct _Log
  {
    uint32_t LastAddress;
  }Log;

  struct _DateTime
  {
    char Now[DEVICE_DT_STR_SIZE];
    time_t PosixTime;
    struct tm tmDateTime;
  }DateTime;

  struct _Backlight
  {
    uint32_t OffTimerSec;    //If it is not 0, then it is valid time
    uint32_t RemainingTimeToOff;
    time_t TimestampToOff;
    uint8_t LightPercent;
    uint32_t TouchInterrupt;
    uint8_t LightIsEnabled;
  } Backlight;

}Device_t;

extern Device_t Device;

extern osMutexId_t myMutex01Handle;

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/*** RTC ***/
uint8_t DeviceRtcSet(time_t dt);
uint8_t DeviceRtcGet(time_t *dt);

/*** Backlight Off Timer ***/
void DeviceBacklightOffTimerReset(void);

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define DO_EN_Pin GPIO_PIN_8
#define DO_EN_GPIO_Port GPIOI
#define RS_485_DIR_Pin GPIO_PIN_8
#define RS_485_DIR_GPIO_Port GPIOF
#define AIN_CS_Pin GPIO_PIN_0
#define AIN_CS_GPIO_Port GPIOA
#define LIVE_LED_Pin GPIO_PIN_4
#define LIVE_LED_GPIO_Port GPIOC
#define TS_RST_Pin GPIO_PIN_11
#define TS_RST_GPIO_Port GPIOH
#define TS_INT_Pin GPIO_PIN_12
#define TS_INT_GPIO_Port GPIOH
#define TS_INT_EXTI_IRQn EXTI15_10_IRQn
#define DIO_WR_Pin GPIO_PIN_12
#define DIO_WR_GPIO_Port GPIOB
#define SPI2_CLK_Pin GPIO_PIN_13
#define SPI2_CLK_GPIO_Port GPIOB
#define SPI2_MISO_Pin GPIO_PIN_14
#define SPI2_MISO_GPIO_Port GPIOB
#define SPI2_MOSI_Pin GPIO_PIN_15
#define SPI2_MOSI_GPIO_Port GPIOB
#define FLS_CS_Pin GPIO_PIN_2
#define FLS_CS_GPIO_Port GPIOG
#define DIO_CS_Pin GPIO_PIN_3
#define DIO_CS_GPIO_Port GPIOG
#define DIO_LD_Pin GPIO_PIN_6
#define DIO_LD_GPIO_Port GPIOC
#define DISP_EN_Pin GPIO_PIN_7
#define DISP_EN_GPIO_Port GPIOC
#define BTN_PWM_Pin GPIO_PIN_8
#define BTN_PWM_GPIO_Port GPIOA
#define DISP_PWM_Pin GPIO_PIN_11
#define DISP_PWM_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */
  void ConsoleWrite(char *str);
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
