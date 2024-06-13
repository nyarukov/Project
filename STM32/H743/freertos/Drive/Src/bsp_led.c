#include "bsp_led.h"

void Led_Init(void)
{
	__HAL_RCC_GPIOA_CLK_ENABLE();
	GPIO_InitTypeDef GPIO_InitStructe;
	GPIO_InitStructe.Pin = GPIO_PIN_11 | GPIO_PIN_12 | GPIO_PIN_15;
	GPIO_InitStructe.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructe.Pull = GPIO_PULLUP;
	GPIO_InitStructe.Speed = GPIO_SPEED_LOW;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStructe);
	__GPIO_SET_BIT(GPIOA,led_r);
	__GPIO_SET_BIT(GPIOA,led_g);
	__GPIO_SET_BIT(GPIOA,led_b);
}
void Led_Set(uint8_t led, bool value)
{
	(value==true)? (__GPIO_RESET_BIT(GPIOA,led)) : (__GPIO_SET_BIT(GPIOA,led));
}
