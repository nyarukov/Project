/*
 * ��Ŀ����: Struct_Para
 * �汾:1.0
 * ����: Yusaka
 * ��������: 2024-06-04 00:18:18
 * ����޸�����: 2024-06-04 00:18:18
 * ����: �ṹ���������
 */

#ifndef __STRUCT_PARA_H
#define __STRUCT_PARA_H

// ͷ�ļ�����...

#include "middle.h"
#include "DI.h"

typedef struct Struct_Para
{
    uint16_t DI_Value[(DI_NUM + 15) >> 4];
} USER_PARA;

extern USER_PARA UserPara;
#endif
