#ifndef __BSP_PERIPH_H
#define __BSP_PERIPH_H

#include "stm32f4xx.h"
#include "bf_middle.h"
#include "bsp_soft_i2c.h"
#include "bsp_systick.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int BSP_BH1750_Init(void);
void BH1750_Read(void);
#endif /* __BSP_PERIPH_H */
