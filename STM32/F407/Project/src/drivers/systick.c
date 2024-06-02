/*
 * 项目名称: systick
 * 版本:1.0
 * 作者: Yusaka
 * 创建日期: 2024-06-01
 * 最后修改日期: 2024-06-01 18:09:50
 * 描述: 滴答定时器驱动
 */

#include "systick.h"

// C 文件内容...
/**
 * @brief 
 *
 * @param us
 */
void Delay_Us(uint32_t us)
{
    SysTick->LOAD = us * (SystemCoreClock / 8000000);
    SysTick->VAL = 0UL;
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
    while (!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk))
        ;
    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}

void Delay_Ms(uint32_t ms)
{
    while (ms--)
    {
        Delay_Us(1000);
    }
}
