#ifndef __BSP_SYSTICK_H
#define __BSP_SYSTICK_H

#include "stm32f10x.h"
#include "bsp_user_lib.h"

void Delay_us(uint32_t us);
void Delay_ms(uint32_t ms);
void Delay_s(uint32_t s);
#endif
