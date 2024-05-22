#ifndef __BSP_SYSTICK_H
#define __BSP_SYSTICK_H

#include "stm32h7xx_hal.h"
#include "bsp_user_lib.h"


void Delay_Us(uint32_t us);
void Delay_Ms(uint32_t ms);
#endif
