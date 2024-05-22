#ifndef __BSP_BTIM_H
#define __BSP_BTIM_H

#include "stm32h7xx_hal.h"
#include "bsp_control.h"


extern TIM_HandleTypeDef tim6_struct;

void BaseTIM6_Init(uint16_t arr,uint16_t psc,uint8_t count);

#endif
