#ifndef __BSP_RINGBUFFER_H
#define __BSP_RINGBUFFER_H

#include <stdio.h>

#define BUFFER_SIZE 5
typedef struct{
    unsigned short write;
    unsigned short read;
    unsigned short lenght;
    unsigned char buffer[BUFFER_SIZE];
}RingBuffer_t;


unsigned char RingBuffer_Write(RingBuffer_t *_buffer, unsigned char *_pData,unsigned short _len);
unsigned char RingBuffer_Read(RingBuffer_t *_buffer, unsigned char *_pData,unsigned short _len);
unsigned char IsRingBufferEmpty(RingBuffer_t *_buffer);

#endif // !__BSP_RINGBUFFER_H