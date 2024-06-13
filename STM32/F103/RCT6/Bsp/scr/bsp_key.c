#include "bsp_key.h"

/// 读取按键状态
uint8_t read_button_pin1(void)
{
	return GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_1);
}
/// 读取按键状态
uint8_t read_button_pin2(void)
{
	return GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_2);
}
/// 读取按键状态
uint8_t read_button_pin3(void)
{
	return GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_3);
}
/*******************KEY1*************************/
/// 单击事件
void button1_single_click_callback(void *arg)
{
	GuiControl(KEY1_CLICK);
	KEY_PRINT("%s\r\n", __FUNCTION__);
}

/// 双击事件
void button1_double_click_callback(void *arg)
{

	GuiControl(KEY1_DOUBLE);
	KEY_PRINT("%s\r\n", __FUNCTION__);
}

/// 长按触发
void button1_press_start_callback(void *arg)
{
	GuiControl(KEY1_PRESS);
	KEY_PRINT("%s\r\n", __FUNCTION__);
}
/*******************KEY2*************************/
/// 单击事件
void button2_single_click_callback(void *arg)
{
	GuiControl(KEY2_CLICK);
	KEY_PRINT("%s\r\n", __FUNCTION__);
}

/// 双击事件
void button2_double_click_callback(void *arg)
{
	GuiControl(KEY2_DOUBLE);
	KEY_PRINT("%s\r\n", __FUNCTION__);
}

/// 长按触发
void button2_press_start_callback(void *arg)
{
	GuiControl(KEY2_PRESS);
	KEY_PRINT("%s\r\n", __FUNCTION__);
}
/*******************KEY3*************************/
/// 单击事件
void button3_single_click_callback(void *arg)
{
	GuiControl(KEY3_CLICK);
	KEY_PRINT("%s\r\n", __FUNCTION__);
}

/// 双击事件
void button3_double_click_callback(void *arg)
{
	GuiControl(KEY3_DOUBLE);
	KEY_PRINT("%s\r\n", __FUNCTION__);
}

/// 长按触发
void button3_press_start_callback(void *arg)
{
	GuiControl(KEY3_PRESS);
	KEY_PRINT("%s\r\n", __FUNCTION__);
}

struct Button button1;
struct Button button2;
struct Button button3;

void Button_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStruct);

	// 初始化按钮结构体
	button_init(&button1, read_button_pin1, 0, 0);
	button_init(&button2, read_button_pin2, 0, 0); // 假设read_button_pin2是读取button2状态的函数
	button_init(&button3, read_button_pin3, 0, 0); // 假设read_button_pin3是读取button3状态的函数

	// 注册按键事件
	button_attach(&button1, SINGLE_CLICK, button1_single_click_callback);
	button_attach(&button1, DOUBLE_CLICK, button1_double_click_callback);
	button_attach(&button1, LONG_PRESS_START, button1_press_start_callback);

	button_attach(&button2, SINGLE_CLICK, button2_single_click_callback);
	button_attach(&button2, DOUBLE_CLICK, button2_double_click_callback);
	button_attach(&button2, LONG_PRESS_START, button2_press_start_callback);

	button_attach(&button3, SINGLE_CLICK, button3_single_click_callback);
	button_attach(&button3, DOUBLE_CLICK, button3_double_click_callback);
	button_attach(&button3, LONG_PRESS_START, button3_press_start_callback);

	// 启动按键监测
	button_start(&button1);
	button_start(&button2);
	button_start(&button3);
}
