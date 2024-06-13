#ifndef __BSP_PWM_H
#define __BSP_PWM_H

#include "stm32f10x.h"
#include "bsp_user_lib.h"

#define MAX_DUTY_CYCLE 1000 // 最大占空比值
#define MIN_DUTY_CYCLE 0    // 最小占空比值

void PWM_Init(void);
void SetPWM_DutyCycle(uint16_t duty_cycle);
void SetPWM_Frequency(uint32_t frequency);
void PWM_Start(void);
void PWM_Stop(void);
#endif
