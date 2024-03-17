#include"oled.h"
#include<stdint.h>
#include<stdio.h>
#include<wiringPi.h>



int main(void)
{
wiringPiSetupPhys();
pinMode(SDA,OUTPUT);
pinMode(SCL,OUTPUT);
OLED_Init();
while (1)
{
    OLED_ShowChar(1,1,'A');
}




return 0;

}