/*
 * 项目名称: Data_Proc
 * 版本:1.0
 * 作者: Yusaka
 * 创建日期: 2024-06-08 10:36:22
 * 最后修改日期: 2024-06-08 10:36:22
 * 描述: 中间数据处理
 */

#ifndef __DATA_PROC_H
#define __DATA_PROC_H

// 头文件内容...
#include "middle.h"
#include "uart.h"
void Com_DataProc(void);
void COM1_Proc(uint8_t *_pBuf, uint32_t _Len);
void COM2_Proc(uint8_t *_pBuf, uint32_t _Len);
void COM3_Proc(uint8_t *_pBuf, uint32_t _Len);
void COM4_Proc(uint8_t *_pBuf, uint32_t _Len);
void COM5_Proc(uint8_t *_pBuf, uint32_t _Len);
void COM6_Proc(uint8_t *_pBuf, uint32_t _Len);
void COM7_Proc(uint8_t *_pBuf, uint32_t _Len);
void COM8_Proc(uint8_t *_pBuf, uint32_t _Len);
#endif
