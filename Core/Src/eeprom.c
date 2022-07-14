/* Includes ------------------------------------------------------------------*/


#include "eeprom.h"
#include <stdio.h>
#include <stdlib.h>
#include "memory.h"
#include "string.h"

/* Private define ------------------------------------------------------------*/

I2C_HandleTypeDef *_hi2c;

/* Private function prototypes -----------------------------------------------*/
void EepromInit(I2C_HandleTypeDef *hi2c)
{
  _hi2c = hi2c;
}

HAL_StatusTypeDef EepromU32Read(uint16_t address, uint32_t *data)
{
  return HAL_I2C_Mem_Read(_hi2c,
                            EEP_DEV_ADDRESS,
                            address,
                            I2C_MEMADD_SIZE_8BIT,
                            (uint8_t*)data,
                            EEP_DEV_PAGE_SIZE,
                            EEP_DEV_TIMEOUT_MS);
}


HAL_StatusTypeDef EepromU32Write(uint8_t address, uint32_t data)
{
  HAL_StatusTypeDef status = HAL_I2C_Mem_Write( _hi2c,
                                EEP_DEV_ADDRESS,
                                address,
                                I2C_MEMADD_SIZE_8BIT,
                                (uint8_t*)&data,
                                EEP_DEV_PAGE_SIZE,
                                EEP_DEV_TIMEOUT_MS);

//  HAL_Delay(5);
  return status;
}
