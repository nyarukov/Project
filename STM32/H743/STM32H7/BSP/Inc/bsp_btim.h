#ifndef __BSP_BTIM_H
#define __BSP_BTIM_H

#include "stm32h7xx_hal.h"
#include "bsp_user_lib.h"
#include "bsp_uart.h"

extern TIM_HandleTypeDef htim1;

extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;

extern TIM_HandleTypeDef htim6;
extern TIM_HandleTypeDef htim7;

void TIM1_Init(uint16_t _Arr, uint16_t _Psc, uint8_t _Count,uint32_t _Pulse);
void TIM2_Init(uint32_t _Arr, uint32_t _Psc);
void TIM3_Init(uint16_t _Arr, uint16_t _Psc);
void BaseTIM6_Init(uint16_t _Arr,uint16_t _Psc,uint8_t _Count);
void BaseTIM7_Init(uint16_t _Arr,uint16_t _Psc,uint8_t _Count);


#endif
