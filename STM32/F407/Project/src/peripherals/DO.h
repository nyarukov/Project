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

#if DO_NUM > 0

typedef struct
{
    uint8_t DO_This[DO_GROUP];
    uint8_t DO_Last[DO_GROUP];
} DO_PARA;

extern DO_PARA DO;

void Init_DO(void);
void DO_Proc(void);

#endif
#endif
