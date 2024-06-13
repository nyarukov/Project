#ifndef __BSP_FT5426_h
#define __BSP_FT5426_h

#include "bsp_softiic.h"
#include "bsp_uart.h"

#define FT5426_CMD_WR 				0X70    	//写命令
#define FT5426_CMD_RD 				0X71		//读命令

#define FT5426_DEVICE_MODE 				0X00		 /* 模式寄存器 */
#define FT5426_IDGLIB_VERSION1 			0XA1	 	 /* 固件版本寄存器 */
#define FT5426_IDGLIB_VERSION2 			0XA2	 	 /* 固件版本寄存器 */
#define FT5426_IDG_MODE 				   0XA4		 /* 中断模式 */
#define FT5426_TD_STATUS 				   0X02		 /* 触摸状态寄存器 */
#define FT5426_TOUCH1_XH 				   0X03		 /* 触摸点坐标寄存器 */


#define FT5426_INT      6
#define FT5426_RST      7

typedef enum {
   FT5426_Press_Down  =  0x00,       //按下
   FT5426_Lift_Up     =  0x01,       //抬起
   FT5426_Contact     =  0x02,       //接触
   FT5426_No_event    =  0x03,       //无事件
}ft5426_event;

typedef struct ft5426_struct
{
   u16 ID;
   u8  Pointx;
   u8  Event[5];
   u16 XPoint[5];
   u16 YPoint[5];
}bsp_ft5426_dev;

extern bsp_ft5426_dev ft5426_dev;

void FT5426_Init(void);
void FT5426_Send(uint8_t RegAddress, uint8_t Data);
uint8_t FT5426_Read(uint8_t RegAddress);
void FT5426_Reads(uint8_t RegAddress,uint8_t *pData,u8 len);

#endif // !__BSP_FT5426_h