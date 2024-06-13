#ifndef __BSP_BTIM_H
#define __BSP_BTIM_H

#include "stm32h7xx_hal.h"
#include "bsp_control.h"
#include "bsp_uart.h"

extern TIM_HandleTypeDef tim6_struct;
extern TIM_HandleTypeDef tim7_struct;

void BaseTIM6_Init(uint16_t arr,uint16_t psc,uint8_t count);
void BaseTIM7_Init(uint16_t arr,uint16_t psc,uint8_t count);

#endif
