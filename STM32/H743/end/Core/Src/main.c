#include "bsp.h"

int main(void)
{
	Bsp_Init();
	while (1)
	{
		Bsp_Loop();
	}
}
