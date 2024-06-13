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

#if DI_NUM > 0
// clang-format off

#define DI_Press_OK     (0x01)

// clang-format on

typedef struct
{
    uint8_t DI_This[DI_GROUP];
    uint8_t DI_Last[DI_GROUP];
    void (*_DI_Callbacks)(uint16_t _Index);
} DI_PARA;

extern DI_PARA DI;

void Init_DI(void);
void DI_Read(void);

#endif

#endif
