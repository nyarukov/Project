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
void inti_systemtick(void)
{
    SysTick->LOAD = (SystemCoreClock / SYSTICK_VAL) - 1;
    SysTick->VAL = 0UL;
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk |
                    SysTick_CTRL_TICKINT_Msk |
                    SysTick_CTRL_ENABLE_Msk;
}
void Delay_Us(uint32_t us)
{
    uint32_t count = (SystemCoreClock / 1000000) * us / 5;
    while (count--)
    {
        __NOP();
    }
}

void Delay_Ms(uint32_t ms)
{
    TIME_OUT(ms);
}
