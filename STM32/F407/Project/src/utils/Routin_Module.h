/*
 * 项目名称: Routin_Module
 * 版本:1.0
 * 作者: Yusaka
 * 创建日期: 2024-06-01 18:26:19
 * 最后修改日期: 2024-06-01 18:26:19
 * 描述: 路由模块
 */

#ifndef __ROUTIN_MODULE_H
#define __ROUTIN_MODULE_H

// 头文件内容...

#include "middle.h"

typedef struct
{
    int ID;
    Status (*Send)(int _Src, int _Dst, void * _pBuf, int _Len);
    Status (*Recv)(int _Src, int _Dst, void * _pBuf, int _Len);
}Routin_Module;

Status Routin_Register(int _ID, Status (*_Recv)(int, int, void*, int));
Status Route_Forward(int _Src, int _Dst, void * _pBuf, int _Len);
Status Routin_ID_Cancle(int _ID);
Status Routin_ALL_Cancle(void);
void Routin_Foreach(void);
#endif
