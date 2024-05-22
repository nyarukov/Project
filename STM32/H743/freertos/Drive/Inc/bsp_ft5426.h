#ifndef __BSP_FT5426_H
#define __BSP_FT5426_H

#include "bsp_uart.h"

#define I2C_MODE    0   //0软件，1硬件
#if I2C_MODE
    #include "bsp_hard_i2c.h"
#else
    #include "bsp_soft_i2c.h"
#endif

#if I2C_MODE
   #define  I2C_Init()                             Hard_I2C_Init()
   #define  I2C_Start()                            
   #define  I2C_Stop()                             
   #define  I2C_SendByte(_Byte)                    
   #define  I2C_SendACK(n)                         
   #define  I2C_ReceiveByte()                      
   #define  I2C_ReceiveACK(n)                      
#else
   #define  I2C_Init()                             Soft_I2C_Init()
   #define  I2C_Start()                            Soft_I2C_Start()
   #define  I2C_Stop()                             Soft_I2C_Stop()
   #define  I2C_SendByte(_Byte)                    Soft_I2C_SendByte(_Byte)    
   #define  I2C_SendACK(n)                         Soft_I2C_SendACK(n)
   #define  I2C_ReceiveByte()                      Soft_I2C_ReceiveByte()
   #define  I2C_ReceiveBytes(_pBuf,_len)           Soft_I2C_ReceiveBytes(_pBuf,_len)
   #define  I2C_ReceiveACK(n)                      Soft_I2C_ReceiveACK(n)
#endif


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
   uint16_t ID;
   uint8_t  Pointx;
   uint8_t  Event[5];
   uint16_t XPoint[5];
   uint16_t YPoint[5];
}bsp_ft5426_dev;

extern bsp_ft5426_dev ft5426_dev;

void FT5426_Init(void);
void FT5426_Send(uint8_t RegAddress, uint8_t Data);
uint8_t FT5426_Read(uint8_t RegAddress);
void FT5426_Reads(uint8_t RegAddress,uint8_t *pData,uint8_t len);

#endif // !__BSP_FT5426_h