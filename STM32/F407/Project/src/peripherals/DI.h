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

// clang-format off
#define DI_MODE         GPIO_Mode_IN
#define DI_OTYP         GPIO_OType_OD
#define DI_PUPD         GPIO_PuPd_UP

#define DI_Press_OK     (0x01)

#define DI_NUM          (3)

#define DI_GROUP        ((DI_NUM + 15) >> 4)

#define DI1             PE4
#define DI2             PE3
#define DI3             PE2

// clang-format on

typedef struct
{
    uint16_t DI_This[DI_GROUP];
    uint16_t DI_Last[DI_GROUP];
    void (*_DI_Callbacks)(uint16_t _Index);
} DI_PARA;

extern DI_PARA DI;

void DI_Init(void);
void DI_Read(void);

#endif
