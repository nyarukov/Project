#include "systick.h"

/**
 * @brief usÑÓÊ±
 *
 * @param us
 */
void Delay_Us(uint32_t us)
{
    SysTick->LOAD = us * (SystemCoreClock / 1000000);
    SysTick->VAL = 0UL;
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
    while (!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk));
    
    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}

void Delay_Ms(uint32_t ms)
{
    while (ms--)
    {
        Delay_Us(1000);
    }
}
