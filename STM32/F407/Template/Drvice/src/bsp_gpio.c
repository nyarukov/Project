#include "bsp_gpio.h"

void* GET_PORT(uint8_t _IOx)
{
	void *port = 0;
	uint8_t port_num = _IOx >> 4;
	if (port_num <= 8)
	{
		port = (void *)(GPIOA_BASE + 0x400 * port_num);
	}
	return port;
}
void RCC_IO_XXABLE(uint8_t _IOx, uint8_t _Val)
{
	uint8_t port = _IOx >> 4;
	if (_Val)
		__RCC_GPIOX_ENABLE(port);
	else
		__RCC_GPIOX_DISABLE(port);
}
void IO_Wrtie(uint8_t _IOx, uint8_t _Val)
{
	uint8_t Pin = _IOx & 0x0F;
	GPIO_TypeDef *GPIOx = ((GPIO_TypeDef*)GET_PORT(_IOx));
	(_Val) ? __IO_SET_BIT(GPIOx, Pin) : __IO_RESET_BIT(GPIOx, Pin);
}

void IO_Init(uint8_t _IOx, uint8_t _Mode,
			  uint8_t _OType, uint8_t _Pupd,
			  uint8_t _Speed)
{
	RCC_IO_XXABLE(_IOx, 1);
	uint8_t Pin = _IOx & 0x0F;
	GPIO_TypeDef *GPIOx = (GPIO_TypeDef *)GET_PORT(_IOx);
	__IO_WRITE_MODE(GPIOx, Pin, _Mode);
	__IO_WRITE_OTYPE(GPIOx, Pin, _OType);
	__IO_WRITE_SPEED(GPIOx, Pin, _Speed);
	__IO_WRITE_PUPD(GPIOx, Pin, _Pupd);
}
