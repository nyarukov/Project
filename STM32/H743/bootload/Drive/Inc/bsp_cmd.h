#ifndef __BSP_CMD_H
#define __BSP_CMD_H

#include "bsp_control.h"
#include "string.h"
#include "bsp_uart.h"


typedef struct 
{
    const char *cmd_name;
    void (*cmd_function)(void);
}Command_t;

void Command_List(void);
void Register_Cmds(Command_t _cmdarr[], uint16_t _cmdlen);
void Match_Cmd(char *_cmdstr);


#endif // !__BSP_CMD_H
