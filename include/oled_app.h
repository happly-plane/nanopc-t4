
#ifndef __OLED_APP_H
#define	__OLED_APP_H

#include <sys/types.h>



#define I2C_RETRIES                                 0x0701
#define I2C_TIMEOUT                                 0x0702
#define I2C_SLAVE                                   0x0703       //IIC从器件的地址设置
#define I2C_BUS_MODE                                0x0780

#define OLED_COMMEND_ADDR 0x00
#define OLED_DATA_ADDR 0x40
#define OLED_ADDRESS 0x3C   //通过调整0R电阻,屏可以0x78和0x7A两个地址 -- 默认0x78  3C  

typedef unsigned char uint8;



static uint8 oled_i2c_write(int fd, uint8 reg, uint8 val);
void OLED_Init(void);
void OLED_Fill(unsigned char fill_Data); //全屏填充
void OLED_CLS(void);//清屏
void oled_set_Pos(unsigned char x, unsigned char y); //设置起始点坐标
// unsigned int  OLED_Pow(unsigned int X, unsigned int Y);
// void OLED_ShowNum(uint8 Line, uint8 Column, unsigned int Number, uint8 Length);
// void OLED_ShowChar(uint8 Line, uint8 Column, char Char);
void OLED_ShowChar(uint8 Line, uint8 Column, char Char);
void OLED_WriteData(uint8 Data);
void OLED_SetCursor(uint8 Y, uint8 X);
u_int32_t OLED_Pow(uint8 x,uint8 y);
void OLED_ShowNumber(uint8 x,uint8 y, u_int32_t number,uint8 length);



//void OLED_ShowStr(unsigned char x, unsigned char y, unsigned char ch[] );

// void OLED_ShowCN(unsigned char x, unsigned char y, unsigned char N);
// void OLED_DrawBMP(unsigned char x0,unsigned char y0,unsigned char x1,unsigned char y1,unsigned char BMP[]);

#endif