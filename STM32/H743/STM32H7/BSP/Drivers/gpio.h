#ifndef __GPIO_H
#define __GPIO_H

#include "stm32h7xx_hal.h"
#include "user_lib.h"
#include "uart.h"

// // 根据 GPIO 组使能相应的时钟
// #define GPIO_CLK_ENABLE(group)      do { \
//                                     __HAL_RCC_GPIO\##group##_CLK_ENABLE(); \
//                                     } while(0)
// // 根据 GPIO 组失能相应的时钟
// #define GPIO_CLK_DISABLE(group)     do { \
//                                     __HAL_RCC_GPIO ## group ## _CLK_DISABLE(); \
//                                     } while(0)
// // 解析引脚号
#define GPIO_PIN_NUM(pin)           ((pin[3] != '\0') ? (((pin[2]) - '0') * 10 + ((pin[3]) - '0')) : ((pin[2]) - '0'))
// // 解析基地址
// #define GPIOx_BASE(group)           do { \
//                                     GPIO ## group \
//                                     } while(0)

// 定义IO模式枚举
typedef enum {
    IO_MODE_FLOATING = 0x00UL,               // 浮空输入模式 
    IO_MODE_ANALOG = 0x01UL,                 // 模拟输入模式
    IO_MODE_PULL_UP = 0x02UL,                // 上拉输入模式
    IO_MODE_PULL_DOWN = 0x04UL,              // 下拉输入模式
    IO_MODE_PUSH_PULL_UP = 0x08UL,           // 推挽上拉输出模式
    IO_MODE_PUSH_PULL_DOWN = 0x10UL,         // 推挽下拉输出模式
    IO_MODE_OPEN_DRAIN_UP = 0x20UL,          // 开漏上拉输出模式
    IO_MODE_OPEN_DRAIN_DOWN = 0x40UL         // 开漏下拉输出模式
} IOMode;


// 定义IO速度枚举
typedef enum {
    IO_SPEED_LOW = 0x00UL,       // 低速
    IO_SPEED_MEDIUM = 0x01UL,    // 中速
    IO_SPEED_HIGH = 0x02UL,      // 高速
    IO_SPEED_HIGH_VERY = 0x04UL  // 非常高速
} IOSpeed;

// 定义IO控制命令枚举
typedef enum {
    CMD_IO_NEG,     // 反转IO状态
    CMD_IO_ON_T,    // 打开IO并设置持续时间
    CMD_IO_OFF_T,   // 关闭IO并设置持续时间
    CMD_IO_RST,     // 重置IO状态
    CMD_IO_CLOSE    // 关闭IO
} IOCmd;


/**
 * @brief 
 * 
 * @param _IOx 
 * @param _Mode 
 * @param _Speed 
 * @return int8_t 
 */
void IO_Init(uint8_t *_IOx, uint8_t _Mode, uint8_t _Speed);
/**
 * @brief 
 * 
 * @param _IOx 
 * @param _Para 0:单端口输入  1:组端口输入  2 单端口输出  3:组端口输出
 * @return uint32_t 
 */
uint32_t IO_Read(uint32_t _IOx,uint8_t _Para);
/**
 * @brief 
 * 
 * @param _IOx 
 * @param _Val 
 * @param _Para 0:单端口输入  1:组端口输入  2 单端口输出  3:组端口输出
 */
void IO_Write(uint32_t _IOx,uint32_t _Val,uint8_t _Para);
/**
 * @brief 
 * 
 * @param _IOx 
 * @param _CMD 
 * @param _Para 
 * @return uint32_t 
 */
int8_t IO_Ctrl(uint32_t _IOx, IOCmd _CMD,uint8_t _Para);

#endif // !__GPIO_H
