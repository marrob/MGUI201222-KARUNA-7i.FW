/*
 * Periph.h
 *
 *  Created on: 2022. máj. 14.
 *      Author: Margit Robert
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _ANALOG_INPUTS_H_
#define _ANALOG_INPUTS_H_

#define AI_CH0    0
#define AI_CH1    1
#define AI_CH2    2
#define AI_CH3    3

#define DO_0      ((uint8_t) 1<<0)
#define DO_1      ((uint8_t) 1<<1)
#define DO_2      ((uint8_t) 1<<2)
#define DO_3      ((uint8_t) 1<<3)
#define DO_4      ((uint8_t) 1<<4)
#define DO_5      ((uint8_t) 1<<5)
#define DO_6      ((uint8_t) 1<<6)
#define DO_7      ((uint8_t) 1<<7)

#define DI_0      ((uint8_t) 1<<0)
#define DI_1      ((uint8_t) 1<<1)
#define DI_2      ((uint8_t) 1<<2)
#define DI_3      ((uint8_t) 1<<3)
#define DI_4      ((uint8_t) 1<<4)
#define DI_5      ((uint8_t) 1<<5)
#define DI_6      ((uint8_t) 1<<6)
#define DI_7      ((uint8_t) 1<<7)
#define DI_8      ((uint8_t) 1<<8)
#define DI_9      ((uint8_t) 1<<9)
#define DI_10     ((uint8_t) 1<<10)
#define DI_11     ((uint8_t) 1<<11)
#define DI_12     ((uint8_t) 1<<12)
#define DI_13     ((uint8_t) 1<<13)
#define DI_14     ((uint8_t) 1<<14)
#define DI_15     ((uint8_t) 1<<15)

/* Exported functions prototypes ---------------------------------------------*/
float PeriphReadTemp(uint8_t channel);
uint16_t PeriphReadInputs(void);
void PeriphWriteOutputs(uint8_t data);

#endif /* _ANALOG_INPUTS_H_ */
