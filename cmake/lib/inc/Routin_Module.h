/**
 * @file Routin_Module.h
 * @author yusaka (luckychaoyue1@gmail.com)
 * @brief 
 * @version 1.0
 * @date 2024-05-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef __ROUTIN_MODULE
#define __ROUTIN_MODULE

#include "bf_middle.h"

#define  _LOG_Routin(fmt, ...)    printf(fmt, __VA_ARGS__)

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

#endif // !__ROUTIN_MODULE

