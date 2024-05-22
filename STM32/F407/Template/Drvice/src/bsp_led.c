#include "bsp_led.h"

#define LED0 GPIO_Pin_9
#define LED1 GPIO_Pin_10

void Led_Init(void)
{
//	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
//	GPIO_InitTypeDef GPIOx_Config;
//	GPIOx_Config.GPIO_Pin = LED0 | LED1;
//	GPIOx_Config.GPIO_Mode = GPIO_Mode_OUT;
//	GPIOx_Config.GPIO_Speed = GPIO_Speed_2MHz;
//	GPIOx_Config.GPIO_OType = GPIO_OType_PP;
//	GPIO_Init(GPIOF, &GPIOx_Config);
//	__GPIO_SET_BIT(GPIOF, 9);
//	__GPIO_SET_BIT(GPIOF, 10);
}
