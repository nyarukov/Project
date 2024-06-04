/*
 * 项目名称: Struct_Para
 * 版本:1.0
 * 作者: Yusaka
 * 创建日期: 2024-06-04 00:18:18
 * 最后修改日期: 2024-06-04 00:18:18
 * 描述: 结构体参数定义
 */

#ifndef __STRUCT_PARA_H
#define __STRUCT_PARA_H

// 头文件内容...

#include "middle.h"
#include "DI.h"
#include "DO.h"

typedef struct Struct_Para
{
    int8_t a;
} USER_PARA;

extern USER_PARA UserPara;
#endif
