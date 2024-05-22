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

typedef struct
{
    int Src;
    int Dst;
    Status (*Send)(int _Src, int _Dst, void * _pBuf, int _Len);
    Status (*Recv)(int _Src, int _Dst, void * _pBuf, int _Len);
}Routin_Module;

Status Routin_Register(int _Src, int _Dst,
                       Status (*Sned)(int _Src, ...),
                       Status (*Recv)(int _Src, ...));

#endif // !__ROUTIN_MODULE

