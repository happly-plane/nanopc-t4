#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include "gpu_read.h"

#define  GPU_MAX_FREP "/sys/devices/platform/ff9a0000.gpu/devfreq/ff9a0000.gpu/max_freq"  // 800000000
#define  GPU_MIN_FREP "/sys/devices/platform/ff9a0000.gpu/devfreq/ff9a0000.gpu/min_freq"   // 200000000
#define  GPU_LOAD "/sys/devices/platform/ff9a0000.gpu/devfreq/ff9a0000.gpu/load"

int main()
{
FILE *fp;
unsigned long max_frep,min_frep, load;
// char a[8];


// if((fp = fopen(GPU_MAX_FREP,"r")) == NULL)
// {
//     printf("failure to open file\n");
//     exit(EXIT_FAILURE);
// }

// fread(&a,sizeof(a),8,fp);

// // frep = (unsigned long)buff;
// frep = atol(a);
// printf("%lu\n",frep);

// // while ((ch = getc(fp)) != EOF)
// // {
// //     putchar(fp);
// // }
fclose(fp);
return 0;

}