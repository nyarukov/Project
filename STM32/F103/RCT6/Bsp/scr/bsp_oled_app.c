#include "bsp_oled_app.h"
#include "oled_font.h"
#include <string.h>
#include <stdio.h>

#define INTERNAL_FLASH_START_ADDRESS ((uint32_t)0x08019000)

Menu_Data MDV_Flash;

int8_t selectItem = 0;	  // 当前菜单在当前菜单页的索引，最大为3，一页最多显示四个菜单
int8_t scrollBar = 0;	  // 滚动条
struct Menu_t *menuPoint; // 当前菜单

void tempVptIncrement(void);
void tempVptDecrement(void);
void humiVptIncrement(void);
void humiVptDecrement(void);
void luxVptIncrement(void);
void luxVptDecrement(void);
void fireVptIncrement(void);
void fireVptDecrement(void);
void mq2VptIncrement(void);
void mq2VptDecrement(void);
void mq4VptIncrement(void);
void mq4VptDecrement(void);
void mq7VptIncrement(void);
void mq7VptDecrement(void);
void mq135VptIncrement(void);
void mq135VptDecrement(void);

struct Menu_t MainUI = {{1, 0}, "MainUI", NULL, NULL, NULL, NULL};

struct Menu_t menuMain[5] =
	{
		{{5, 1}, "[<--]          ", NULL, NULL, NULL, &MainUI, NULL}, // 返回
		{{5, 1}, "[WEATHER]      ", NULL, NULL, NULL, NULL, NULL},	  // 温湿度
		{{5, 1}, "[PREALTI]      ", NULL, NULL, NULL, NULL, NULL},	  // 气压，海拔
		{{5, 1}, "[LIGHTFL]      ", NULL, NULL, NULL, NULL, NULL},	  // 光照火焰
		{{5, 1}, "[GAS]          ", NULL, NULL, NULL, NULL, NULL},	  // 气体
};

// 温湿度子菜单
struct Menu_t weatherMain[4] =
	{
		{{4, 0}, "[<--]           ", NULL, NULL, NULL, menuMain, NULL}, // 返回
		{{4, 0}, "[TEMP]  0.0C    ", NULL, NULL, NULL, NULL, NULL},		// 温度
		{{4, 0}, "[HUMI]  0.0%RH  ", NULL, NULL, NULL, NULL, NULL},		// 湿度
		{{4, 0}, "[SETTINGS]      ", NULL, NULL, NULL, NULL, NULL}		// 参数设置 - 温湿度
};

struct Menu_t weather_settings[3] =
	{
		{{3, 0}, "[<--]          ", NULL, NULL, NULL, weatherMain, NULL},								 // 返回
		{{3, 0}, "[TEMP VPT]     ", tempVptIncrement, tempVptDecrement, WriteStructToFlash, NULL, NULL}, // 最大值
		{{3, 0}, "[HUMI VPT]     ", humiVptIncrement, humiVptDecrement, WriteStructToFlash, NULL, NULL}, // 最大值
};

// 气压子菜单
struct Menu_t pre_altiMain[3] =
	{
		{{3, 0}, "[<--]           ", NULL, NULL, NULL, menuMain, NULL}, // 返回
		{{3, 0}, "[PRE]   0.0Pa   ", NULL, NULL, NULL, NULL, NULL},		// 气压值
		{{3, 0}, "[ALTI]  0.0mm   ", NULL, NULL, NULL, NULL, NULL},		// 海拔值
};

// 火焰子菜单
struct Menu_t lightMain[4] =
	{
		{{4, 0}, "[<--]           ", NULL, NULL, NULL, menuMain, NULL}, // 返回
		{{4, 0}, "[LUX]   0.0lx   ", NULL, NULL, NULL, NULL, NULL},		// 光照
		{{4, 0}, "[FIRE]  0.0mm   ", NULL, NULL, NULL, NULL, NULL},		// 火焰值
		{{4, 0}, "[SETTINGS]      ", NULL, NULL, NULL, NULL, NULL}		// 参数设置-光照火焰值
};

struct Menu_t light_settings[3] =
	{
		{{3, 0}, "[<--]          ", NULL, NULL, NULL, lightMain, NULL},									 // 返回
		{{3, 0}, "[LUX VPT]      ", luxVptIncrement, luxVptDecrement, WriteStructToFlash, NULL, NULL},	 // 最大值
		{{3, 0}, "[Fire VPT]     ", fireVptIncrement, fireVptDecrement, WriteStructToFlash, NULL, NULL}, // 最大值
};

// 气体子菜单
struct Menu_t gasMain[6] =
	{
		{{6, 2}, "[<--]           ", NULL, NULL, NULL, menuMain, NULL}, // 返回
		{{6, 2}, "[MQ2]   0.0%    ", NULL, NULL, NULL, NULL, NULL},		// MQ-2 烟雾气体传感器值
		{{6, 2}, "[MQ4]   0.0ppm  ", NULL, NULL, NULL, NULL, NULL},		// MQ-4 甲烷气体传感器值
		{{6, 2}, "[MQ7]   0.0ppm  ", NULL, NULL, NULL, NULL, NULL},		// MQ-7 一氧化碳气体传感器值
		{{6, 2}, "[MQ135] 0.0ppm  ", NULL, NULL, NULL, NULL, NULL},		// MQ-135 有害气体传感器值
		{{6, 2}, "[SETTINGS]      ", NULL, NULL, NULL, NULL, NULL}		// 参数设置-气体
};

struct Menu_t gas_settings[5] =
	{
		{{5, 1}, "[<--]          ", NULL, NULL, NULL, gasMain, NULL},									   // 返回
		{{5, 1}, "[MQ2 VPT]      ", mq2VptIncrement, mq2VptDecrement, WriteStructToFlash, NULL, NULL},	   // 最大值
		{{5, 1}, "[MQ4 VPT]      ", mq4VptIncrement, mq4VptDecrement, WriteStructToFlash, NULL, NULL},	   // 最大值
		{{5, 1}, "[MQ7 VPT]      ", mq7VptIncrement, mq7VptDecrement, WriteStructToFlash, NULL, NULL},	   // 最大值
		{{5, 1}, "[MQ135 VPT]    ", mq135VptIncrement, mq135VptDecrement, WriteStructToFlash, NULL, NULL}, // 最大值
};

void Menu_Clear_Box(void)
{
	OLED_ClearSolidBox(10, 11, 128, 16);
	OLED_ClearSolidBox(10, 11 + 16 * 1, 128, 16 + 16 * 1);
	OLED_ClearSolidBox(10, 11 + 16 * 2, 128, 16 + 16 * 2);
	OLED_ClearSolidBox(10, 11 + 16 * 3, 128, 16 + 16 * 3);
	OLED_Refresh_Gram(); // 更新显示
}

void DisplayRefreash(struct Menu_t *ShowMenu, uint8_t IndexItem, uint8_t scrollBar)
{
	int i = 0;
	static uint8_t last_IndexItem = 0;
	if (ShowMenu == &MainUI)
	{
		OLED_Clear();
		Menu_Main();
	}
	else
	{

		OLED_ShowChar(0, last_IndexItem * 16, ' ', 12, 1);
		OLED_ShowChar(0, IndexItem * 16, '>', 12, 1);
		for (i = 0; i < (ShowMenu->page_info.total_menus - ShowMenu->page_info.current_page); i++)
		{
			// Ensure menu labels are displayed within 15 characters
			char display_label[MAX_MENU_LABEL_LENGTH + 1];
			snprintf(display_label, MAX_MENU_LABEL_LENGTH + 1, "%-15s", ShowMenu[i + scrollBar].label);
			OLED_ShowString(8, i * 16, display_label, 12, 1);
		}
	}
	OLED_Refresh_Gram();
	last_IndexItem = IndexItem;
}

void DisplayRefreashData(struct Menu_t *showMenu, u8 selectItem, u8 scrollBar)
{
	int i = 0;
	for (i = 0; i < (showMenu->page_info.total_menus - showMenu->page_info.current_page); i++)
	{
		OLED_ShowString(8, i * 12, showMenu[i + scrollBar].label, 12, 1);
	}
	OLED_Refresh_Gram();
}
void MEnu_Init(void)
{
	MainUI.child = menuMain;
	menuMain[1].child = weatherMain;
	menuMain[2].child = pre_altiMain;
	menuMain[3].child = lightMain;
	menuMain[4].child = gasMain;
	weatherMain[3].child = weather_settings;
	lightMain[3].child = light_settings;
	gasMain[5].child = gas_settings;
	menuPoint = &MainUI;
	DisplayRefreash(menuPoint, selectItem, scrollBar);
}

void Menu_Main(void)
{

	OLED_ShowString(45, 5, "STM32", 16, 1);
	OLED_Show_CH(18 + 16 * 0, 25, 0, 16, 1);
	OLED_Show_CH(18 + 16 * 1, 25, 1, 16, 1);
	OLED_Show_CH(18 + 16 * 2, 25, 2, 16, 1);
	OLED_Show_CH(18 + 16 * 3, 25, 3, 16, 1);
	OLED_Show_CH(18 + 16 * 4, 25, 4, 16, 1);
	OLED_Show_CH(18 + 16 * 5, 25, 5, 16, 1);
	OLED_Show_CH(18 + 16 * 2, 45, 6, 16, 1);
	OLED_Show_CH(18 + 16 * 3, 45, 7, 16, 1);
}

void GuiDataDisplayRefresh(void)
{
	if (menuPoint == weatherMain)
	{
		snprintf((char *)weatherMain[1].label, 18, "[TEMP]  %.1fC      ", user_data.temp);
		snprintf((char *)weatherMain[2].label, 18, "[HUMI]  %.1f%%RH   ", user_data.humi);
		DisplayRefreash(menuPoint, selectItem, scrollBar);
	}
	else if (menuPoint == weather_settings)
	{
		snprintf((char *)weather_settings[1].label, 18, "[TEMP VPT] %3d    ", MDV_Flash.tempVpt);
		snprintf((char *)weather_settings[2].label, 18, "[HUMI VPT] %3d    ", MDV_Flash.humiVpt);
		DisplayRefreash(menuPoint, selectItem, scrollBar);
	}
	else if (menuPoint == pre_altiMain)
	{
		snprintf((char *)pre_altiMain[1].label, 18, "[PRE]   %.1fPa     ", user_data.Pa);
		snprintf((char *)pre_altiMain[2].label, 18, "[ALTI]  %.1fmm     ", user_data.ALT);
		DisplayRefreash(menuPoint, selectItem, scrollBar);
	}
	else if (menuPoint == lightMain)
	{
		snprintf((char *)lightMain[1].label, 18, "[LUX]   %.1flx      ", user_data.lux);
		snprintf((char *)lightMain[2].label, 18, "[FIRE]  %.1fmm      ", user_data.Fire);
		DisplayRefreash(menuPoint, selectItem, scrollBar);
	}
	else if (menuPoint == light_settings)
	{
		snprintf((char *)light_settings[1].label, 18, "[LUX VPT]  %3d    ", MDV_Flash.luxVpt);
		snprintf((char *)light_settings[2].label, 18, "[FIRE VPT] %3d    ", MDV_Flash.fireVpt);
		DisplayRefreash(menuPoint, selectItem, scrollBar);
	}
	else if (menuPoint == gasMain)
	{
		snprintf((char *)gasMain[1].label, 18, "[MQ2]    %.1f%%          ", user_data.MQ2);
		snprintf((char *)gasMain[2].label, 18, "[MQ4]    %.1f%%          ", user_data.MQ4);
		snprintf((char *)gasMain[3].label, 18, "[MQ7]    %.1f%%          ", user_data.MQ7);
		snprintf((char *)gasMain[4].label, 18, "[MQ135]  %.1f%%  	     ", user_data.MQ135);
		DisplayRefreash(menuPoint, selectItem, scrollBar);
	}
	else if (menuPoint == gas_settings)
	{
		snprintf((char *)gas_settings[1].label, 18, "[MQ2 VPT]   %3d      ", MDV_Flash.mq2Vpt);
		snprintf((char *)gas_settings[2].label, 18, "[MQ4 VPT]   %3d      ", MDV_Flash.mq4Vpt);
		snprintf((char *)gas_settings[3].label, 18, "[MQ7 VPT]   %3d      ", MDV_Flash.mq7Vpt);
		snprintf((char *)gas_settings[4].label, 18, "[MQ135 VPT] %3d      ", MDV_Flash.mq135Vpt);
		DisplayRefreash(menuPoint, selectItem, scrollBar);
	}
	else if (menuPoint == &MainUI)
	{
		Menu_Main();
		OLED_Refresh_Gram();
	}
}

void GuiControl(uint8_t keyPressed)
{
	switch (keyPressed) // 根据按键事件执行相应的操作
	{
	case KEY1_CLICK:																   // 处理 KEY1 单击事件
		if (selectItem == 0 && scrollBar == 0 && menuPoint[selectItem].parent != NULL) // 如果选中的是第一个菜单项并且存在父菜单
		{
			menuPoint = menuPoint[selectItem].parent; // 切换到父菜单
		}
		else if (menuPoint[selectItem + scrollBar].child != NULL) // 如果选中的菜单项有子菜单
		{
			OLED_Clear();
			menuPoint = menuPoint[selectItem + scrollBar].child; // 切换到子菜单
			selectItem = 0;
			scrollBar = 0;							   // 将选中的菜单项设置为子菜单的第一个
			if (menuPoint->page_info.total_menus <= 3) // 如果子菜单大小小于等于 3
			{
				OLED_ShowString(8, 4 * 16, "               ", 12, 1);
			}
		}

		DisplayRefreash(menuPoint, selectItem, scrollBar); // 更新菜单显示
		break;

	case KEY1_DOUBLE:											 // 处理 KEY1 双击事件
		if (menuPoint[selectItem + scrollBar].function3 != NULL) // 如果选中的菜单项有第3个功能
		{
			menuPoint[selectItem + scrollBar].function3(); // 执行选中的菜单项的第3个功能
		}
		DisplayRefreash(menuPoint, selectItem, scrollBar); // 更新菜单显示
		break;
	case KEY1_PRESS: // 处理 KEY1 长按事件
		break;

	case KEY2_CLICK:																																   // 处理 KEY2 单击事件
		selectItem++;																																   // 选中的菜单项向下滚动一个位置
		if (selectItem > (menuPoint->page_info.total_menus - 1 - menuPoint->page_info.current_page) && scrollBar != menuPoint->page_info.current_page) // 如果选中的菜单项已经滚动到底部并且不在最后一页
		{
			selectItem = menuPoint->page_info.total_menus - 1 - menuPoint->page_info.current_page; // 将选中的菜单项设置为当前页最后一个
			scrollBar++;																		   // 滚动条向下滚动一页
		}
		else if (selectItem > (menuPoint->page_info.total_menus - 1 - menuPoint->page_info.current_page) && scrollBar == menuPoint->page_info.current_page) // 如果选中的菜单项已经滚动到底部并且在最后一页
		{
			selectItem = 0; // 将选中的菜单项设置为第一个
			scrollBar = 0;	// 将滚动条设置为第一页
		}
		DisplayRefreash(menuPoint, selectItem, scrollBar); // 更新菜单显示
		break;

	case KEY2_DOUBLE:						  // 处理 KEY2 双击事件
		selectItem--;						  // 选中的菜单项向上滚动一个位置
		if (selectItem < 0 && scrollBar != 0) // 如果选中的菜单项已经滚动到顶部并且不在第一页
		{
			selectItem = 0; // 将选中的菜单项设置为第一个
			scrollBar--;	// 滚动条向上滚动一页
		}
		else if (selectItem < 0 && scrollBar == 0) // 如果选中的菜单项已经滚动到顶部并且在第一页
		{
			selectItem = menuPoint->page_info.total_menus - 1 - menuPoint->page_info.current_page; // 将选中的菜单项设置为当前页最后一个
			scrollBar = menuPoint->page_info.current_page;										   // 将滚动条设置为最后一页
		}
		DisplayRefreash(menuPoint, selectItem, scrollBar); // 更新菜单显示
		break;

	case KEY3_CLICK:											 // 处理 KEY3 单击事件
		if (menuPoint[selectItem + scrollBar].function1 != NULL) // 如果选中的菜单项有第一个功能
		{
			menuPoint[selectItem + scrollBar].function1(); // 执行选中的菜单项的第一个功能
		}
		DisplayRefreash(menuPoint, selectItem, scrollBar); // 更新菜单显示
		break;

	case KEY3_DOUBLE:											 // 处理 KEY3 双击事件
		if (menuPoint[selectItem + scrollBar].function2 != NULL) // 如果选中的菜单项有第二个功能
		{
			menuPoint[selectItem + scrollBar].function2(); // 执行选中的菜单项的第二个功能
		}
		DisplayRefreash(menuPoint, selectItem, scrollBar); // 更新菜单显示
		break;
	case KEY3_PRESS:
		alarm_flag = 0;
		break;
	default: // 默认情况，不执行任何操作
		break;
	}
	// Beep_Variable(10, 1);
	Menu_Clear_Box();		 // 清除菜单框架
	GuiDataDisplayRefresh(); // 更新数据显示
}

void tempVptIncrement(void)
{
	MDV_Flash.tempVpt++;
}

void tempVptDecrement(void)
{
	MDV_Flash.tempVpt--;
}

void humiVptIncrement(void)
{
	MDV_Flash.humiVpt++;
}

void humiVptDecrement(void)
{
	MDV_Flash.humiVpt--;
}

void luxVptIncrement(void)
{
	MDV_Flash.luxVpt++;
}

void luxVptDecrement(void)
{
	MDV_Flash.luxVpt--;
}

void fireVptIncrement(void)
{
	MDV_Flash.fireVpt++;
}

void fireVptDecrement(void)
{
	MDV_Flash.fireVpt--;
}

void mq2VptIncrement(void)
{
	MDV_Flash.mq2Vpt++;
}

void mq2VptDecrement(void)
{
	MDV_Flash.mq2Vpt--;
}

void mq4VptIncrement(void)
{
	MDV_Flash.mq4Vpt++;
}

void mq4VptDecrement(void)
{
	MDV_Flash.mq4Vpt--;
}

void mq7VptIncrement(void)
{
	MDV_Flash.mq7Vpt++;
}

void mq7VptDecrement(void)
{
	MDV_Flash.mq7Vpt--;
}

void mq135VptIncrement(void)
{
	MDV_Flash.mq135Vpt++;
}

void mq135VptDecrement(void)
{
	MDV_Flash.mq135Vpt--;
}

void WriteStructToFlash(void)
{
	CPU_Flash_ErasePage(INTERNAL_FLASH_START_ADDRESS);
	// 将结构体数据写入Flash
	CPU_Flash_Write(INTERNAL_FLASH_START_ADDRESS, (uint32_t *)&MDV_Flash, sizeof(Menu_Data) / sizeof(int32_t));
	// DEBUG_PRINT("Saving data %d to address %p in Flash...\n", data, address);
	ReadStructFromFlash();
	Beep_Variable(100, 1);
}

void ReadStructFromFlash(void)
{
	// 从Flash读取结构体数据
	CPU_Flash_Read(INTERNAL_FLASH_START_ADDRESS, (uint32_t *)&MDV_Flash, sizeof(Menu_Data) / sizeof(int32_t));
}
