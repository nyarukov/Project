#ifndef __BSP_BTIM_H
#define __BSP_BTIM_H

#include "stm32h7xx_hal.h"
#include "bsp_user_lib.h"
#include "bsp_uart.h"

extern TIM_HandleTypeDef tim6_struct;
extern TIM_HandleTypeDef tim7_struct;
extern TIM_HandleTypeDef htim3;

void BaseTIM6_Init(uint16_t arr,uint16_t psc,uint8_t count);
void BaseTIM7_Init(uint16_t arr,uint16_t psc,uint8_t count);
void TIM3_Init(uint16_t arr, uint16_t psc);

#endif
