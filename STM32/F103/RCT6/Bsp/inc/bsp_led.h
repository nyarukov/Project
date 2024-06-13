#ifndef __BSP_LED_H
#define __BSP_LED_H

#include "stm32f10x.h"
#include "stdbool.h"
#include "bsp_user_lib.h"
#include "bsp_systick.h"

void Beep_Init(void);

void Beep_Simple(uint32_t ms);
void Beep_Variable(uint32_t ms, uint8_t count);
#endif
