/*
 * 项目名称: lib
 * 版本:1.0
 * 作者: Yusaka
 * 创建日期: 2024-06-01
 * 最后修改日期: 2024-06-01 18:09:50
 * 描述: 常用lib库
 */

#ifndef __LIB_H
#define __LIB_H

// 头文件内容...

#include "middle.h"

int str_len(char *_str);
void str_cpy(char *_tar, char *_src);
int str_cmp(char *s1, char *s2);

void mem_set(void *_ptr, int _value, int _len);
void mem_cpy(void *_dest, const void *_src, int _len);

uint16_t Check_CRC8(uint8_t *buf, uint16_t len);
uint16_t Check_Modbus_CRC16(uint8_t *buf, uint16_t len);
uint16_t Check_Xmodeme_CRC16(uint8_t *buf, uint16_t len);
uint16_t Check_Ymodeme_CRC16(uint8_t *buf, uint16_t len);

#endif
