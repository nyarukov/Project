#include "bsp_led.h"

#define led_r 11
#define led_g 12
#define led_b 15

static void LEDR_ON(void)
{
	__GPIO_RESET_BIT(GPIOA, led_r);
}
static void LEDR_OFF(void)
{
	__GPIO_SET_BIT(GPIOA, led_r);
}
static void LEDG_ON(void)
{
	__GPIO_RESET_BIT(GPIOA, led_g);
}
static void LEDG_OFF(void)
{
	__GPIO_SET_BIT(GPIOA, led_g);
}
static void LEDB_ON(void)
{
	__GPIO_RESET_BIT(GPIOA, led_b);
}
static void LEDB_OFF(void)
{
	__GPIO_SET_BIT(GPIOA, led_b);
}

void Led_Init(void)
{
	__HAL_RCC_GPIOA_CLK_ENABLE();
	GPIO_InitTypeDef GPIO_InitStructe;
	GPIO_InitStructe.Pin = GPIO_PIN_11 | GPIO_PIN_12 | GPIO_PIN_15;
	GPIO_InitStructe.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructe.Pull = GPIO_PULLUP;
	GPIO_InitStructe.Speed = GPIO_SPEED_LOW;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStructe);
	__GPIO_SET_BIT(GPIOA, led_r);
	__GPIO_SET_BIT(GPIOA, led_g);
	__GPIO_SET_BIT(GPIOA, led_b);

	Command_t led_cmds[] = {
		{"ledr_on", LEDR_ON},
		{"ledr_off", LEDR_OFF},
		{"ledg_on", LEDG_ON},
		{"ledg_off", LEDG_OFF},
		{"ledb_on", LEDB_ON},
		{"ledb_off", LEDB_OFF}};
	Register_Cmds(led_cmds, ARRAY_SIZE(led_cmds));
}
