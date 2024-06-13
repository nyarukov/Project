#ifndef __USER_FUNCTIONS_H
#define __USER_FUNCTIONS_H

#include "bf_lib.h"
#include "bsp_uart.h"
#include "uart_proc.h"

typedef struct
{
    void (*Uart_Process_Function)(uint8_t _Id, uint8_t *_pBuf, uint32_t _Len);
} User_Functions;

extern User_Functions user_functions;

void User_Function_Proc(void);

#endif /* __USER_FUNCTIONS_H */
