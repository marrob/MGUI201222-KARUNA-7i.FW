/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"
#include "app_touchgfx.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "string.h"
#include "mx25.h"
#include <stdio.h>
#include <queue.h>
#include <stdlib.h>
#include "GuiItf.h"
#include <time.h>
#include "Log.h"


/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

typedef enum RS485ItemType
{
  TX_ITEM_NO_ARG,
  TX_ITEM_INT_ARG
}RS485ItemType_t;

typedef struct _RS485TxItem
{
  char Command[RS485_CMD_LENGTH];
  uint8_t HostAddr;
  RS485ItemType_t Type;
  void (*Arg1);
  uint32_t PeriodTime;
  int32_t Timesamp;
}RS485TxItem_t;

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/*** SDRAM ***/
/* SDRAM refresh counter (100Mhz SD clock)    */
#define SDRAM_REFRESH_COUNT                      ((uint32_t)0x0603)
#define SDRAM_TIMEOUT                            ((uint32_t)0xFFFF)
#define SDRAM_DEVICE_ADDR                        ((uint32_t)0xD0000000)
/* SDRAM device size in MBytes */
#define SDRAM_DEVICE_SIZE                        ((uint32_t)0x800000)
#define SDRAM_MODEREG_BURST_LENGTH_1             ((uint16_t)0x0000)
#define SDRAM_MODEREG_BURST_LENGTH_2             ((uint16_t)0x0001)
#define SDRAM_MODEREG_BURST_LENGTH_4             ((uint16_t)0x0002)
#define SDRAM_MODEREG_BURST_LENGTH_8             ((uint16_t)0x0004)
#define SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL      ((uint16_t)0x0000)
#define SDRAM_MODEREG_BURST_TYPE_INTERLEAVED     ((uint16_t)0x0008)
#define SDRAM_MODEREG_CAS_LATENCY_2              ((uint16_t)0x0020)
#define SDRAM_MODEREG_CAS_LATENCY_3              ((uint16_t)0x0030)
#define SDRAM_MODEREG_OPERATING_MODE_STANDARD    ((uint16_t)0x0000)
#define SDRAM_MODEREG_WRITEBURST_MODE_PROGRAMMED ((uint16_t)0x0000)
#define SDRAM_MODEREG_WRITEBURST_MODE_SINGLE     ((uint16_t)0x0200)
#define SDRAM_BUFFER_SIZE                        ((uint32_t)0x1000)


/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

CRC_HandleTypeDef hcrc;

DMA2D_HandleTypeDef hdma2d;

I2C_HandleTypeDef hi2c1;
I2C_HandleTypeDef hi2c2;

LTDC_HandleTypeDef hltdc;

QSPI_HandleTypeDef hqspi;

RTC_HandleTypeDef hrtc;

TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim2;

UART_HandleTypeDef huart7;
UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;
DMA_HandleTypeDef hdma_uart7_rx;
DMA_HandleTypeDef hdma_usart1_rx;

SDRAM_HandleTypeDef hsdram1;

/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .stack_size = 8192 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for UsbRx_Task */
osThreadId_t UsbRx_TaskHandle;
const osThreadAttr_t UsbRx_Task_attributes = {
  .name = "UsbRx_Task",
  .stack_size = 8192 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for LiveLed_Task */
osThreadId_t LiveLed_TaskHandle;
const osThreadAttr_t LiveLed_Task_attributes = {
  .name = "LiveLed_Task",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for RS485Rx_Task */
osThreadId_t RS485Rx_TaskHandle;
const osThreadAttr_t RS485Rx_Task_attributes = {
  .name = "RS485Rx_Task",
  .stack_size = 8192 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for RS485Tx_Task */
osThreadId_t RS485Tx_TaskHandle;
const osThreadAttr_t RS485Tx_Task_attributes = {
  .name = "RS485Tx_Task",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for Peri_Task */
osThreadId_t Peri_TaskHandle;
const osThreadAttr_t Peri_Task_attributes = {
  .name = "Peri_Task",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for USBUartRxQueue */
osMessageQueueId_t USBUartRxQueueHandle;
const osMessageQueueAttr_t USBUartRxQueue_attributes = {
  .name = "USBUartRxQueue"
};
/* USER CODE BEGIN PV */
#define husb      huart1
#define hRs485    huart7

Device_t Device;
__IO unsigned long RTOSRunTimeStatTick;

static char USB_UART_RxBuffer[USB_BUFFER_SIZE];
static char RS485_UART_RxBuffer[RS485_BUFFER_SIZE];


RS485TxItem_t RS485TxCollection[] =
{
  /*** Karuna ***/
  {"#%02X UPTIME?", KRN_HOST_TX_ADDR, TX_ITEM_NO_ARG, NULL, 200,},
  {"#%02X DI?",     KRN_HOST_TX_ADDR, TX_ITEM_NO_ARG, NULL, 100 },
  {"#%02X DO %08X", KRN_HOST_TX_ADDR, TX_ITEM_INT_ARG, &Device.Karuna.DO, 100 },
  {"#%02X FW?",     KRN_HOST_TX_ADDR, TX_ITEM_NO_ARG, NULL, 4000 },
  {"#%02X UID?",    KRN_HOST_TX_ADDR, TX_ITEM_NO_ARG, NULL, 4200 },
  {"#%02X PCB?",    KRN_HOST_TX_ADDR, TX_ITEM_NO_ARG, NULL, 4600 },
  {"#%02X UE?",     KRN_HOST_TX_ADDR, TX_ITEM_NO_ARG, NULL, 4800 },


  /*** DasClock ***/
  {"#%02X UPTIME?", DAS_HOST_TX_ADDR, TX_ITEM_NO_ARG, NULL, 200,},
  {"#%02X FW?",     DAS_HOST_TX_ADDR, TX_ITEM_NO_ARG, NULL, 5000 },
  {"#%02X UID?",    DAS_HOST_TX_ADDR, TX_ITEM_NO_ARG, NULL, 5200 },
  {"#%02X PCB?",    DAS_HOST_TX_ADDR, TX_ITEM_NO_ARG, NULL, 5400 },
  {"#%02X UE?",     DAS_HOST_TX_ADDR, TX_ITEM_NO_ARG, NULL, 5400 },

  {"#%02X DI?",     DAS_HOST_TX_ADDR, TX_ITEM_NO_ARG, NULL, 200 },
  {"#%02X AI? 0",   DAS_HOST_TX_ADDR, TX_ITEM_NO_ARG, NULL ,2100 },
  {"#%02X AI? 1",   DAS_HOST_TX_ADDR, TX_ITEM_NO_ARG, NULL ,2200 },
  {"#%02X AI? 2",   DAS_HOST_TX_ADDR, TX_ITEM_NO_ARG, NULL ,2300 },
  {"#%02X AI? 3",   DAS_HOST_TX_ADDR, TX_ITEM_NO_ARG, NULL ,2400 },
  {"#%02X AI? 4",   DAS_HOST_TX_ADDR, TX_ITEM_NO_ARG, NULL ,2500 },
  {"#%02X AI? 5",   DAS_HOST_TX_ADDR, TX_ITEM_NO_ARG, NULL ,2600 },
  {"#%02X AI? 6",   DAS_HOST_TX_ADDR, TX_ITEM_NO_ARG, NULL ,2700 },
};


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA2D_Init(void);
static void MX_FMC_Init(void);
static void MX_DMA_Init(void);
static void MX_LTDC_Init(void);
static void MX_CRC_Init(void);
static void MX_I2C2_Init(void);
static void MX_QUADSPI_Init(void);
static void MX_TIM1_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_UART7_Init(void);
static void MX_TIM2_Init(void);
static void MX_I2C1_Init(void);
static void MX_RTC_Init(void);
void StartDefaultTask(void *argument);
void UsbRxTask(void *argument);
void LiveLedOsTask(void *argument);
void RS485RxTask(void *argument);
void RS485TxTask(void *argument);
void PeriTask(void *argument);

/* USER CODE BEGIN PFP */
/*** Live LED***/
void LiveLedOff(void);
void LiveLedOn(void);

/*** LCD ***/
void ConsoleWrite(char *str);
void UsbParser(char *request);
void UsbUartTx(char *str);

/*** RS485 ***/
void RS485DirTx(void);
void RS485DirRx(void);
void RS485Parser(char *response);
void RS485UartTx(char *str);

uint8_t DeviceTimeUpdate(void);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* Enable I-Cache---------------------------------------------------------*/
  SCB_EnableICache();

  /* Enable D-Cache---------------------------------------------------------*/
  SCB_EnableDCache();

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA2D_Init();
  MX_FMC_Init();
  MX_DMA_Init();
  MX_LTDC_Init();
  MX_CRC_Init();
  MX_I2C2_Init();
  MX_QUADSPI_Init();
  MX_TIM1_Init();
  MX_USART2_UART_Init();
  MX_USART1_UART_Init();
  MX_UART7_Init();
  MX_TIM2_Init();
  MX_I2C1_Init();
  MX_RTC_Init();
  MX_TouchGFX_Init();
  /* Call PreOsInit function */
  MX_TouchGFX_PreOSInit();
  /* USER CODE BEGIN 2 */

  /*** Display ***/
  BacklightEn(0);

  /*** Flash ***/
  MX25_Init(&hqspi);
  MX25_EnableMemoryMappedMode(&hqspi);
  HAL_NVIC_DisableIRQ(QUADSPI_IRQn);

  /*** Leds ***/
  BacklightInit(&htim1);
  BacklightSet(100);

  PowerLedInit(&htim1);
  PowerSetLedLight(10);
  PowerLedSetState(PWR_LED_ON);

  /*** EEPROM ***/
  EepromInit(&hi2c1);
  GuiItfLoad();

  /*** Versions ***/
  sprintf(Device.Gui.FW, "%s",DEVICE_FW);
  sprintf(Device.Gui.UID, "%4lX%4lX%4lX",HAL_GetUIDw0(), HAL_GetUIDw1(), HAL_GetUIDw2());
  sprintf(Device.Gui.PCB, "%s",DEVICE_PCB);

  /*** Date ***/
  DeviceTimeUpdate();

  /*** Falsh Playgorund ***/
#ifdef OFF_LOG_UPLOAD
  char buf[256];
  for(uint32_t i = 0; i < GuiItfLogGetLastAddress(); i++)
  {
    GuitItfLogGetLine(i,buf, sizeof(buf));
    printf( "%s\n", buf);
  }
#endif

  /*** Time Zone ***/
  setenv("TZ", "UTC", 0);
  tzset();

  /* USER CODE END 2 */

  /* Init scheduler */
  osKernelInitialize();

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the queue(s) */
  /* creation of USBUartRxQueue */
  USBUartRxQueueHandle = osMessageQueueNew (16, 80, &USBUartRxQueue_attributes);

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* creation of UsbRx_Task */
  UsbRx_TaskHandle = osThreadNew(UsbRxTask, NULL, &UsbRx_Task_attributes);

  /* creation of LiveLed_Task */
  LiveLed_TaskHandle = osThreadNew(LiveLedOsTask, NULL, &LiveLed_Task_attributes);

  /* creation of RS485Rx_Task */
  RS485Rx_TaskHandle = osThreadNew(RS485RxTask, NULL, &RS485Rx_Task_attributes);

  /* creation of RS485Tx_Task */
  RS485Tx_TaskHandle = osThreadNew(RS485TxTask, NULL, &RS485Tx_Task_attributes);

  /* creation of Peri_Task */
  Peri_TaskHandle = osThreadNew(PeriTask, NULL, &Peri_Task_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

  /* Start scheduler */
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure LSE Drive Capability
  */
  HAL_PWR_EnableBkUpAccess();
  __HAL_RCC_LSEDRIVE_CONFIG(RCC_LSEDRIVE_LOW);

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE|RCC_OSCILLATORTYPE_LSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 432;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Activate the Over-Drive mode
  */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief CRC Initialization Function
  * @param None
  * @retval None
  */
static void MX_CRC_Init(void)
{

  /* USER CODE BEGIN CRC_Init 0 */

  /* USER CODE END CRC_Init 0 */

  /* USER CODE BEGIN CRC_Init 1 */

  /* USER CODE END CRC_Init 1 */
  hcrc.Instance = CRC;
  hcrc.Init.DefaultPolynomialUse = DEFAULT_POLYNOMIAL_ENABLE;
  hcrc.Init.DefaultInitValueUse = DEFAULT_INIT_VALUE_ENABLE;
  hcrc.Init.InputDataInversionMode = CRC_INPUTDATA_INVERSION_NONE;
  hcrc.Init.OutputDataInversionMode = CRC_OUTPUTDATA_INVERSION_DISABLE;
  hcrc.InputDataFormat = CRC_INPUTDATA_FORMAT_BYTES;
  if (HAL_CRC_Init(&hcrc) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CRC_Init 2 */

  /* USER CODE END CRC_Init 2 */

}

/**
  * @brief DMA2D Initialization Function
  * @param None
  * @retval None
  */
static void MX_DMA2D_Init(void)
{

  /* USER CODE BEGIN DMA2D_Init 0 */

  /* USER CODE END DMA2D_Init 0 */

  /* USER CODE BEGIN DMA2D_Init 1 */

  /* USER CODE END DMA2D_Init 1 */
  hdma2d.Instance = DMA2D;
  hdma2d.Init.Mode = DMA2D_M2M;
  hdma2d.Init.ColorMode = DMA2D_OUTPUT_RGB565;
  hdma2d.Init.OutputOffset = 0;
  hdma2d.LayerCfg[1].InputOffset = 0;
  hdma2d.LayerCfg[1].InputColorMode = DMA2D_INPUT_RGB565;
  hdma2d.LayerCfg[1].AlphaMode = DMA2D_NO_MODIF_ALPHA;
  hdma2d.LayerCfg[1].InputAlpha = 0;
  if (HAL_DMA2D_Init(&hdma2d) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_DMA2D_ConfigLayer(&hdma2d, 1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN DMA2D_Init 2 */

  /* USER CODE END DMA2D_Init 2 */

}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.Timing = 0x20404768;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief I2C2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C2_Init(void)
{

  /* USER CODE BEGIN I2C2_Init 0 */

  /* USER CODE END I2C2_Init 0 */

  /* USER CODE BEGIN I2C2_Init 1 */

  /* USER CODE END I2C2_Init 1 */
  hi2c2.Instance = I2C2;
  hi2c2.Init.Timing = 0x20404768;
  hi2c2.Init.OwnAddress1 = 0;
  hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c2.Init.OwnAddress2 = 0;
  hi2c2.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c2.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c2) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c2, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c2, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C2_Init 2 */

  /* USER CODE END I2C2_Init 2 */

}

/**
  * @brief LTDC Initialization Function
  * @param None
  * @retval None
  */
static void MX_LTDC_Init(void)
{

  /* USER CODE BEGIN LTDC_Init 0 */

  /* USER CODE END LTDC_Init 0 */

  LTDC_LayerCfgTypeDef pLayerCfg = {0};

  /* USER CODE BEGIN LTDC_Init 1 */
#ifdef KARUNA_7i
  /* USER CODE END LTDC_Init 1 */
  hltdc.Instance = LTDC;
  hltdc.Init.HSPolarity = LTDC_HSPOLARITY_AL;
  hltdc.Init.VSPolarity = LTDC_VSPOLARITY_AL;
  hltdc.Init.DEPolarity = LTDC_DEPOLARITY_AL;
  hltdc.Init.PCPolarity = LTDC_PCPOLARITY_IPC;
  hltdc.Init.HorizontalSync = 19;
  hltdc.Init.VerticalSync = 2;
  hltdc.Init.AccumulatedHBP = 159;
  hltdc.Init.AccumulatedVBP = 22;
  hltdc.Init.AccumulatedActiveW = 1183;
  hltdc.Init.AccumulatedActiveH = 622;
  hltdc.Init.TotalWidth = 1343;
  hltdc.Init.TotalHeigh = 634;
  hltdc.Init.Backcolor.Blue = 0;
  hltdc.Init.Backcolor.Green = 0;
  hltdc.Init.Backcolor.Red = 0;
  if (HAL_LTDC_Init(&hltdc) != HAL_OK)
  {
    Error_Handler();
  }
  pLayerCfg.WindowX0 = 0;
  pLayerCfg.WindowX1 = 1024;
  pLayerCfg.WindowY0 = 0;
  pLayerCfg.WindowY1 = 600;
  pLayerCfg.PixelFormat = LTDC_PIXEL_FORMAT_RGB565;
  pLayerCfg.Alpha = 0xFF;
  pLayerCfg.Alpha0 = 0;
  pLayerCfg.BlendingFactor1 = LTDC_BLENDING_FACTOR1_CA;
  pLayerCfg.BlendingFactor2 = LTDC_BLENDING_FACTOR2_CA;
  pLayerCfg.FBStartAdress = 0xD0000000;
  pLayerCfg.ImageWidth = 1024;
  pLayerCfg.ImageHeight = 600;
  pLayerCfg.Backcolor.Blue = 0;
  pLayerCfg.Backcolor.Green = 0;
  pLayerCfg.Backcolor.Red = 0;
  if (HAL_LTDC_ConfigLayer(&hltdc, &pLayerCfg, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN LTDC_Init 2 */
#endif

#ifdef KARUNA_43i
  hltdc.Instance = LTDC;
  hltdc.Init.HSPolarity = LTDC_HSPOLARITY_AL;
  hltdc.Init.VSPolarity = LTDC_VSPOLARITY_AL;
  hltdc.Init.DEPolarity = LTDC_DEPOLARITY_AL;
  hltdc.Init.PCPolarity = LTDC_PCPOLARITY_IPC;
  hltdc.Init.HorizontalSync = 19;
  hltdc.Init.VerticalSync = 2;
  hltdc.Init.AccumulatedHBP = 159;
  hltdc.Init.AccumulatedVBP = 22;
  hltdc.Init.AccumulatedActiveW = 959;
  hltdc.Init.AccumulatedActiveH = 502;
  hltdc.Init.TotalWidth = 1119;
  hltdc.Init.TotalHeigh = 514;
  hltdc.Init.Backcolor.Blue = 0;
  hltdc.Init.Backcolor.Green = 0;
  hltdc.Init.Backcolor.Red = 0;
  if (HAL_LTDC_Init(&hltdc) != HAL_OK)
  {
    Error_Handler();
  }
  pLayerCfg.WindowX0 = 0;
  pLayerCfg.WindowX1 = 800;
  pLayerCfg.WindowY0 = 0;
  pLayerCfg.WindowY1 = 480;
  pLayerCfg.PixelFormat = LTDC_PIXEL_FORMAT_RGB565;
  pLayerCfg.Alpha = 0xFF;
  pLayerCfg.Alpha0 = 0;
  pLayerCfg.BlendingFactor1 = LTDC_BLENDING_FACTOR1_CA;
  pLayerCfg.BlendingFactor2 = LTDC_BLENDING_FACTOR2_CA;
  pLayerCfg.FBStartAdress = 0xD0000000;
  pLayerCfg.ImageWidth = 800;
  pLayerCfg.ImageHeight = 480;
  pLayerCfg.Backcolor.Blue = 0;
  pLayerCfg.Backcolor.Green = 0;
  pLayerCfg.Backcolor.Red = 0;
  if (HAL_LTDC_ConfigLayer(&hltdc, &pLayerCfg, 0) != HAL_OK)
  {
    Error_Handler();
  }
#endif

  /* USER CODE END LTDC_Init 2 */

}

/**
  * @brief QUADSPI Initialization Function
  * @param None
  * @retval None
  */
static void MX_QUADSPI_Init(void)
{

  /* USER CODE BEGIN QUADSPI_Init 0 */

  /* USER CODE END QUADSPI_Init 0 */

  /* USER CODE BEGIN QUADSPI_Init 1 */

  /* USER CODE END QUADSPI_Init 1 */
  /* QUADSPI parameter configuration*/
  hqspi.Instance = QUADSPI;
  hqspi.Init.ClockPrescaler = 5;
  hqspi.Init.FifoThreshold = 4;
  hqspi.Init.SampleShifting = QSPI_SAMPLE_SHIFTING_NONE;
  hqspi.Init.FlashSize = 25;
  hqspi.Init.ChipSelectHighTime = QSPI_CS_HIGH_TIME_6_CYCLE;
  hqspi.Init.ClockMode = QSPI_CLOCK_MODE_0;
  hqspi.Init.FlashID = QSPI_FLASH_ID_1;
  hqspi.Init.DualFlash = QSPI_DUALFLASH_DISABLE;
  if (HAL_QSPI_Init(&hqspi) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN QUADSPI_Init 2 */

  /* USER CODE END QUADSPI_Init 2 */

}

/**
  * @brief RTC Initialization Function
  * @param None
  * @retval None
  */
static void MX_RTC_Init(void)
{

  /* USER CODE BEGIN RTC_Init 0 */

  /* USER CODE END RTC_Init 0 */

  /* USER CODE BEGIN RTC_Init 1 */

  /* USER CODE END RTC_Init 1 */

  /** Initialize RTC Only
  */
  hrtc.Instance = RTC;
  hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
  hrtc.Init.AsynchPrediv = 127;
  hrtc.Init.SynchPrediv = 255;
  hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
  hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
  hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
  if (HAL_RTC_Init(&hrtc) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN RTC_Init 2 */

  /* USER CODE END RTC_Init 2 */

}

/**
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};
  TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 0;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 10000;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterOutputTrigger2 = TIM_TRGO2_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 5000;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
  if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
  {
    Error_Handler();
  }
  sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
  sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
  sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
  sBreakDeadTimeConfig.DeadTime = 0;
  sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
  sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
  sBreakDeadTimeConfig.BreakFilter = 0;
  sBreakDeadTimeConfig.Break2State = TIM_BREAK2_DISABLE;
  sBreakDeadTimeConfig.Break2Polarity = TIM_BREAK2POLARITY_HIGH;
  sBreakDeadTimeConfig.Break2Filter = 0;
  sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
  if (HAL_TIMEx_ConfigBreakDeadTime(&htim1, &sBreakDeadTimeConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */
  HAL_TIM_MspPostInit(&htim1);

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 0;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 4294967295;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief UART7 Initialization Function
  * @param None
  * @retval None
  */
static void MX_UART7_Init(void)
{

  /* USER CODE BEGIN UART7_Init 0 */

  /* USER CODE END UART7_Init 0 */

  /* USER CODE BEGIN UART7_Init 1 */

  /* USER CODE END UART7_Init 1 */
  huart7.Instance = UART7;
  huart7.Init.BaudRate = 230400;
  huart7.Init.WordLength = UART_WORDLENGTH_8B;
  huart7.Init.StopBits = UART_STOPBITS_1;
  huart7.Init.Parity = UART_PARITY_NONE;
  huart7.Init.Mode = UART_MODE_TX_RX;
  huart7.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart7.Init.OverSampling = UART_OVERSAMPLING_16;
  huart7.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart7.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart7) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN UART7_Init 2 */
  HAL_UART_Receive_DMA (&hRs485, (uint8_t*)RS485_UART_RxBuffer, RS485_BUFFER_SIZE);
  /* USER CODE END UART7_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 921600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */
  HAL_UART_Receive_DMA (&husb, (uint8_t*)USB_UART_RxBuffer, RS485_BUFFER_SIZE);
  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA2_CLK_ENABLE();
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Stream3_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Stream3_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(DMA1_Stream3_IRQn);
  /* DMA2_Stream2_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA2_Stream2_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(DMA2_Stream2_IRQn);

}

/* FMC initialization function */
static void MX_FMC_Init(void)
{

  /* USER CODE BEGIN FMC_Init 0 */

  /* USER CODE END FMC_Init 0 */

  FMC_SDRAM_TimingTypeDef SdramTiming = {0};

  /* USER CODE BEGIN FMC_Init 1 */

  /* USER CODE END FMC_Init 1 */

  /** Perform the SDRAM1 memory initialization sequence
  */
  hsdram1.Instance = FMC_SDRAM_DEVICE;
  /* hsdram1.Init */
  hsdram1.Init.SDBank = FMC_SDRAM_BANK2;
  hsdram1.Init.ColumnBitsNumber = FMC_SDRAM_COLUMN_BITS_NUM_8;
  hsdram1.Init.RowBitsNumber = FMC_SDRAM_ROW_BITS_NUM_12;
  hsdram1.Init.MemoryDataWidth = FMC_SDRAM_MEM_BUS_WIDTH_16;
  hsdram1.Init.InternalBankNumber = FMC_SDRAM_INTERN_BANKS_NUM_4;
  hsdram1.Init.CASLatency = FMC_SDRAM_CAS_LATENCY_3;
  hsdram1.Init.WriteProtection = FMC_SDRAM_WRITE_PROTECTION_DISABLE;
  hsdram1.Init.SDClockPeriod = FMC_SDRAM_CLOCK_PERIOD_2;
  hsdram1.Init.ReadBurst = FMC_SDRAM_RBURST_ENABLE;
  hsdram1.Init.ReadPipeDelay = FMC_SDRAM_RPIPE_DELAY_0;
  /* SdramTiming */
  SdramTiming.LoadToActiveDelay = 2;
  SdramTiming.ExitSelfRefreshDelay = 7;
  SdramTiming.SelfRefreshTime = 4;
  SdramTiming.RowCycleDelay = 7;
  SdramTiming.WriteRecoveryTime = 3;
  SdramTiming.RPDelay = 2;
  SdramTiming.RCDDelay = 2;

  if (HAL_SDRAM_Init(&hsdram1, &SdramTiming) != HAL_OK)
  {
    Error_Handler( );
  }

  /* USER CODE BEGIN FMC_Init 2 */
  __IO uint32_t tmpmrd = 0;
  FMC_SDRAM_CommandTypeDef Command;

  /* Step 1: Configure a clock configuration enable command */
  Command.CommandMode            = FMC_SDRAM_CMD_CLK_ENABLE;
  Command.CommandTarget          = FMC_SDRAM_CMD_TARGET_BANK2;
  Command.AutoRefreshNumber      = 1;
  Command.ModeRegisterDefinition = 0;

  /* Send the command */
  HAL_SDRAM_SendCommand(&hsdram1, &Command, SDRAM_TIMEOUT);

  /* Step 2: Insert 100 us minimum delay */
  /* Inserted delay is equal to 1 ms due to systick time base unit (ms) */
  HAL_Delay(1);

  /* Step 3: Configure a PALL (precharge all) command */
  Command.CommandMode            = FMC_SDRAM_CMD_PALL;
  Command.CommandTarget          = FMC_SDRAM_CMD_TARGET_BANK2;
  Command.AutoRefreshNumber      = 1;
  Command.ModeRegisterDefinition = 0;

  /* Send the command */
  HAL_SDRAM_SendCommand(&hsdram1, &Command, SDRAM_TIMEOUT);

  /* Step 4: Configure an Auto Refresh command */
  Command.CommandMode            = FMC_SDRAM_CMD_AUTOREFRESH_MODE;
  Command.CommandTarget          = FMC_SDRAM_CMD_TARGET_BANK2;
  Command.AutoRefreshNumber      = 8;
  Command.ModeRegisterDefinition = 0;

  /* Send the command */
  HAL_SDRAM_SendCommand(&hsdram1, &Command, SDRAM_TIMEOUT);

  /* Step 5: Program the external memory mode register */
  tmpmrd = (uint32_t)SDRAM_MODEREG_BURST_LENGTH_1          |\
                     SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL   |\
                     SDRAM_MODEREG_CAS_LATENCY_3           |\
                     SDRAM_MODEREG_OPERATING_MODE_STANDARD |\
                     SDRAM_MODEREG_WRITEBURST_MODE_SINGLE;

  Command.CommandMode            = FMC_SDRAM_CMD_LOAD_MODE;
  Command.CommandTarget          = FMC_SDRAM_CMD_TARGET_BANK2;
  Command.AutoRefreshNumber      = 1;
  Command.ModeRegisterDefinition = tmpmrd;

  /* Send the command */
  HAL_SDRAM_SendCommand(&hsdram1, &Command, SDRAM_TIMEOUT);

  /* Step 6: Set the refresh rate counter */
  /* Set the device refresh rate */
  HAL_SDRAM_ProgramRefreshRate(&hsdram1, SDRAM_REFRESH_COUNT);

  //Deactivate speculative/cache access to first FMC Bank to save FMC bandwidth
  FMC_Bank1->BTCR[0] = 0x000030D2;
  /* USER CODE END FMC_Init 2 */
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOI_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(DO_EN_GPIO_Port, DO_EN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(RS_485_DIR_GPIO_Port, RS_485_DIR_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(AIN_CS_GPIO_Port, AIN_CS_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, LIVE_LED_Pin|DIO_LD_Pin|DISP_EN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(TS_RST_GPIO_Port, TS_RST_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, DIO_WR_Pin|SPI2_CLK_Pin|SPI2_MOSI_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOG, FLS_CS_Pin|DIO_CS_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin : DO_EN_Pin */
  GPIO_InitStruct.Pin = DO_EN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(DO_EN_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : RS_485_DIR_Pin */
  GPIO_InitStruct.Pin = RS_485_DIR_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(RS_485_DIR_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : AIN_CS_Pin */
  GPIO_InitStruct.Pin = AIN_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(AIN_CS_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LIVE_LED_Pin DIO_LD_Pin */
  GPIO_InitStruct.Pin = LIVE_LED_Pin|DIO_LD_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : TS_RST_Pin */
  GPIO_InitStruct.Pin = TS_RST_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(TS_RST_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : TS_INT_Pin */
  GPIO_InitStruct.Pin = TS_INT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(TS_INT_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : DIO_WR_Pin SPI2_CLK_Pin SPI2_MOSI_Pin */
  GPIO_InitStruct.Pin = DIO_WR_Pin|SPI2_CLK_Pin|SPI2_MOSI_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : SPI2_MISO_Pin */
  GPIO_InitStruct.Pin = SPI2_MISO_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(SPI2_MISO_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : FLS_CS_Pin DIO_CS_Pin */
  GPIO_InitStruct.Pin = FLS_CS_Pin|DIO_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

  /*Configure GPIO pin : DISP_EN_Pin */
  GPIO_InitStruct.Pin = DISP_EN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(DISP_EN_GPIO_Port, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

/* USER CODE BEGIN 4 */

/* LEDs ---------------------------------------------------------------------*/
void LiveLedOn(void)
{
  HAL_GPIO_WritePin(LIVE_LED_GPIO_Port, LIVE_LED_Pin, GPIO_PIN_SET);
}

void LiveLedOff(void)
{
  HAL_GPIO_WritePin(LIVE_LED_GPIO_Port, LIVE_LED_Pin, GPIO_PIN_RESET);
}

/* Flash ---------------------------------------------------------------------*/
int Read (uint32_t address, uint32_t size, uint8_t* buffer)
{
  int i = 0;
  for (i=0; i < size;i++)
  {
    *(uint8_t*)buffer++ = *(uint8_t*)address;
    address ++;
  }
  return 1;
}

/* FreeRTOS ------------------------------------------------------------------*/
void configureTimerForRunTimeStats(void)
{
  HAL_TIM_Base_Start_IT(&htim2);
}

unsigned long getRunTimeCounterValue(void)
{
  return RTOSRunTimeStatTick;
}

/* Display--------------------------------------------------------------------*/
void SetDisplayOn()
{
  HAL_GPIO_WritePin(DISP_EN_GPIO_Port, DISP_EN_Pin, GPIO_PIN_SET);
}
void SetDisplayOff()
{
  HAL_GPIO_WritePin(DISP_EN_GPIO_Port, DISP_EN_Pin, GPIO_PIN_RESET);
}

uint8_t GetDisply(void)
{
  return HAL_GPIO_ReadPin(DISP_EN_GPIO_Port, DISP_EN_Pin) == GPIO_PIN_SET;
}

/* Usb------------------------------------------------------------------------*/
void UsbUartTx(char *str)
{
  strcat(str,"\n");
  HAL_UART_Transmit(&husb, (uint8_t*)str, strlen(str), 100);
}

void UsbParser(char *request)
{
  char response[USB_BUFFER_SIZE];
  char cmd[20];
  char arg1[10];

  if(strlen(USB_UART_RxBuffer) !=0)
  {
    memset(cmd,0x00, sizeof(cmd));
    memset(arg1,0x00, sizeof(arg1));

    sscanf(request, "%s", cmd);

    if(!strcmp(cmd, "*OPC?"))
    {
      strcpy(response, "*OPC");
    }
    else if(!strcmp(cmd, "OK?"))
    {
      strcpy(response, "OK");
    }
    else if(!strcmp(cmd, "*WHOIS?"))
    {
      strcpy(response, DEVICE_NAME);
    }
    else if(!strcmp(cmd, "*VER?"))
    {
      strcpy(response, DEVICE_FW);
    }
    else if(!strcmp(cmd, "*UID?"))
    {
      sprintf(response, "%4lX%4lX%4lX",HAL_GetUIDw0(), HAL_GetUIDw1(), HAL_GetUIDw2());
    }
    else if(!strcmp(cmd,"UPTIME?"))
    {
      sprintf(response, "%lld", Device.Gui.UpTimeSec);
    }
    else if(!strcmp(cmd, "DIS:LIG?"))
    {
      sprintf(response, "%d", Device.Backlight.LightPercent);
    }
    else if(!strcmp(cmd, "DIS?"))
    {
      sprintf(response, "%d",GetDisply()?1:0);
    }
    else if(!strcmp(cmd, "DIS:ON"))
    {
      SetDisplayOn();
      strcpy(response, "OK");
    }
    else if(!strcmp(cmd, "DIS:OFF"))
    {
      SetDisplayOff();
      strcpy(response, "OK");
    }
    else if(!strcmp(cmd, "DIG:INP:U16?"))
    {
      sprintf(response, "%04X",PeriphReadInputs());
    }
    else if(!strcmp(cmd, "DIG:OUT:U8?"))
    {
      strcpy(response, "!UNKNOWN");
    }
    else if(!strcmp(cmd, "DIG:OUT:SET:U8"))
    {
      sscanf(request, "%s %s", cmd, arg1);
      uint8_t value = strtol(arg1, NULL, 16);

      PeriphWriteOutputs(value);
      strcpy(response, "OK");
    }
    else if(!strcmp(cmd,"RST"))
    {
      strcpy(response, "OK");
      UsbUartTx(response);
      NVIC_SystemReset();
    }
    else
    {
      strcpy(response, "!UNKNOWN");
    }
    UsbUartTx(response);
  }
}

/* RTC -----------------------------------------------------------------------*/
uint8_t DeviceRtcSet(time_t dt)
{
#if rtc_test
  /*** Loopback for test ***/
  struct tm tm_out = {0};
  struct tm *tm_in = gmtime(&dt);

  tm_out.tm_year = tm_in->tm_year;
  tm_out.tm_mon = tm_in->tm_mon;
  tm_out.tm_mday = tm_in->tm_mday;

  tm_out.tm_hour = tm_in->tm_hour;
  tm_out.tm_min = tm_in->tm_min;
  tm_out.tm_sec = tm_in->tm_sec;

  Device.DateTime.PosixTime = mktime(&tm_out);
#endif

  struct tm *tm_info = gmtime(&dt);

  RTC_DateTypeDef date;
  date.Year = tm_info->tm_year - 100;
  date.Month = tm_info->tm_mon + 1;
  date.Date = tm_info->tm_mday;
  date.WeekDay = 0;
  if(HAL_RTC_SetDate(&hrtc, &date, RTC_FORMAT_BIN) != HAL_OK)
    return DEVICE_FAIL;

  RTC_TimeTypeDef time;
  time.Hours = tm_info->tm_hour;
  time.Minutes = tm_info->tm_min;
  time.Seconds = tm_info->tm_sec;
  time.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
  time.StoreOperation = RTC_STOREOPERATION_SET;

  if(HAL_RTC_SetTime(&hrtc, &time, RTC_FORMAT_BIN) != HAL_OK)
    return DEVICE_FAIL;

  return DEVICE_OK;
}

uint8_t DeviceRtcGet(time_t *dt)
{
  //Have to read time first!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  RTC_TimeTypeDef time;
  if(HAL_RTC_GetTime(&hrtc, &time, RTC_FORMAT_BIN) != HAL_OK)
    return DEVICE_FAIL;

  RTC_DateTypeDef date;
  if(HAL_RTC_GetDate(&hrtc, &date, RTC_FORMAT_BIN) != HAL_OK)
    return DEVICE_FAIL;

  struct tm tm_info;
  tm_info.tm_year = 2000 - 1900 + date.Year ;
  tm_info.tm_mon = date.Month - 1;
  tm_info.tm_mday = date.Date;
  tm_info.tm_hour = time.Hours;
  tm_info.tm_min = time.Minutes;
  tm_info.tm_sec = time.Seconds;
  if (time.DayLightSaving == RTC_DAYLIGHTSAVING_SUB1H)
    tm_info.tm_isdst = -1;
  else if (time.DayLightSaving == RTC_DAYLIGHTSAVING_ADD1H)
    tm_info.tm_isdst = 1;
  else
    tm_info.tm_isdst = 0;

  *dt = mktime(&tm_info);

  return DEVICE_OK;
}

uint8_t DeviceTimeUpdate()
{
  /*** Device Real Time Clock Update ***/
  if(DeviceRtcGet(&Device.DateTime.PosixTime) != DEVICE_OK)
    return DEVICE_FAIL;

  struct tm *tm_info  = localtime(&Device.DateTime.PosixTime);
  Device.DateTime.tmDateTime.tm_year = tm_info->tm_year;
  Device.DateTime.tmDateTime.tm_mon = tm_info->tm_mon;
  Device.DateTime.tmDateTime.tm_mday = tm_info->tm_mday;
  Device.DateTime.tmDateTime.tm_hour = tm_info->tm_hour;
  Device.DateTime.tmDateTime.tm_min = tm_info->tm_min;
  Device.DateTime.tmDateTime.tm_year = tm_info->tm_year;
  Device.DateTime.tmDateTime.tm_sec = tm_info->tm_sec;
  Device.DateTime.tmDateTime.tm_isdst = tm_info->tm_isdst;

  strftime(Device.DateTime.Now, DEVICE_DT_STR_SIZE, "%Y-%m-%d %H:%M:%S", tm_info );

  /*** Display Backlight Auto Off Timer ***/
  if(Device.Backlight.OffTimerSec != 0)
  {
    if(Device.Backlight.TimestampToOff == Device.DateTime.PosixTime)
    {
      BacklightEn(0);
      Device.Backlight.TouchInterrupt = 0;
    }
    if(Device.Backlight.TimestampToOff > Device.DateTime.PosixTime)
      Device.Backlight.RemainingTimeToOff = Device.Backlight.TimestampToOff - Device.DateTime.PosixTime;
  }
  else
  {
    Device.Backlight.RemainingTimeToOff = 0;
    Device.Backlight.TouchInterrupt = 0;
  }
  return DEVICE_OK;
}

void DeviceBacklightOffTimerReset(void)
{
  Device.Backlight.TimestampToOff = Device.Backlight.OffTimerSec + Device.DateTime.PosixTime;
  BacklightEn(1);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if(Device.Backlight.OffTimerSec)
  {
    Device.Backlight.TouchInterrupt ++;
    DeviceBacklightOffTimerReset();
  }
}

/* RS485----------------------------------------------------------------------*/
void RS485DirTx(void)
{
  HAL_GPIO_WritePin(RS_485_DIR_GPIO_Port, RS_485_DIR_Pin, GPIO_PIN_SET);
}

void RS485DirRx(void)
{
  HAL_GPIO_WritePin(RS_485_DIR_GPIO_Port, RS_485_DIR_Pin, GPIO_PIN_RESET);
}

void RS485UartTx(char *str)
{
  RS485DirTx();
  HAL_Delay(RS485_TX_HOLD_MS);
  strcat(str,"\n");
  HAL_UART_Transmit(&hRs485, (uint8_t*)str, strlen(str), 100);
  RS485DirRx();
}

void RS485Parser(char *response)
{
  unsigned int addr = 0;
  char cmd[RS485_CMD_LENGTH];
  char arg1[RS485_ARG1_LENGTH];
  char arg2[RS485_ARG2_LENGTH];

  if(strlen(response) !=0)
  {
    memset(cmd,0x00, RS485_CMD_LENGTH);
    memset(arg1,0x00, RS485_ARG1_LENGTH);
    memset(arg2,0x00, RS485_ARG2_LENGTH);

    Device.Diag.RS485ResponseCnt++;
    sscanf(response, "#%x %s %s", &addr, cmd, arg1);
    if(addr == KRN_HOST_RX_ADDR )
    {
      if(!strcmp(cmd, "OK"))
      {
        Device.Karuna.OkCnt++;
      }
      else if(!strcmp(cmd, "FW"))
      {
         uint8_t i = strlen(arg1);
         if(i<DEVICE_FW_SIZE && i!=0)
           strcpy(Device.Karuna.FW, arg1);
         else
           strcpy(Device.Karuna.FW, "?");
      }
      else if(!strcmp(cmd, "UID"))
      {
        uint8_t i = strlen(arg1);
        if(i<DEVICE_UID_SIZE && i!=0)
          strcpy(Device.Karuna.UID, arg1);
        else
          strcpy(Device.Karuna.UID, "?");
      }
      else if(!strcmp(cmd, "PCB"))
      {
        uint8_t i = strlen(arg1);
        if(i<DEVICE_PCB_SIZE && i!=0)
          strcpy(Device.Karuna.PCB, arg1);
        else
          strcpy(Device.Karuna.PCB, "?");
      }
      else if(!strcmp(cmd,"UPTIME"))
      {
        Device.Karuna.UpTimeSec = strtol(arg1, NULL, 16);
      }
      else if(!strcmp(cmd, "DI"))
      {
        Device.Karuna.DI = strtol(arg1, NULL, 16);
      }
      else if(!strcmp(cmd, "DO"))
      {
        Device.Karuna.DO = strtol(arg1, NULL, 16);
      }
      else if(!strcmp(cmd, "UE"))
      {
        Device.Karuna.UartErrorCnt = strtol(arg1, NULL, 16);
      }
      else
      {
        Device.Karuna.UnknownCnt++;
      }
    }

    if(addr == DAS_HOST_RX_ADDR)
    {
      if(!strcmp(cmd, "OK"))
      {
        Device.DasClock.OkCnt++;
      }

      if(!strcmp(cmd, "FW"))
      {
        uint8_t i = strlen(arg1);
        if(i<DEVICE_FW_SIZE && i!=0)
          strcpy(Device.DasClock.FW, arg1);
        else
          strcpy(Device.DasClock.UID, "?");
      }
      else if(!strcmp(cmd, "UID"))
      {
        uint8_t i = strlen(arg1);
        if(i<DEVICE_UID_SIZE && i!=0)
          strcpy(Device.DasClock.UID, arg1);
        else
          strcpy(Device.DasClock.UID, "?");
      }
      else if(!strcmp(cmd, "PCB"))
      {
        uint8_t i = strlen(arg1);
        if(i<DEVICE_PCB_SIZE && i!=0)
          strcpy(Device.DasClock.PCB, arg1);
        else
          strcpy(Device.DasClock.PCB, "?");
      }
      else if(!strcmp(cmd,"UPTIME"))
      {
         Device.DasClock.UpTimeSec = strtol(arg1, NULL, 16);
      }
      else if(!strcmp(cmd, "DI"))
      {
        Device.DasClock.DI = strtol(arg1, NULL, 16);
      }
      else if(!strcmp(cmd, "DO"))
      {
        Device.DasClock.DO = strtol(arg1, NULL, 16);
      }
      else if(!strcmp(cmd, "UE"))
      {
        Device.DasClock.UartErrorCnt = strtol(arg1, NULL, 16);
      }
      if(!strcmp(cmd, "AI"))
      {
        sscanf(response, "#%x %s %s %s", &addr, cmd, arg1, arg2);
        uint8_t ch = strtol(arg1, NULL, 10);
        double value = atof(arg2);
        if(ch < DAS_AI_CHANNELS)
         Device.DasClock.AI[ch] = value;
      }
      else
      {
        Device.DasClock.UnknownCnt++;
      }
    }
  }
}



/* USER CODE END 4 */

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN 5 */

  LogWriteLine("Start Default Task");

  MX_TouchGFX_Process();
  /* Infinite loop */
  for(;;)
  {
    osDelay(100);
  }
  /* USER CODE END 5 */
}

/* USER CODE BEGIN Header_UsbRxTask */
/**
* @brief Function implementing the UsbRx_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_UsbRxTask */
void UsbRxTask(void *argument)
{
  /* USER CODE BEGIN UsbRxTask */
  /* Infinite loop */
  static uint32_t timestamp;
  static uint8_t startFlag;
  for(;;)
  {
    if(strlen(USB_UART_RxBuffer)!=0)
    {
      if(!startFlag)
      {
        timestamp = HAL_GetTick();
        startFlag = 1;
      }
      for(uint8_t i=0; i < USB_BUFFER_SIZE; i++)
      {
        if(USB_UART_RxBuffer[i]=='\n')
        {
          USB_UART_RxBuffer[i] = 0;
          startFlag = 0;
          HAL_UART_DMAStop(&husb);
          UsbParser(USB_UART_RxBuffer);
          memset(USB_UART_RxBuffer, 0x00, USB_BUFFER_SIZE);
          HAL_UART_Receive_DMA(&husb, (uint8_t*) USB_UART_RxBuffer, USB_BUFFER_SIZE);
        }
      }
      if(startFlag)
      {
        if(HAL_GetTick() - timestamp > 500)
        {
          if(__HAL_UART_GET_FLAG(&husb, UART_FLAG_ORE))
            __HAL_UART_CLEAR_FLAG(&husb,UART_CLEAR_OREF);
          if(__HAL_UART_GET_FLAG(&husb, USART_ISR_NE))
            __HAL_UART_CLEAR_FLAG(&husb,USART_ISR_NE);
          if(__HAL_UART_GET_FLAG(&husb, USART_ISR_FE))
            __HAL_UART_CLEAR_FLAG(&husb,USART_ISR_FE);
          startFlag = 0;
          HAL_UART_DMAStop(&husb);
          memset(USB_UART_RxBuffer, 0x00, USB_BUFFER_SIZE);
          HAL_UART_Receive_DMA(&husb, (uint8_t*) USB_UART_RxBuffer, USB_BUFFER_SIZE);
          Device.Diag.UsbUartErrorCnt ++;
        }
      }
    }
    osDelay(10);
  }
  /* USER CODE END UsbRxTask */
}

/* USER CODE BEGIN Header_LiveLedOsTask */
/**
* @brief Function implementing the LiveLed_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_LiveLedOsTask */
void LiveLedOsTask(void *argument)
{
  /* USER CODE BEGIN LiveLedOsTask */
  /* Infinite loop */
  for(;;)
  {
    uint32_t timestamp = 0;
    uint8_t flag = 0;

    osDelay(1000);
    BacklightEn(1);
    for(;;)
    {
      if(HAL_GetTick() - timestamp > 500)
      {
        timestamp = HAL_GetTick();
        if(flag)
        {
          flag = 0;
          LiveLedOn();
          DeviceTimeUpdate();
        }
        else
        {
          flag = 1;
          LiveLedOff();
          Device.Gui.UpTimeSec++;
        }
      }
      osDelay(10);
    }
  }
  /* USER CODE END LiveLedOsTask */
}

/* USER CODE BEGIN Header_RS485RxTask */
/**
* @brief Function implementing the RS485Rx_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_RS485RxTask */
void RS485RxTask(void *argument)
{
  /* USER CODE BEGIN RS485RxTask */
  /* Infinite loop */
  static uint32_t timestamp;
  static uint8_t startFlag;
  for(;;)
  {
    if(strlen(RS485_UART_RxBuffer)!=0)
    {
      if(!startFlag)
      {
        timestamp = HAL_GetTick();
        startFlag = 1;
      }
      for(uint8_t i=0; i < RS485_BUFFER_SIZE; i++)
      {
        if(RS485_UART_RxBuffer[i]=='\n')
        {
          RS485_UART_RxBuffer[i] = 0;
          startFlag = 0;
          HAL_UART_DMAStop(&hRs485);
          RS485Parser(RS485_UART_RxBuffer);
          memset(RS485_UART_RxBuffer, 0x00, RS485_BUFFER_SIZE);
          HAL_UART_Receive_DMA(&hRs485, (uint8_t*) RS485_UART_RxBuffer, RS485_BUFFER_SIZE);
        }
      }
      if(startFlag)
      {
        if(HAL_GetTick() - timestamp > 500)
        {
          if(__HAL_UART_GET_FLAG(&hRs485, UART_FLAG_ORE))
            __HAL_UART_CLEAR_FLAG(&hRs485,UART_CLEAR_OREF);
          if(__HAL_UART_GET_FLAG(&hRs485, USART_ISR_NE))
            __HAL_UART_CLEAR_FLAG(&hRs485,USART_ISR_NE);
          if(__HAL_UART_GET_FLAG(&hRs485, USART_ISR_FE))
            __HAL_UART_CLEAR_FLAG(&hRs485,USART_ISR_FE);
          startFlag = 0;
          HAL_UART_DMAStop(&hRs485);
          memset(RS485_UART_RxBuffer, 0x00, RS485_BUFFER_SIZE);
          HAL_UART_Receive_DMA(&hRs485, (uint8_t*) RS485_UART_RxBuffer, RS485_BUFFER_SIZE);
          Device.Diag.RS485UartErrorCnt ++;
        }
      }
    }
    osDelay(10);
  }
  /* USER CODE END RS485RxTask */
}

/* USER CODE BEGIN Header_RS485TxTask */
/**
* @brief Function implementing the RS485Tx_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_RS485TxTask */
void RS485TxTask(void *argument)
{
  /* USER CODE BEGIN RS485TxTask */
  /* Infinite loop */
  static char buffer[RS485_BUFFER_SIZE];
  memset(buffer, 0xCC, RS485_BUFFER_SIZE);

  for(;;)
  {
    for(uint8_t i=0; i< sizeof(RS485TxCollection)/sizeof(RS485TxItem_t); i++)
    {
      if(HAL_GetTick() - RS485TxCollection[i].Timesamp > RS485TxCollection[i].PeriodTime )
      {
        RS485TxCollection[i].Timesamp = HAL_GetTick();
        switch(RS485TxCollection[i].Type)
        {
          case TX_ITEM_NO_ARG:
          {
            sprintf(buffer, RS485TxCollection[i].Command, RS485TxCollection[i].HostAddr);
            break;
          }
          case TX_ITEM_INT_ARG:
          {
            sprintf(buffer, RS485TxCollection[i].Command, RS485TxCollection[i].HostAddr, *((uint32_t*)RS485TxCollection[i].Arg1));
            break;
          }
        }
        RS485UartTx(buffer);
      }
      osDelay(10);
    }
  }
  /* USER CODE END RS485TxTask */
}

/* USER CODE BEGIN Header_PeriTask */
/**
* @brief Function implementing the Peri_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_PeriTask */
void PeriTask(void *argument)
{
  /* USER CODE BEGIN PeriTask */
  /* Infinite loop */
  for(;;)
  {
    Device.Gui.DI = PeriphReadInputs();
    PeriphWriteOutputs(Device.Gui.DO);

    Device.Gui.Temps[AI_CH0] = PeriphReadTemp(AI_CH0);
    Device.Gui.Temps[AI_CH1] = PeriphReadTemp(AI_CH1);
    Device.Gui.Temps[AI_CH2] = PeriphReadTemp(AI_CH2);
    Device.Gui.Temps[AI_CH3] = PeriphReadTemp(AI_CH3);
    osDelay(100);
  }
  /* USER CODE END PeriTask */
}

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM6 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM6) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
