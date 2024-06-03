/*
 * 项目名称: DO
 * 版本:1.0
 * 作者: Yusaka
 * 创建日期: 2024-06-03 23:11:28
 * 最后修改日期: 2024-06-03 23:11:28
 * 描述: DO驱动
 */

#ifndef __DO_H
#define __DO_H

// 头文件内容...

#include "gpio.h"
#include "Struct_Para.h"

// clang-format off
#define DO_MODE     GPIO_Mode_OUT
#define DO_OTYP     GPIO_OType_PP
#define DO_SPEED    GPIO_Speed_50MHz

#define DO_NUM      (2) 
#define DO1         PA0
#define DO2         PA1
// clang-format on

#endif
