
/************************************************************/
//文件名：mpu6050.c
//功能:测试linux下iic驱动oled显示程序
//使用说明: (1)
//          (2)
//          (3)
//          (4)
//作者:pengjie
//日期:2019-07-03

/************************************************************/
//包含头文件
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>
#include <errno.h>

#include "oled_app.h"

extern int fd;

/* 主函数  */
int main(int argc, char *argv[])
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

        OLED_ShowStr(0, 4, (unsigned char *)"Hello wildfire", 2); //测试8*16字符
        sleep(1);
        OLED_CLS(); //清屏
    }

    close(fd);
}
