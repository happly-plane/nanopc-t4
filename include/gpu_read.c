#include<stdio.h>
#include<stdlib.h>
#include "gpu_read.h"
unsigned long read_gpu_frep_load(FILE *fp,const char *path)
{
unsigned long frep = 0;
char a[8];
if ((fp = fopen(path,"r")) == NULL)
{
    printf("Open %s failure\n",path);
    exit(EXIT_FAILURE);
}   
if ((fread(&a,sizeof(a),8,fp)) < 8)
{
    printf("Read %s failure\n",path);
    exit(EXIT_FAILURE);
}

frep = atol(a);

return frep;

}

