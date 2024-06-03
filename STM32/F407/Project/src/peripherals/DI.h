/*
 * 项目名称: DI
 * 版本:1.0
 * 作者: Yusaka
 * 创建日期: 2024-06-03 23:10:38
 * 最后修改日期: 2024-06-03 23:10:38
 * 描述: DI驱动
 */

#ifndef __DI_H
#define __DI_H

// 头文件内容...

#include "gpio.h"
#include "Struct_Para.h"

// clang-format off
#define DI_NUM          (4)

#define DI_MODE         GPIO_Mode_IN
#define DI_OTYP         GPIO_OType_OD
#define DI_PUPD         GPIO_PuPd_UP

#define DI_COUNT        (4)


#define DI1             PA0
#define DI2             PA8
#define DI3             PB7
#define DI4             PC10
// clang-format on

void DI_Init(void);
void DI_Read(uint16_t *__DI_States);

#endif
