#ifndef __BSP_OLED_APP_H
#define __BSP_OLED_APP_H

#include "stm32f10x.h"
#include "bsp_oled.h"
#include "bsp_key.h"
#include "bsp_i2c_app.h"
#include "bsp_cpu_flash.h"

#define MAX_MENU_LABEL_LENGTH 15
typedef struct Menu_t
{
    struct
    {
        uint8_t total_menus;  // 菜单的总数
        uint8_t current_page; // 当前显示的菜单页码
    } page_info;
    char label[MAX_MENU_LABEL_LENGTH + 1]; // 菜单项的标签
    void (*function1)(void);               // 当前菜单的功能函数1
    void (*function2)(void);               // 当前菜单的功能函数2
    void (*function3)(void);               // 当前菜单的功能函数3
    struct Menu_t *parent;                 // 菜单项的父级菜单
    struct Menu_t *child;                  // 菜单项的子级菜单
} Menu_t;

typedef struct
{
    int32_t tempVpt;
    int32_t humiVpt;
    int32_t luxVpt;
    int32_t fireVpt;
    int32_t mq2Vpt;
    int32_t mq4Vpt;
    int32_t mq7Vpt;
    int32_t mq135Vpt;
} Menu_Data;

extern Menu_Data MDV_Flash;

void Menu_Main(void);
void MEnu_Init(void);
void GuiDataDisplayRefresh(void);
void GuiControl(uint8_t keyPressed);

void WriteStructToFlash(void);
void ReadStructFromFlash(void);
#endif
