#include"oled.h"
#include<stdint.h>
#include<stdio.h>
#include<wiringPi.h>
#define SDA  3
#define SCL  5


int main(void)
{
wiringPiSetupPhys();
pinMode(SDA,OUTPUT);
pinMode(SCL,OUTPUT);
pullUpDnControl(SDA,PUD_UP);
pullUpDnControl(SCL,PUD_UP);
OLED_Init();
while (1)
{
    OLED_ShowChar(1,1,'A');
}




return 0;

}