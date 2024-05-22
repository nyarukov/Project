#ifndef __BSP_H
#define __BSP_H

#include "stm32h7xx_hal.h"

#include "bsp_control.h"

#include "bsp_rcc.h"

#include "bsp_mpu.h"

#include "bsp_led.h"

#include "bsp_uart.h"

//#include "bsp_key.h"

#include "bsp_ltdc_draw.h"

#include "bsp_softiic.h"

//#include "bsp_softspi.h"

#include "bsp_btim.h"

#include "GUI.h"

#include "MainTask.h"

#include "bsp_ft5426.h"

#include "bsp_mpu6050.h"

extern const uint16_t _acmickey[] ;
extern const uint16_t _ac1[];

void Bsp_Init(void);
void Bsp_Loop(void);
#endif /* __BSP_H */
