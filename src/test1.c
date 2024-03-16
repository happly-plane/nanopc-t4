#include<stdio.h>
#include<stdlib.h>

int main()
{
char a[9] = "800000000";

unsigned long b = 0;

b = atol(a);
//b = (unsigned long)a;
printf("%lu\n",b);
    return 0;
}