#include "bsp_cmd.h"

#define Cmd_MAX 20

Command_t commands[Cmd_MAX];

uint16_t cmd_count;

/**
 * @brief ע������
 *
 * @param _cmds ��������
 * @param _len �������鳤��
 */
void Register_Cmds(Command_t _cmdarr[], uint16_t _cmdlen)
{
	uint8_t i;
	if (_cmdlen > Cmd_MAX)
	{
		// printf("�޷�ע������ﵽ�������������\n");
		return;
	}
	for (i = 0; i < _cmdlen; i++)
	{
		commands[cmd_count].cmd_name = _cmdarr[i].cmd_name;
		commands[cmd_count].cmd_function = _cmdarr[i].cmd_function;
		cmd_count++;
	}
}
/**
 * @brief ����ƥ��ִ�к���
 *
 * @param _cmdstr
 */
void Match_Cmd(char *_cmdstr)
{
	uint8_t i;
	for (i = 0; i < cmd_count; i++)
	{
		if (strcmp(commands[i].cmd_name, _cmdstr) == 0)
		{
			commands[i].cmd_function();
			memset(Uart1.Rxbuf, 0, sizeof(Uart1.Rxbuf));
			Uart1.RXFlag = 0;
			Uart1.RxCnt = 0;
		}
	}
}

/**
 * @brief ���������ע�������
 *
 */
void Print_Commands(void)
{
	uint8_t i;
	for (i = 0; i < cmd_count; i++)
	{
		printf("%d: %s\r\n", i, commands[i].cmd_name);
	}
}
/**
 * @brief ע�������б���ӡ��ע�������
 *
 */
void Command_List(void)
{
	Command_t List[] = {
		{"print", Print_Commands}};
	Register_Cmds(List, ARRAY_SIZE(List));
}
