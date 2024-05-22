#include "bsp_led.h"

#define led_g 11
#define led_r 12
#define led_b 15

static void Led_Set(uint8_t led, uint8_t value)
{
	(value == 0) ? (__GPIO_RESET_BIT(GPIOA, led)) : (__GPIO_SET_BIT(GPIOA, led));
}

static void ledr_on(void)
{
	Led_Set(led_r, 0);
}
static void ledr_off(void)
{
	Led_Set(led_r, 1);
}
static void ledg_on(void)
{
	Led_Set(led_g, 0);
}
static void ledg_off(void)
{
	Led_Set(led_g, 1);
}
static void ledb_on(void)
{
	Led_Set(led_b, 0);
}
static void ledb_off(void)
{
	Led_Set(led_b, 1);
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

	Command_t led_cmds[] = {
		{"ledr_on", ledr_on},
		{"ledr_off", ledr_off},
		{"ledg_on", ledg_on},
		{"ledg_off", ledg_off},
		{"ledb_on", ledb_on},
		{"ledb_off", ledb_off}};
	Register_Cmds(led_cmds, ARRAY_SIZE(led_cmds));

	__GPIO_SET_BIT(GPIOA, led_r);
	__GPIO_SET_BIT(GPIOA, led_g);
	__GPIO_SET_BIT(GPIOA, led_b);
}
