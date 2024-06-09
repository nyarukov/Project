/*
 * 项目名称: Basic_Tim
 * 版本:1.0
 * 作者: Yusaka
 * 创建日期: 2024-06-09 15:12:15
 * 最后修改日期: 2024-06-09 15:12:15
 * 描述: 基本定时器
 */

#include "Basic_Tim.h"

// C 文件内容...
void init_basic_tim(void)
{
    TIMRE_Config timConfig;
    timConfig.ID = TIM_3;
    timConfig.Mode = TIMER_MODE_BASIC;
    timConfig.prescaler = 8400 - 1; // 84MHz / 8400 = 10kHz
    timConfig.counterMode = TIM_CounterMode_Up;
    timConfig.period = 5000 - 1; // 10kHz / 5000 = 2Hz (500ms)
    timConfig.clockDivision = TIM_CKD_DIV1;
    timConfig.interruptEnable = 1; // 开启中断
    timConfig.dmaEnable = 0;
    timConfig.dmaRequest = 0;
    TIM_Init(&timConfig, BF_NULL);
}