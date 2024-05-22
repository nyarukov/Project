#include "bsp_led.h"

void Beep_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOC, &GPIO_InitStruct);
	__GPIO_SET_BIT(GPIOC, 0);
}

void Beep_Simple(uint32_t ms)
{
	__GPIO_RESET_BIT(GPIOC, 0);
	Delay_ms(ms); // 持续鸣叫时间
	__GPIO_SET_BIT(GPIOC, 0);
}

void Beep_Variable(uint32_t ms, uint8_t count)
{
	uint8_t i;
	for (i = 0; i < count; i++)
	{
		__GPIO_RESET_BIT(GPIOC, 0);
		Delay_ms(ms); // 持续鸣叫时间
		__GPIO_SET_BIT(GPIOC, 0);

		if (i != count - 1)
		{
			Delay_ms(ms); // 间隔时间
		}
	}
}

