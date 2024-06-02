/*
 * 项目名称: systick
 * 版本:1.0
 * 作者: Yusaka
 * 创建日期: 2024-06-01
 * 最后修改日期: 2024-06-01 18:09:50
 * 描述: 滴答定时器驱动
 */

#ifndef __SYSTICK_H
#define __SYSTICK_H

// 头文件内容...

#include "middle.h"

void Delay_Us(uint32_t us);
void Delay_Ms(uint32_t ms);

#endif
