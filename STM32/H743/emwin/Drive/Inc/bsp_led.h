#ifndef __BSP_LED_H
#define __BSP_LED_H

#include "stm32h7xx_hal.h"
#include "stdbool.h"
#include "bsp_control.h"

#define led_r		12
#define led_g		15
#define led_b		11


void Led_Init(void);
void Led_Set(u8 led, bool value);

#endif
