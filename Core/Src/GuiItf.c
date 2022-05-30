/*
 * GuiItf.c
 *
 *  Created on: 2022. máj. 14.
 *      Author: Margit Robert
 */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "DisplayLight.h"
#include "GuiItf.h"

/* Private user code ---------------------------------------------------------*/
uint8_t GuiItfGetKarunaStatus(void)
{
	return Device.Karuna.Status;
}

void GuiItfKarunaControl(uint8_t output)
{
  Device.Karuna.Outputs = output;
}

uint32_t GuiItfGetKarunaUptimeCnt(void)
{
  return Device.Karuna.UpTimeSec;
}

void GuiItfSetDisplayBacklight(uint8_t percent)
{

}
