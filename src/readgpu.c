#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include "gpu_read.h"

#define  GPU_MAX_FREP "/sys/devices/platform/ff9a0000.gpu/devfreq/ff9a0000.gpu/max_freq"  // 800000000
#define  GPU_MIN_FREP "/sys/devices/platform/ff9a0000.gpu/devfreq/ff9a0000.gpu/min_freq"   // 200000000
#define  GPU_LOAD "/sys/devices/platform/ff9a0000.gpu/devfreq/ff9a0000.gpu/load"

int main()
{
FILE *fp, *cp;
unsigned long max_frep,min_frep, load;
// char a[8];

max_frep = read_gpu_frep_load(fp,GPU_MAX_FREP);
min_frep = read_gpu_frep_load(cp,GPU_MIN_FREP);

printf("%lu\n",max_frep);
printf("%lu\n",min_frep);

// fclose(fp);
// fclose(cp);
return 0;

}