#ifndef __BF_DEF_H
#define __BF_DEF_H

#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "stm32f4xx.h"
#include "user_function_proc.h"

#define ENABLE_INT()    __set_PRIMASK(0)  /* 使能全局中断 */
#define DISABLE_INT()   __set_PRIMASK(1) /* 禁止全局中断 */

/************************************************内存访问属性宏定义*******************************************************/
#define __I                             volatile const /* 只读属性 */
#define __O                             volatile       /* 只写属性 */
#define __IO                            volatile      /* 读写属性 */

/* Memory attributes for peripherals accessible through AXI or AHB interfaces */
#define __IM                            volatile const /* 只读属性 */
#define __OM                            volatile       /* 只写属性 */
#define __IOM                           volatile      /* 读写属性 */

/************************************************计算数组元素个数*******************************************************/
#define ARRAY_SIZE(x)                   (sizeof(x) / (sizeof((x)[0])))

/************************************************字符串操作*******************************************************/
#define CONCAT(a, b)                    a##b /* 合并两个标识符 */
#define STR(s)                          #s         /* 将参数转换为字符串 */

/************************************************值转换*******************************************************/
#define BMIN(a, b)                      ((a) < (b) ? (a) : (b)) /* 最小值宏定义 */
#define BMAX(a, b)                      ((a) > (b) ? (a) : (b)) /* 最大值宏定义 */
#define BABS(x)                         ((x) < 0 ? -(x) : (x))     /* 绝对值宏定义 */

/************************************************字节操作*******************************************************/
#define SWAP_BYTE(x)                    (((x) << 4) | ((x) >> 4)) /*字节交换*/
#define SWAP_UINT16(x)                  (((x) << 8) | ((x) >> 8)) /*16位整数字节交换*/
#define BEBufToUint16(byte1, byte2)     ((((byte1) & 0xFF) | ((uint16_t)byte2) << 8)) /*大端模式字节转换为16位整数*/
#define LEBufToUint16(byte1, byte2)     ((((uint16_t)byte1) << 8) | ((byte2) & 0xFF)) /*小端模式字节转换为16位整数*/
#define HIGH_BYTE(x)                    ((x) >> 8) /*保留16位高字节*/
#define LOW_BYTE(x)                     ((x) & 0xFF) /*保留16位低字节*/


/************************************************操作寄存器位宏定义*******************************************************/
#define __SET_BIT(REG, MASK)            ((REG) |= (MASK))    /* 设置寄存器指定位 */
#define __CLEAR_BIT(REG, MASK)          ((REG) &= ~(MASK))          /* 清除寄存器指定位 */
#define __READ_BIT(REG, MASK)           ((REG) & (MASK))    /* 读取寄存器指定位 */
#define __CLEAR_REG(REG)                ((REG) = (0x0))          /* 清除寄存器所有位 */
#define __WRITE_REG(REG, MASK)          ((REG) = (MASK))   /* 向寄存器写入值 */
#define __CMP_REG(REG, MASK)            ((REG) == (MASK))    /* 比较寄存器值 */
#define __MASK_BIT(DATA, MASK)          ((DATA) & ((1 << MASK)))      /*保留指定位*/

#define __RCC_GPIOX_ENABLE(VAL)         __SET_BIT((RCC->AHB1ENR), (1 << VAL))
#define __RCC_GPIOX_DISABLE(VAL)        __CLEAR_BIT((RCC->AHB1ENR), (1 << VAL))

/************************************************GPIO 操作宏定义*******************************************************/
/**
 * @brief 设置 GPIO 端口输出类型寄存器指定位
 * @param REG GPIOx
 * @param PIN 引脚号
 * @param VAL 值
 */
#define __IO_WRITE_MODE(REG, PIN, VAL) __SET_BIT((REG->MODER), (VAL << ((PIN << 1))))
/**
 * @brief 设置 GPIO 端口输出类型寄存器指定位
 * @param REG GPIOx
 * @param PIN 引脚号
 * @param VAL 值
 */
#define __IO_WRITE_OTYPE(REG, PIN, VAL) __SET_BIT((REG->OTYPER), (VAL << ((PIN << 1))))

/**
 * @brief 设置 GPIO 端口输出速度寄存器指定位
 * @param REG GPIOx
 * @param PIN 引脚号
 * @param VAL 值
 */
#define __IO_WRITE_SPEED(REG, PIN, VAL) __SET_BIT((REG->OSPEEDR), (VAL << ((PIN << 1))))

/**
 * @brief 设置 GPIO 端口上拉/下拉寄存器指定位
 * @param REG GPIOx
 * @param PIN 引脚号
 * @param VAL 值
 */
#define __IO_WRITE_PUPD(REG, PIN, VAL) __SET_BIT((REG->PUPDR), (VAL << ((PIN << 1))))

/**
 * @brief 设置 GPIO 复用功能
 * @param REG GPIOx
 * @param PIN 引脚号
 * @param VAL 值
 */
#if 0
#define __IO_WRITE_AFR(REG, PIN, VAL)   __SET_BIT((REG->AFR[1]), (VAL << ((PIN - 8) << 2)));
#else

#define __IO_WRITE_AFR(REG, PIN, VAL)                            \
    if (PIN < 7) {                                               \
        __SET_BIT((REG->AFR[0]), (VAL << (PIN << 2)));           \
    } else {                                                     \
        __SET_BIT((REG->AFR[1]), (VAL << ((PIN - 8) << 2)));     \
    }

#endif
/**
 * @brief 设置 GPIO 输出寄存器指定位
 * @param REG GPIOx
 * @param PIN 引脚号
 */
#define __IO_SET_BIT(REG, PIN)     __SET_BIT((REG->BSRRL), (1 << PIN))

/**
 * @brief 复位 GPIO 输出寄存器指定位
 * @param REG GPIOx
 * @param PIN 引脚号
 */
#define __IO_RESET_BIT(REG, PIN)     __SET_BIT((REG->BSRRH), (1 << PIN))

/**
 * @brief 读取 GPIO 输入寄存器指定位
 * @param REG GPIOx
 * @param PIN 引脚号
 */
#define __IO_READ_IN(REG, PIN)       __CMP_REG(__READ_BIT((REG->IDR), (1 << PIN)), (1 << PIN))

/**
 * @brief 读取 GPIO 输出寄存器指定位
 * @param REG GPIOx
 * @param PIN 引脚号
 */
#define __IO_READ_OUT(REG, PIN)       __CMP_REG(__READ_BIT((REG->ODR), (1 << PIN)), (1 << PIN))

typedef enum
{
    BF_OK = 0,            // 成功
    BF_FAILURE,           // 失败
    BF_ERROR,             // 错误
    BF_FULL,              // 满
    BF_EMPTY,             // 空
    BF_INVALID_PARAM,     // 无效的参数
    BF_NULL_POINTER,      // 空指针
    BF_INVALID_LENGTH,    // 无效长度
    BF_TOO_SMALL,         // 过小
    BF_TOO_LARGE,         // 过大
    BF_NOT_FOUND,         // 未找到
    BF_PERMISSION_DENIED, // 权限被拒绝
    BF_TIMEOUT,           // 超时
    BF_NOT_SUPPORTED,     // 不支持的操作
    BF_INTERRUPTED,       // 被中断
    BF_OUT_OF_MEMORY,     // 内存不足
    BF_NETWORK_ERROR,     // 网络错误
    BF_FILE_NOT_FOUND,    // 文件未找到
    BF_CORRUPT_DATA,      // 数据损坏
    BF_DUPLICATE_ENTRY    // 重复的条目
} Status;

#endif // !__BF_DEF_H
