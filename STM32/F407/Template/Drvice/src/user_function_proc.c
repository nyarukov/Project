#include "user_function_proc.h"

void User_Function_Proc(void)
{
    user_functions.Uart_Process_Function = Uart_Process_Function;
}