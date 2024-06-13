#ifndef __BSP_H
#define __BSP_H

#include "stm32f10x.h" // Device header
#include "bsp_led.h"
#include "bsp_key.h"
#include "bsp_uart.h"
#include "bsp_adc.h"
#include "bsp_adc_app.h"
#include "bsp_systick.h"
#include "bsp_esp8266.h"

#include "bsp_i2c_app.h"
#include "bsp_pwm.h"
#include "bsp_oled_app.h"
#include "bsp_cpu_flash.h"

#define DEBUG_ENABLE 1
#define ERROR_HANDLE_ENABLE 0
#define KEY_PRINT_ENABLE 0

#if (DEBUG_ENABLE == 1)
#define DEBUG_PRINT(...)         \
    do                           \
    {                            \
        LOG_Printf(__VA_ARGS__); \
    } while (0)
#else
#define DEBUG_PRINT(...)
#endif

// 错误处理宏定义
#if (ERROR_HANDLE_ENABLE == 1)
#define ERROR_HANDLE(message)                 \
    do                                        \
    {                                         \
        LOG_Printf("Error: %s\r\n", message); \
    } while (0)
#else
#define ERROR_HANDLE(message)
#endif

// 定义打印输出宏
#if KEY_PRINT_ENABLE
#define KEY_PRINT(fmt, ...) LOG_Printf(fmt, ##__VA_ARGS__)
#else
#define KEY_PRINT(fmt, ...)
#endif

typedef struct
{
    uint32_t c1ms;
    uint32_t c100ms;
    uint32_t c1s;
} systime;

typedef struct
{
    float lux;   // 光照
    float temp;  // 温度
    float humi;  // 湿度
    float Pa;    // 大气压强
    float ALT;   // 海拔
    float MQ2;   // 烟雾
    float MQ4;   // 甲烷
    float MQ7;   // 一氧化碳
    float MQ135; // 空气污染
    float Fire;  // 火焰
} User_Data;

extern User_Data user_data;
extern uint8_t alarm_flag;
#endif
