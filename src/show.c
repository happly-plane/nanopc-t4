#include"oled.h"
#include<stdint.h>
#include<stdio.h>
#include<wiringPi.h>



int main(void)
{
wiringPiSetupPhys();
pinMode(SDA,OUT_PUT);
pinMode(SCL,OUT_PUT);
OLED_Init();
while (1)
{
    OLED_ShowChar(1,1,'A');
}




return 0;

}