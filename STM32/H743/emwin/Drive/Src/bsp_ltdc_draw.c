#include "bsp_ltdc_draw.h"

static u32 index(u16 x, u16 y);

/**
 * @brief 在指定坐标(x, y)处绘制一个点
 * 
 * @param x x坐标
 * @param y y坐标
 * @param color 绘制的颜色
 */
void LCD_DrawPoint(u16 x, u16 y, u16 color)
{
    *(SDRAM_LCD_BUF1+index(x, y)) = color;
}

/**
 * @brief 读取指定坐标(x, y)处的颜色值
 * 
 * @param x x坐标
 * @param y y坐标
 * @return u16 该点的颜色值
 */
u16 LCD_ReadPoint(u16 x, u16 y)
{
    u16 rgb;
    rgb = *(SDRAM_LCD_BUF1+index(x, y));
    return rgb;
}
u32 index(u16 x, u16 y)
{
    return (y * 1024 + x);
}

/**
 * @brief 用指定颜色清空整个屏幕
 * 
 * @param color 要填充的颜色
 */
void LCD_Cler(u16 color)
{
    u32 size;
    u32 i;
    size = 1024 * 600;
    for (i = 0; i < size; i++)
    {
        *(SDRAM_LCD_BUF1+i) = color;
    }
}

/**
 * @brief 在指定区域填充指定颜色
 * 
 * @param x0 填充区域左上角 x 坐标
 * @param y0 填充区域左上角 y 坐标
 * @param x1 填充区域右下角 x 坐标
 * @param y1 填充区域右下角 y 坐标
 * @param color 填充的颜色
 */
void LCD_Fill(u16 xStrat, u16 yStrat, u16 xEnd, u16 yEnd, u16 color)
{
    u16 i, j;
    for (i = xStrat; i < xEnd; i++)
    {
        for (j = yStrat; j < yEnd; j++)
        {
            *(SDRAM_LCD_BUF1+index(i, j)) = color;
        }
    }
}

/**
 * @brief 在屏幕上绘制一个位图
 * 
 * @param _usX 位图左上角 x 坐标
 * @param _usY 位图左上角 y 坐标
 * @param _usHeight 位图高度
 * @param _usWidth 位图宽度
 * @param _ptr 位图数据指针
 */
void LCD_DrawBMP(uint16_t _usX, uint16_t _usY, uint16_t _usHeight, uint16_t _usWidth, uint16_t *_ptr)
{
	uint16_t i, k, y;
	const uint16_t *p;

	p = _ptr;
	y = _usY;
	for (i = 0; i < _usHeight; i++)
	{
		for (k = 0; k < _usWidth; k++)
		{
			LCD_DrawPoint(_usX + k, y, *p++);
		}
		y++;
	}
}

/*
 * FGMAR: 前景内存地址寄存器, 指定前景图像数据的存储起始地址.
 * FGOR: 前景偏移寄存器, 指定前景图像数据的行与行之间的偏移量.
 * FGPFCCR: 前景PFC控制寄存器, 配置前景图像的像素格式和PFC选项.
 * FGCOLOR: 前景颜色寄存器, 指定前景图像的颜色.
 * FGCMAR: 前景CLUT内存地址寄存器, 指定前景图像的颜色查找表的存储起始地址.
 * FGCLUT: 前景CLUT, 包含前景图像的颜色查找表.
 */
/*
 * BGMAR: 背景内存地址寄存器, 指定背景图像数据的存储起始地址.
 * BGOR: 背景偏移寄存器, 指定背景图像数据的行与行之间的偏移量.
 * BGPFCCR: 背景PFC控制寄存器, 配置背景图像的像素格式和PFC选项.
 * BGCOLR: 背景颜色寄存器, 指定背景图像的颜色.
 * BGCMAR: 背景CLUT内存地址寄存器, 指定背景图像的颜色查找表的存储起始地址.
 * BGCLUT: 背景CLUT, 包含背景图像的颜色查找表.
 */
/*
 * OMAR: 输出内存地址寄存器, 指定输出图像数据的存储起始地址.
 * OOR: 输出偏移寄存器, 指定输出图像数据的行与行之间的偏移量.
 * OCOLR: 输出颜色寄存器, 指定输出图像的颜色.
 * NLR: 行数寄存器, 指定图像的行数.
 * OPFCCR: 输出PFC控制寄存器, 配置输出图像的像素格式和PFC选项.
 * LWR: 行水印寄存器, 指定何时生成行中断.
 * AMTCR: AXI主定时器配置寄存器, 配置AXI主定时器的工作方式.
 */


/**
 * @brief 使用DMA2D填充指定区域的颜色
 * 
 * @param xStart 填充区域左上角 x 坐标
 * @param yStart 填充区域左上角 y 坐标
 * @param xEnd 填充区域右下角 x 坐标
 * @param yEnd 填充区域右下角 y 坐标
 * @param Color 填充的颜色
 */
void LCD_DMA2D_Fill(u16 xStart,u16 yStart,u16 xEnd,u16 yEnd,u16 Color){
    __HAL_RCC_DMA2D_CLK_ENABLE();
    u32 BuffAdd;
    u32 OffLine;
    
    BuffAdd=((u32)SDRAM_LCD_BUF1+index(xStart,yStart)*2);
    OffLine= ABS(1024-(xEnd-xStart));
    
    __WRITE_REG(DMA2D->CR,0x00030000UL);                    
    
    __WRITE_REG(DMA2D->OMAR,(u32)BuffAdd);                   
    __WRITE_REG(DMA2D->OCOLR,Color);                         
    __WRITE_REG(DMA2D->OOR,OffLine);                         
    __WRITE_REG(DMA2D->OPFCCR,LTDC_PIXEL_FORMAT_RGB565);
    
    __WRITE_REG(DMA2D->NLR,((xEnd-xStart)<<16)| (yEnd-yStart));
    
    __SET_BIT(DMA2D->CR,DMA2D_CR_START);
    
    while(DMA2D->CR & DMA2D_CR_START){}
}

/**
 * @brief 使用DMA2D在指定区域显示图像
 * 
 * @param xStart 显示区域左上角 x 坐标
 * @param yStart 显示区域左上角 y 坐标
 * @param xEnd 显示区域右下角 x 坐标
 * @param yEnd 显示区域右下角 y 坐标
 * @param Image 图像数据指针
 */
void LCD_DMA2D_Image(u16 xStart,u16 yStart,u16 xEnd,u16 yEnd,void *Image){
    __HAL_RCC_DMA2D_CLK_ENABLE();
    u32 BuffAdd;
    u32 OffLine;

    BuffAdd=((u32)SDRAM_LCD_BUF1+index(xStart,yStart)*2);
    OffLine= ABS(1024-(xEnd-xStart));

    __WRITE_REG(DMA2D->CR,0x00000000UL);                     
   
    __WRITE_REG(DMA2D->FGMAR,(u32)Image);
    __WRITE_REG(DMA2D->FGOR,0);
    __WRITE_REG(DMA2D->FGPFCCR,LTDC_PIXEL_FORMAT_RGB565);
    
    __WRITE_REG(DMA2D->OMAR,(u32)BuffAdd);
    __WRITE_REG(DMA2D->OOR,OffLine);
    __WRITE_REG(DMA2D->OPFCCR,LTDC_PIXEL_FORMAT_RGB565);
    
    __WRITE_REG(DMA2D->NLR,((xEnd-xStart)<<16)| (yEnd-yStart));
    
    __SET_BIT(DMA2D->CR,DMA2D_CR_START);

    while(DMA2D->CR & DMA2D_CR_START){}
}
