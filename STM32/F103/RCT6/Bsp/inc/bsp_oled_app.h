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
        uint8_t total_menus;  // �˵�������
        uint8_t current_page; // ��ǰ��ʾ�Ĳ˵�ҳ��
    } page_info;
    char label[MAX_MENU_LABEL_LENGTH + 1]; // �˵���ı�ǩ
    void (*function1)(void);               // ��ǰ�˵��Ĺ��ܺ���1
    void (*function2)(void);               // ��ǰ�˵��Ĺ��ܺ���2
    void (*function3)(void);               // ��ǰ�˵��Ĺ��ܺ���3
    struct Menu_t *parent;                 // �˵���ĸ����˵�
    struct Menu_t *child;                  // �˵�����Ӽ��˵�
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
