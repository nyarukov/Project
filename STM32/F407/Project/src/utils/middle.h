/*
 * 项目名称: list
 * 版本:1.0
 * 作者: Yusaka
 * 创建日期: 2024-06-01
 * 最后修改日期: 2024-06-01 18:09:50
 * 描述: 链表
 */

/**
 * @file middle.h
 * @author yusaka (luckychaoyue1@gmail.com)
 * @brief
 * @version 1.0
 * @date 2024-06-01
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef __MIDDLE_H
#define __MIDDLE_H

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "def.h"
#include "lib.h"
#include "list.h"
#include "buffer.h"
#include "config.h"
#include "Routin_Module.h"
#include "stm32f4xx.h"
#include "stm32f4xx_it.h"
#include "systick.h"

#define ENABLE_INT() __set_PRIMASK(0)  /* 使能全局中断 */
#define DISABLE_INT() __set_PRIMASK(1) /* 禁止全局中断 */

#define __RCC_GPIOX_ENABLE(VAL) __SET_BIT((RCC->AHB1ENR), (1 << VAL))
#define __RCC_GPIOX_DISABLE(VAL) __CLEAR_BIT((RCC->AHB1ENR), (1 << VAL))

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
#define __IO_WRITE_AFR(REG, PIN, VAL) __SET_BIT((REG->AFR[1]), (VAL << ((PIN - 8) << 2)));
#else

#define __IO_WRITE_AFR(REG, PIN, VAL)                        \
    if (PIN < 7)                                             \
    {                                                        \
        __SET_BIT((REG->AFR[0]), (VAL << (PIN << 2)));       \
    }                                                        \
    else                                                     \
    {                                                        \
        __SET_BIT((REG->AFR[1]), (VAL << ((PIN - 8) << 2))); \
    }

#endif
/**
 * @brief 设置 GPIO 输出寄存器指定位
 * @param REG GPIOx
 * @param PIN 引脚号
 */
#define __IO_SET_BIT(REG, PIN) __SET_BIT((REG->BSRRL), (1 << PIN))

/**
 * @brief 复位 GPIO 输出寄存器指定位
 * @param REG GPIOx
 * @param PIN 引脚号
 */
#define __IO_RESET_BIT(REG, PIN) __SET_BIT((REG->BSRRH), (1 << PIN))

/**
 * @brief 读取 GPIO 输入寄存器指定位
 * @param REG GPIOx
 * @param PIN 引脚号
 */
#define __IO_READ_IN(REG, PIN) __CMP_REG(__READ_BIT((REG->IDR), (1 << PIN)), (1 << PIN))

/**
 * @brief 读取 GPIO 输出寄存器指定位
 * @param REG GPIOx
 * @param PIN 引脚号
 */
#define __IO_READ_OUT(REG, PIN) __CMP_REG(__READ_BIT((REG->ODR), (1 << PIN)), (1 << PIN))

#endif
