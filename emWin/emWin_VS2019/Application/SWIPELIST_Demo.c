#include "GUI.h"
int i;
char acText[] = "This example demonstrates text wrapping";
GUI_RECT Rect = { 10, 10, 59, 59 };
GUI_WRAPMODE aWm[] = { GUI_WRAPMODE_NONE,
GUI_WRAPMODE_CHAR,
GUI_WRAPMODE_WORD };

void MainTask(void) {
	GUI_Init();
	
	//GUI_SetBkColor(GUI_BLUE);
	//GUI_Clear();
	//GUI_SetFont(&GUI_Font8x16);
	//GUI_DispString("GUI_DispStringe");
	//GUI_DispStringAt("GUI_DispStringAt",20,100);
	//GUI_DispStringHCenterAt("GUI_DispStringHCenterAt",300,50);
	//GUI_RECT rClient;
	//GUI_GetClientRect(&rClient);
	//GUI_DispStringInRect("GUI_DispStringInRect", &rClient, GUI_TA_HCENTER | GUI_TA_VCENTER);
	//

	GUI_SetTextMode(GUI_TM_TRANS);
	for (i = 0; i < 3; i++)
	{
		GUI_SetColor(GUI_BLUE);
		GUI_FillRectEx(&Rect);

		GUI_SetColor(GUI_WHITE);

		GUI_DispStringInRectWrap(acText, &Rect,GUI_TA_LEFT, aWm[i]);
		Rect.x0 += 60;
		Rect.x1 += 60;
	}


	while (1)
	{
		GUI_Delay(10);
	}
}