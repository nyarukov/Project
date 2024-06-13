#ifndef __BF_LIB_H
#define __BF_LIB_H

#include "bf_middle.h"

int32_t str_len(char *_str);
void str_cpy(char *_tar, char *_src);
int32_t str_cmp(char *s1, char *s2);

void mem_set(void *_ptr, int32_t _value, int32_t _len);
void mem_cpy(void *_dest, const void *_src, int32_t _len);

uint16_t Check_CRC8(uint8_t *buf, uint16_t len);
uint16_t Check_Modbus_CRC16(uint8_t *buf, uint16_t len);
uint16_t Check_Xmodeme_CRC16(uint8_t *buf, uint16_t len);
uint16_t Check_Ymodeme_CRC16(uint8_t *buf, uint16_t len);




#endif // !__BF_LIB_H
