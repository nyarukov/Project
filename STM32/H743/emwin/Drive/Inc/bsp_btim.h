#ifndef __BSP_BTIM_H
#define __BSP_BTIM_H

#include "stm32h7xx_hal.h"
#include "bsp_control.h"
#include "GUI.h"


extern TIM_HandleTypeDef tim6_struct;
extern TIM_HandleTypeDef tim7_struct;

void BaseTIM6_Init(u16 arr,u16 psc,u8 count);
void BaseTIM7_Init(u16 arr,u16 psc,u8 count);

#endif
