#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


#define  GPU_MAX_FREP "/sys/devices/platform/ff9a0000.gpu/devfreq/ff9a0000.gpu/max_freq"
#define  GPU_MIN_FREP "/sys/devices/platform/ff9a0000.gpu/devfreq/ff9a0000.gpu/min_freq"
#define  GPU_LOAD "/sys/devices/platform/ff9a0000.gpu/devfreq/ff9a0000.gpu/load"

int main()
{
 FILE *fp;
unsigned long frep;
char buff[9]= {0};
int ch = 0;


if((fp = fopen(GPU_MAX_FREP,"r")) == NULL)
{
    printf("failure to open file\n");
    exit(EXIT_FAILURE);
}

fread(&buff,sizeof(buff),9,fp);

// frep = (unsigned long)buff;
frep = strtoul(buff,NULL,9);
printf("%lu\n",frep);

// while ((ch = getc(fp)) != EOF)
// {
//     putchar(fp);
// }
fclose(fp);
return 0;

}