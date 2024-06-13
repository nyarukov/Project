#ifndef __BSP_LED_H
#define __BSP_LED_H

#include "stm32h7xx_hal.h"
#include "stdbool.h"
#include "bsp_control.h"

#define led_r		11
#define led_g		12
#define led_b		15


void Led_Init(void);
void Led_Set(uint8_t led, bool value);

#endif
