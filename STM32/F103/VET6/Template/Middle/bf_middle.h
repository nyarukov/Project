#ifndef __BF_MIDDLE_H
#define __BF_MIDDLE_H

#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

#include "bf_def.h"
#include "bf_lib.h"
#include "bf_list.h"
#include "bf_buffer.h"
#include "Routin_Module.h"

#include "stm32f10x.h"

#define ENABLE_INT()    __set_PRIMASK(0)    /* 使能全局中断 */
#define DISABLE_INT()   __set_PRIMASK(1)    /* 禁止全局中断 */

#define __RCC_GPIOX_ENABLE(VAL)         __SET_BIT((RCC->APB2ENR), (1 << (VAL + 0x2)))
#define __RCC_GPIOX_DISABLE(VAL)        __CLEAR_BIT((RCC->APB2ENR), (1 << (VAL + 0x2)))


/************************************************GPIO 操作宏定义*******************************************************/

/**
 * @brief 设置 GPIO 输出寄存器指定位
 * @param REG GPIOx
 * @param PIN 引脚号
 */
#define __IO_SET_BIT(REG, PIN)     __SET_BIT((REG->BSRR), (1 << PIN))

/**
 * @brief 复位 GPIO 输出寄存器指定位
 * @param REG GPIOx
 * @param PIN 引脚号
 */
#define __IO_RESET_BIT(REG, PIN)     __SET_BIT((REG->BRR), (1 << PIN))

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


#endif // !__BF_MIDDLE_H
