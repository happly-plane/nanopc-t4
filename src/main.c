#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>


#define OLED_ADDRESS 0x3C
#define OLED_COMMEND_ADDR 0x00
#define OLED_DATA_ADDR 0x40
int fd = -1;


void OLED_Init(void)
{
	fd = open("/dev/ii2c-2",O_RDWR);
		if (fd < 0)
	{
		perror("Can't open /dev/i2c-2 \n");
		exit(1);
	}
if (ioctl(fd,I2C_SLAVE,OLED_ADDRESS) < 0)
{
	 printf("fail to set i2c device slave address!\n");
        close(fd);
}

 	oled_i2c_write(fd, OLED_COMMEND_ADDR, 0xAE); //display off
    oled_i2c_write(fd, OLED_COMMEND_ADDR, 0x20); //
    oled_i2c_write(fd, OLED_COMMEND_ADDR, 0x10); //00,Horizontal Addressing Mode;
    oled_i2c_write(fd, OLED_COMMEND_ADDR, 0xb0); //Set Page Start Address for Page Addressing Mode,0-7
    oled_i2c_write(fd, OLED_COMMEND_ADDR, 0xc8); //Set COM Output Scan Direction

}

static uint8 oled_i2c_write(int fd, uint8 reg, uint8 val)
{
    /*******************第一部分************************/
    int retries;
    uint8 data[2];
    int write_error = 0;

    data[0] = reg;
    data[1] = val;

    ioctl(fd, I2C_SLAVE, OLED_ADDRESS);
    /*******************第二部分************************/
    for (retries = 5; retries; retries--)
    {
        if (write(fd, data, 2) == 2)
        {
            return 0;
        }
        usleep(1000);
    }
    return -1;
}



void OLED_Fill(unsigned char fill_Data) //全屏填充
{
    unsigned char m, n;
    /*---------------------第一部分---------------------*/
    for (m = 0; m < 8; m++)
    {
        oled_i2c_write(fd, OLED_COMMEND_ADDR, 0xb0 + m); //page0-page1
        oled_i2c_write(fd, OLED_COMMEND_ADDR, 0x00);     //low column start address
        oled_i2c_write(fd, OLED_COMMEND_ADDR, 0x10);     //high column start address
       /*---------------------第二部分---------------------*/
        for (n = 0; n < 128; n++)
        {
            // WriteDat(fill_Data);
            oled_i2c_write(fd, OLED_DATA_ADDR, fill_Data); //high column start address
        }
    }
}
void OLED_ShowStr(unsigned char x, unsigned char y, unsigned char ch[], unsigned char TextSize)
{
     unsigned char c = 0,i = 0,j = 0;
     switch(TextSize)
     {

    /*---------------------第一部分---------------------*/
             case 1:
             {
                     while(ch[j] != '\0')
                     {
                             c = ch[j] - 32;
                             if(x > 126)
                             {
                                     x = 0;
                                     y++;
                             }
                             oled_set_Pos(x,y);
                             for(i=0;i<6;i++)
                                     oled_i2c_write(fd, OLED_DATA_ADDR,F6x8[c][i]);
                             x += 6;
                             j++;
                     }
             }break;
    /*---------------------第二部分---------------------*/
            //  case 2:
            //  {
            //          while(ch[j] != '\0')
            //          {
            //                  c = ch[j] - 32;
            //                  if(x > 120)
            //                  {
            //                          x = 0;
            //                          y++;
            //                  }
            //                  oled_set_Pos(x,y);
            //                  for(i=0;i<8;i++)
            //                          oled_i2c_write(fd, OLED_DATA_ADDR,F8X16[c*16+i]);
            //                  oled_set_Pos(x,y+1);
            //                  for(i=0;i<8;i++)
            //                          oled_i2c_write(fd, OLED_DATA_ADDR,F8X16[c*16+i+8]);
            //                  x += 8;
            //                  j++;
            //          }
            //  }break;
     }
}

int main()
{
int i = 0; //用于循环

    OLED_Init(); //初始化oled
    usleep(1000 * 100);
    OLED_Fill(0xff); //全屏填充

    while (1)
    {
        OLED_Fill(0xff); //全屏填充
        sleep(1);

        OLED_CLS(); //清屏
        sleep(1);

        OLED_ShowStr(0, 3, (unsigned char *)"Wildfire Tech", 1);  //测试6*8字符
        OLED_ShowStr(0, 4, (unsigned char *)"Hello wildfire", 2); //测试8*16字符
        sleep(1);
        OLED_CLS(); //清屏

        // for (i = 0; i < 4; i++)
        // {
        //     OLED_ShowCN(22 + i * 16, 0, i); //测试显示中文
        // }
        sleep(1);
        OLED_CLS(); //清屏

        // OLED_DrawBMP(0, 0, 128, 8, (unsigned char *)BMP1); //测试BMP位图显示
        sleep(1);
        OLED_CLS(); //清屏
    }

    close(fd);
}