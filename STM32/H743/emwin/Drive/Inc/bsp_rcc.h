#ifndef __BSP_RCC_H
#define __BSP_RCC_H

#include "stm32h7xx_hal.h"
#include "bsp_uart.h"

void SystemClock_Config(void);
void Error_Handler(void);
void MX_GPIO_Init(void);
void PLL_CLK_Ptintf(void);

#endif
