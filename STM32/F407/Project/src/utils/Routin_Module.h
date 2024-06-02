/*
 * ��Ŀ����: Routin_Module
 * �汾:1.0
 * ����: Yusaka
 * ��������: 2024-06-01 18:26:19
 * ����޸�����: 2024-06-01 18:26:19
 * ����: ·��ģ��
 */

#ifndef __ROUTIN_MODULE_H
#define __ROUTIN_MODULE_H

// ͷ�ļ�����...

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
