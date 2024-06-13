#ifndef __BSP_RCC_H
#define __BSP_RCC_H

#include "stm32h7xx_hal.h"
#include "bsp_uart.h"
#include "main.h"

void SystemClock_Config(void);
void MX_GPIO_Init(void);

#endif
