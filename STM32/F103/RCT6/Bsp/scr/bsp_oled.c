#include "bsp_oled.h"
#include "oled_font.h"
#include "math.h"
#include <stdlib.h>
uint8_t OLED_GRAM[128][8];

void OLED_Refresh_Gram(void)
{
	u8 i,n;		    
	for(i=0;i<8;i++)  
	{
		//仅对页寻址有效
		OLED_WR_Byte (0xb0+i,OLED_CMD);    //设置页地址（0~7）
		OLED_WR_Byte (0x02,OLED_CMD);      //设置显示位置—列低地址(0x00-0x0F)
		OLED_WR_Byte (0x10,OLED_CMD);      //设置显示位置—列高地址(0x10-0x1F) 
		for(n=0;n<128;n++)OLED_WR_Byte(OLED_GRAM[n][i],OLED_DATA); 
	}   
}

// 向SSD1306写入一个字节。
// dat:要写入的数据/命令
// cmd:数据/命令标志 0,表示命令;1,表示数据;
void OLED_WR_Byte(u8 dat, u8 cmd)
{
    OLED_DC(cmd);
    Soft_SPI_Transmit(dat);
    OLED_DC(1);
}
  
//开启OLED显示    
void OLED_Display_On(void)
{
	OLED_WR_Byte(0X8D,OLED_CMD);  //SET DCDC命令
	OLED_WR_Byte(0X14,OLED_CMD);  //DCDC ON
	OLED_WR_Byte(0XAF,OLED_CMD);  //DISPLAY ON
}
//关闭OLED显示     
void OLED_Display_Off(void)
{
	OLED_WR_Byte(0X8D,OLED_CMD);  //SET DCDC命令
	OLED_WR_Byte(0X10,OLED_CMD);  //DCDC OFF
	OLED_WR_Byte(0XAE,OLED_CMD);  //DISPLAY OFF
}		   			 
//清屏函数,清完屏,整个屏幕是黑色的!和没点亮一样!!!	  
void OLED_Clear(void)  
{  
	u8 i,n;  
	for(i=0;i<8;i++)
	{
		for(n=0;n<128;n++)
		{
			OLED_GRAM[n][i]=0X00;  
		}
	}
	OLED_Refresh_Gram();//更新显示
}
//画点 
//x:0~127
//y:0~63
//t:1 填充 0,清空				   
void OLED_DrawPoint(int x,int y,u8 t)
{
	u8 pos,bx,temp=0;
	if(x<0 || x>127 || y<0 || y>63)return;//超出范围了.
	pos=7-y/8;
	bx=y%8;
	temp=1<<(7-bx);
	if(t)OLED_GRAM[x][pos]|=temp;
	else OLED_GRAM[x][pos]&=~temp;
}

//显示汉字
void OLED_ShowCH(u8 x,u8 y,u8 chr,u8 size,u8 mode)
{
	u8 temp,t,t1;
	u8 y0=y;
	  
  for(t=0;t<size;t++)
  {
		if(size==16)
			temp=oled_CH_1616[chr][t];		 //调用中文字库
		else
			temp=oled_CH_1212[chr][t];
		for(t1=0;t1<8;t1++)
		{
			if(temp&0x80)OLED_DrawPoint(x,y,mode);
			else OLED_DrawPoint(x,y,!mode);
			temp<<=1;
			y++;
			if((y-y0)==size)
			{
				y=y0;
				x++;
				break;
			}
		}
  }          
}

//显示单个中文字符
void OLED_Show_CH(u8 x,u8 y,u8 chr,u8 size,u8 mode)
{
	OLED_ShowCH(x,y,chr*2,size,1);OLED_ShowCH(x+size/2,y,chr*2+1,size,1);
}

//在字库里找字，低位，高位，大小
u8 OLED_findoneCN(u8 ch1,u8 ch2,u8 size)
{
	u8 j=0;
	if(size==12)
	{
		while(character12[j]!='\0')
		{
			if(ch1==character12[j]&&ch2==character12[j+1])
				return j/2+1;
			j+=2;
		}
	}
	else
		while(character16[j]!='\0')
		{
			if(ch1==character16[j]&&ch2==character16[j+1])
				return j/2+1;
			j+=2;
		}
		
	return 0;
}

void OLED_Show_chString(u8 x, u8 y,u8 ch[],u8 size)
{
	int j=0,k;	
	while(ch[j] != '\0')
	{
		if(ch[j]>0x80)//汉字
		{
			k=OLED_findoneCN(ch[j],ch[j+1],size);
			if(k!=0)OLED_Show_CH(j*size/2+x,y,k-1,size,1);
			j+=2;		
		}
		else//ASCLL
		{
			OLED_ShowChar(j*size/2+x,y,ch[j],size,1);
			j++;
		}		
	}
}

//显示一串中文字符
void OLED_Show_MY_String(u8 x,u8 y,const u8 *p,u8 size,u8 mode)
{
	u8 temp,t,t1;
	u8 y0=y;
	
	for(t=0;t<size;t++)
	{
		temp=p[t];		 //调用中文字库                          
		for(t1=0;t1<8;t1++)
		{
			if(temp&0x80)OLED_DrawPoint(x,y,mode);
			else OLED_DrawPoint(x,y,!mode);
			temp<<=1;
			y++;
			if((y-y0)==size)
			{
				y=y0;
				x++;
				break;
			}
		}
	}
}

void chString1(void)
{
	for(u8 i=0;i<12;i++) OLED_Show_MY_String(30+6*i,30,oled_CH1[i],12,1);
}


//m^n函数
u32 oled_pow(u8 m,u8 n)
{
	u32 result=1;	 
	while(n--)result*=m;    
	return result;
}

/**
 * @brief 显示数字
 *
 * @param x 起点坐标
 * @param y 起点坐标
 * @param num 数值(0~4294967295);
 * @param len 数字的位数
 * @param size 字体大小
 */
void OLED_ShowNumber(u8 x,u8 y,u32 num,u8 len,u8 size)
{         	
	u8 t,temp;
	u8 enshow=0;						   
	for(t=0;t<len;t++)
	{
		temp=(num/oled_pow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				OLED_ShowChar(x+(size/2)*t,y,' ',size,1);
				continue;
			}else enshow=1; 
		 	 
		}
	 	OLED_ShowChar(x+(size/2)*t,y,temp+'0',size,1); 
	}
}

//显示数字
//x,y :起点坐标
//num :要显示的小数字
//z_len :整数数字的位数
//f_len :小数数字的位数
void OLED_Showdecimalchar(u8 x,u8 y,float num,u8 z_len,u8 f_len)
{
	u8 t,temp,flag=0;
	u8 enshow=0;
	int z_temp,f_temp;      
	z_temp = num;
	//整数部分
	for(t=0;t<z_len;t++)
	{
		z_temp =abs(z_temp);
		temp=(z_temp/oled_pow(10,z_len-t-1))%10;
		if(enshow==0 && t<(z_len-1))
		{
			if(temp==0)
			{
				OLED_ShowChar(x+t*8,y,' ',16,1);
				continue;
			}
			else
			  enshow=1;
		}
		if(num < 0 && flag == 0)
			{OLED_ShowChar(x+(t-1)*8,y,'-',16,1);flag=1;}
		//if(fabs(num) < oled_pow(10,z_len-1))
			//OLED_ShowChar((t-1)*8,y,' ',16,1);
		OLED_ShowChar(x+t*8,y,temp+'0',16,1); 
	}
	//小数点
	OLED_ShowChar(x+z_len*8,y,'.',16,1); 
	num =fabs(num);
	f_temp=(int)((num-z_temp)*(oled_pow(10,f_len)));
  //小数部分
	for(t=0;t<f_len;t++)
	{
		temp=(f_temp/oled_pow(10,f_len-t-1))%10;
		OLED_ShowChar(x+(t+z_len+1)*8,y,temp+'0',16,1); 
	}
}

//在指定位置显示一个字符,包括部分字符
//x:0~127
//y:0~63
//mode:0,反白显示;1,正常显示				 
//size:选择字体 16/12 
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 size,u8 mode)
{      			    
	u8 temp,t,t1;
	u8 y0=y;
	chr=chr-' ';//得到偏移后的值				   
  for(t=0;t<size;t++)
  {
		if(size==12)temp=oled_asc2_1206[chr][t];  //调用1206字体
		else temp=oled_asc2_1608[chr][t];		 //调用1608字体 	                          
    for(t1=0;t1<8;t1++)
		{
			if(temp&0x80) OLED_DrawPoint(x,y,mode);
			else OLED_DrawPoint(x,y,!mode);
			temp<<=1;
			y++;
			if((y-y0)==size)
			{
				y=y0;
				x++;
				break;
			}
		}
  }
}


/**
 * @brief 显示字符串
 *
 * @param x 显示字符串
 * @param y 显示字符串
 * @param p 字符串起始地址
 * @param size 字体大小
 * @param mode 显示i模式
 */
void OLED_ShowString(u8 x,u8 y,char *p,u8 size,u8 mode)
{
#define MAX_CHAR_POSX 122
#define MAX_CHAR_POSY 58          
  while(*p!='\0')
  {       
    if(x>MAX_CHAR_POSX){x=0;y+=16;}//换行
    if(y>MAX_CHAR_POSY){y=x=0;OLED_Clear();}
    OLED_ShowChar(x,y,*p,size,mode);	 
    x+=8;
    p++;
  }  
}

//画线，起始坐标x y，长度，1向右 2向下
void line(u8 x,u8 y,u8 length,u8 mode)
{
	if(mode == 1)
		for(u8 x1=x;x1<x+length;x1++)
			OLED_DrawPoint(x1,y,1);
	else
		for(u8 y1=y;y1<y+length;y1++)
			OLED_DrawPoint(x,y1,1);
}

//一次函数，2点坐标画线
void drawline(float x1,float y1,float x2,float y2)
{
	u8 y;
	if(x1==x2)
		if(y1<y2)
			for(u8 i=y1;i<y2;i++)
				OLED_DrawPoint(x1,i,1);
		else
			for(u8 i=y1;i>y2;i--)
				OLED_DrawPoint(x1,i,1);
	else
		if(x1<x2)
			for(u8 x=x1;x<x2;x++)
			{
				y=(y2-y1)/(x2-x1)*x+y1-(y2-y1)/(x2-x1)*x1;
				OLED_DrawPoint(x,y,1);
			}
		else
			for(u8 x=x1;x>x2;x--)
			{
				y=(y2-y1)/(x2-x1)*x+y1-(y2-y1)/(x2-x1)*x1;
				OLED_DrawPoint(x,y,1);
			}
}

void OLED_DrawLine(int x0, int y0, int x1, int y1)
{
  int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
  int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
  int erro = (dx > dy ? dx : -dy) / 2;
  while(OLED_DrawPoint(x0,y0,1), x0 != x1 || y0 != y1)
	{
      int e2 = erro;
      if(e2 > -dx) { erro -= dy; x0 += sx;}
      if(e2 <  dy) { erro += dx; y0 += sy;}
  } 
}
void OLED_ClearLine(int x0, int y0, int x1, int y1)
{
	int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
	int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
	int erro = (dx > dy ? dx : -dy) / 2;
	while (x0 != x1 || y0 != y1)
	{
		OLED_DrawPoint(x0, y0, 0); // 清空像素点
		int e2 = erro;
		if (e2 > -dx)
		{
			erro -= dy;
			x0 += sx;
		}
		if (e2 < dy)
		{
			erro += dx;
			y0 += sy;
		}
	}
}

void OLED_DrawSolidBox(int x0, int y0, int x1, int y1)
{
	// Draw horizontal lines to fill the box
	for (int y = y0 + 1; y < y1; y++)
	{
		OLED_DrawLine(x0, y, x1, y);
	}
}

void OLED_ClearSolidBox(int x0, int y0, int x1, int y1)
{
	// Draw horizontal lines to fill the box
	for (int y = y0 + 1; y < y1; y++)
	{
		OLED_ClearLine(x0, y, x1, y);
	}
}

//空心圆
void circle(int x,int y,u8 r)
{
	int x1,y1,a=0;
	float c;
	for(c=0.f;c<2*3.14f;c+=0.04f)
	{
		if(a==0)
		{
			x1=x+r*cos(c)-1; y1=y+r*sin(c);
			OLED_DrawPoint(x1,y1,1);
			a++;
		}
		else
		{
			x1=x+r*cos(c); y1=y+r*sin(c);
			OLED_DrawPoint(x1,y1,1);
		}
	}
}

void OLED_DrawCircle(int x0,int y0,u8 r)
{
	int8_t x = r;
	int8_t y = 0;
	int8_t err = 0;
	while (x >= y)
	{
		OLED_DrawPoint(x0 + x, y0 + y,1);
		OLED_DrawPoint(x0 - x, y0 + y,1);
		OLED_DrawPoint(x0 + x, y0 - y,1);
		OLED_DrawPoint(x0 - x, y0 - y,1);
		OLED_DrawPoint(x0 + y, y0 + x,1);
		OLED_DrawPoint(x0 - y, y0 + x,1);
		OLED_DrawPoint(x0 + y, y0 - x,1);
		OLED_DrawPoint(x0 - y, y0 - x,1);
		if (err <= 0)
		{
			y++;
			err += 2*y+1;
		}
		if (err > 0)
		{
			x--;
			err -= 2*x+1;
		}
	}
}

void OLED_DrawCircle2(u8 x0,u8 y0,u8 r)
{
	int x = 0, y = r,d;
	d = 3- 2*r;
	while (x <= y) 
	{
		OLED_DrawPoint(x0+x,y0+y,1);
		OLED_DrawPoint(x0-x,y0+y,1);
		OLED_DrawPoint(x0+x,y0-y,1);
		OLED_DrawPoint(x0-x,y0-y,1);
		OLED_DrawPoint(x0+y,y0+x,1);
		OLED_DrawPoint(x0-y,y0+x,1);
		OLED_DrawPoint(x0+y,y0-x,1);
		OLED_DrawPoint(x0-y,y0-x,1);
		if (d < 0)
			d = d+4*x+6;
		else 
		{
			d = d+4*(x-y)+10;
			y--;
		}
		x++;
	}
}

void OLED_DrawFullCircle(u8 x0,u8 y0,u8 r)
{
	int x = 0, y = r,yi,d;
	d = 3- 2*r;
	while (x <= y) 
		{
			for (yi = x; yi <= y; yi ++)
			{
				OLED_DrawPoint(x0+x,y0+yi,1);
				OLED_DrawPoint(x0-x,y0+yi,1);
				OLED_DrawPoint(x0+x,y0-yi,1);
				OLED_DrawPoint(x0-x,y0-yi,1);
				OLED_DrawPoint(x0+yi,y0+x,1);
				OLED_DrawPoint(x0-yi,y0+x,1);
				OLED_DrawPoint(x0+yi,y0-x,1);
				OLED_DrawPoint(x0-yi,y0-x,1);
			}
			if (d < 0)
				d = d + 4 * x + 6;
			else 
			{
				d = d + 4 * (x - y) + 10;
				y --;
			}
			x ++;
		}
}

//空心椭圆，中点坐标xy，长半轴，短半轴，顺时针旋转角度
void ellipse(int x,int y,uint8_t major_semi_axis,uint8_t minor_semi_axis,float t)
{
	int x1,y1;
	uint8_t a=major_semi_axis,b=minor_semi_axis;
	float c;
	t=t*0.01745f;
	for(c=0.f;c<2*3.14f;c+=0.04f)
	{
		x1=x+a*cos(c)*cos(t)-b*sin(c)*sin(t);
		y1=y+b*sin(c)*cos(t)+a*cos(c)*sin(t);
		OLED_DrawPoint(x1,y1,1);
	}
}

//xy中心坐标
void OLED_DrawRect(u8 x, u8 y,u8 length,u8 high)
{
	line(x-length/2,y-high/2,length,1);
	line(x-length/2,y+high/2-1,length,1);
	line(x-length/2,y-high/2,high,2);
	line(x+length/2,y-high/2,high,2);
}

// 1/4圆弧
// 角名 1  2
//      3  4
void DrawCircleHelper(int x0,int y0,u8 r,u8 cornername)
{
	int x = 0, y = r,d;
	d = 3- 2*r;
	while (x <= y) 
	{
		if(cornername==1)
		{
			OLED_DrawPoint(x0-x,y0-y,1);
			OLED_DrawPoint(x0-y,y0-x,1);
		}
		else if(cornername==2)
		{
			OLED_DrawPoint(x0+x,y0-y,1);
			OLED_DrawPoint(x0+y,y0-x,1);
		}
		else if(cornername==3)
		{
			OLED_DrawPoint(x0-x,y0+y,1);
			OLED_DrawPoint(x0-y,y0+x,1);
		}
		else if(cornername==4)
		{
			OLED_DrawPoint(x0+x,y0+y,1);
			OLED_DrawPoint(x0+y,y0+x,1);
		}
		if (d < 0)
			d = d+4*x+6;
		else 
		{
			d = d+4*(x-y)+10;
			y--;
		}
		x++;
	}
}

void OLED_DrawRoundRect(u8 x, u8 y,u8 length,u8 high,u8 r)
{
	if(2*r>length || 2*r>high) {OLED_ShowString(x,y,"error",12,1);return;}
	line(x+r,y,length-2*r,1);
  line(x+r,y+high-1,length-2*r,1);
  line(x,y+r,high-2*r,2);
  line(x+length-1,y+r,high-2*r,2);

  DrawCircleHelper(x+r,y+r,r,1);
  DrawCircleHelper(x+length-r-1,y+r,r,2);
	DrawCircleHelper(x+r,y+high-r-1,r,3);
  DrawCircleHelper(x+length-r-1,y+high-r-1,r,4);
}

//向右进度条，左上角起始坐标x y，长度，宽度，变量 (变量最大值要和长度相等)
void progress_right(u8 x,u8 y,u8 length,u8 width,u8 value)
{
	for(u8 x1=x;x1<x+length;x1++)
	{
		while(x1<x+value)
		{
			for(u8 y1=y;y1<y+width;y1++)
				OLED_DrawPoint(x1,y1,1);
			x1++;
		}
		for(u8 y1=y;y1<y+width;y1++)
			OLED_DrawPoint(x1,y1,0);
	}
}

//向上进度条，左下角起始坐标
void progress_up(u8 x,u8 y,u8 length,u8 width,u8 value)
{
	for(u8 y1=y;y1>y-length;y1--)
	{
		while(y1>y-value)
		{
			for(u8 x1=x;x1<x+width;x1++)
				OLED_DrawPoint(x1,y1,1);
			y1--;
		}
		for(u8 x1=x;x1<x+width;x1++)
			OLED_DrawPoint(x1,y1,0);
	}
}

void OLED_ShowBMP(const uint8_t BMP[])
{
	uint8_t temp;
	u16 i=0;
		for(u8 y1=0;y1<8;y1++)
		{
			for(u8 x=0;x<128;x++)
			{
				temp=BMP[i];
				i++;
				for(u8 y=8*y1;y<8*y1+8;y++)
				{
					if(temp&0x80)OLED_DrawPoint(x,y,1);
					else OLED_DrawPoint(x,y,0);
					temp<<=1;
				}
			}
		}
}

void oled_test(void)
{
	line(0,16,127,1);
	line(0,48,127,1);
	OLED_DrawLine(0,0,64,32);
	OLED_DrawLine(40,10,64,32);
	OLED_DrawLine(64,0,64,32);
	OLED_DrawLine(88,10,64,32);
	OLED_DrawLine(128,0,64,32);
	OLED_DrawLine(0,32,128,32);
	OLED_DrawLine(50,64,64,32);
	OLED_DrawLine(78,64,64,32);
	circle(24,32,15);
	OLED_DrawCircle(64,32,15);
	OLED_DrawCircle2(104,32,15);
	OLED_Refresh_Gram();
}

void OLED_setrolll(void)
{
  //以下添加水平滚动效果
  OLED_WR_Byte(0x2E,OLED_CMD);//关滚动
	
  OLED_WR_Byte(0x27,OLED_CMD);//26向右，27向左
  OLED_WR_Byte(0x00,OLED_CMD);//空字节
	
  OLED_WR_Byte(0x02,OLED_CMD);//水平起始页 (0x00-0x07) 从下往上数
  OLED_WR_Byte(0x07,OLED_CMD);//水平滚动速度(0x00-0x07)速度7>4>5>0>6>1>2>3
  OLED_WR_Byte(0x03,OLED_CMD);//水平结束页 (要比起始页大) 从上往下数
	
  OLED_WR_Byte(0x00,OLED_CMD);
	OLED_WR_Byte(0xFF,OLED_CMD);
}

void OLED_setroll(void)
{
  //以下添加水平与垂直滚动效果
  OLED_WR_Byte(0x2E,OLED_CMD);//关滚动
	
	OLED_WR_Byte(0xA3,OLED_CMD);//垂直滚动行区域
	OLED_WR_Byte(0x00,OLED_CMD);//起始，从下往上数
	OLED_WR_Byte(0x20,OLED_CMD);//终止，起始+终止
	
  OLED_WR_Byte(0x29,OLED_CMD);//29向右，2a向左
  OLED_WR_Byte(0x01,OLED_CMD);//开关水平滚动
	
  OLED_WR_Byte(0x02,OLED_CMD);//水平起始页 (0x00-0x07) 从下往上数
  OLED_WR_Byte(0x05,OLED_CMD);//滚动速度(0x00-0x07)速度7>4>5>0>6>1>2>3
  OLED_WR_Byte(0x03,OLED_CMD);//水平结束页 (要比起始页大) 从下往上数
	
  OLED_WR_Byte(0x00,OLED_CMD);//每次垂直滚动位移，反着就是终止-起始-1
	
	OLED_WR_Byte(0x00,OLED_CMD);//水平起始列 (0x00-0x7F) 从左往右数
	OLED_WR_Byte(0x5A,OLED_CMD);//水平结束列 (0x00-0x7F) 从左往右数
}

void OLED_roll(u8 i)
{
	if(i)
    OLED_WR_Byte(0x2F,OLED_CMD);//开滚动
	else
		OLED_WR_Byte(0x2E,OLED_CMD);//关滚动
}


// 初始化SSD1306
void OLED_Init(void)
{
    Soft_SPI_Init();

    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_12;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    OLED_DC(1);

    OLED_RS(0);
    Delay_ms(100);
    OLED_RS(1);

	//设引脚所在方向为上
	OLED_WR_Byte(0xAE,OLED_CMD);//关屏
	OLED_WR_Byte(0x00,OLED_CMD);//列起始地址低位
	OLED_WR_Byte(0x10,OLED_CMD);//列起始地址高位
	
	OLED_WR_Byte(0x20,OLED_CMD);//开始设置地址模式
	OLED_WR_Byte(0x02,OLED_CMD);//水平寻址，垂直寻址，页寻址(0x00/0x01/0x02)
	
	OLED_WR_Byte(0x40,OLED_CMD);//屏幕起始行，效果为画面往下偏移 (0x40~0x7F)
	
	OLED_WR_Byte(0x81,OLED_CMD);//开始设置对比度，亮度
	OLED_WR_Byte(0xD0,OLED_CMD);//0x00-0xFF
	
	OLED_WR_Byte(0xA1,OLED_CMD);//行输出反置，只影响后续输入的数据     0xA0左右反置 0xA1正常
	OLED_WR_Byte(0xA4,OLED_CMD);//0xA4正常 0xA5全亮
	OLED_WR_Byte(0xA6,OLED_CMD);//0xA6正常 0xA7亮灭反转
	
	OLED_WR_Byte(0xA8,OLED_CMD);//多路复用比例，效果为从第几行开始显示
	OLED_WR_Byte(0x3f,OLED_CMD);//默认63(0 to 63)
	
	OLED_WR_Byte(0xC0,OLED_CMD);//列输出反置，立即生效                0xC8上下反置 0xC0正常
	
	OLED_WR_Byte(0xD3,OLED_CMD);//画面偏置，效果为画面往下偏移
	OLED_WR_Byte(0x00,OLED_CMD);//0x00~0x3F
	
	OLED_WR_Byte(0xd5,OLED_CMD);//显示时钟分频比/振荡器频率
	OLED_WR_Byte(0x80,OLED_CMD);//--set divide ratio, Set Clock as 100 Frames/Sec
	OLED_WR_Byte(0xD9,OLED_CMD);//--set pre-charge period
	OLED_WR_Byte(0xF1,OLED_CMD);//Set Pre-Charge as 15 Clocks & Discharge as 1 Clock
	OLED_WR_Byte(0xDA,OLED_CMD);//--set com pins hardware configuration
	OLED_WR_Byte(0x12,OLED_CMD);
	OLED_WR_Byte(0xDB,OLED_CMD);//--set vcomh
	OLED_WR_Byte(0x30,OLED_CMD);//Set VCOM Deselect Level
	OLED_WR_Byte(0x8D,OLED_CMD);//--set Charge Pump enable/disable
	OLED_WR_Byte(0x14,OLED_CMD);//--set(0x10) disable
	/*
	//设置起始、终止列地址，仅对水平、垂直寻址有效 (0x00-0x7f)128列
	OLED_WR_Byte(0x21,OLED_CMD);
	OLED_WR_Byte(0x00,OLED_CMD);//起始列地址
	OLED_WR_Byte(0x00,OLED_CMD);//终止列地址
	//设置起始、终止页地址，仅对水平、垂直寻址有效 (0x00-0x07)8页
	OLED_WR_Byte(0x22,OLED_CMD);
	OLED_WR_Byte(0x00,OLED_CMD);//起始页地址
	OLED_WR_Byte(0x00,OLED_CMD);//终止页地址
	*/
	OLED_Clear();
	OLED_WR_Byte(0xAF,OLED_CMD);//开屏
}
