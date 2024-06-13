#ifndef __BSP_LTDC_DRIVER_H
#define __BSP_LTDC_DRIVER_H

#include "stm32h7xx_hal.h"
#include "bsp_control.h"
#include "bsp_sdram.h"

#define LTCD_BIT(n)      ((n)? __GPIO_SET_BIT(GPIOB,7):__GPIO_RESET_BIT(GPIOB,7))

void LTDC_Init(void);

#endif // !__BSP_LTDC_DRIVER_H
