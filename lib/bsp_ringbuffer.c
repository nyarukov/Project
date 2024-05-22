#include "bsp_ringbuffer.h"



unsigned char RingBuffer_Write(RingBuffer_t *_buffer, unsigned char *_pData,unsigned short _len)
{   
    if ((_buffer->lenght >= BUFFER_SIZE)||(_pData==NULL))
    {
        return 1;
    }
    while (_len--)
    {
        _buffer->buffer[_buffer->write] = *_pData++;;
        _buffer->write = (_buffer->write +1) % BUFFER_SIZE;
        _buffer->lenght++;
    }
    return 0;
}

unsigned char RingBuffer_Read(RingBuffer_t *_buffer, unsigned char *_pData,unsigned short _len)
{
    if ((_buffer->lenght==NULL)||(_buffer->buffer==NULL))
    {
        return 1;
    }
    while (_len--)
    {
        *_pData++ = _buffer->buffer[_buffer->read];
        _buffer->read = (_buffer->read +1) % BUFFER_SIZE;
        _buffer->lenght--;
    }
    return 0;
}

unsigned char IsRingBufferEmpty(RingBuffer_t *_buffer){
    return (_buffer->read==_buffer->write)?1:0;
}