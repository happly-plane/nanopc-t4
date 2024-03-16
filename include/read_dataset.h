#ifndef _READ_DATASET
#define _READ_DATASET   
#include<stdio.h>
#include<stdlib.h>
unsigned int littleEndianToBigEndian(unsigned int num);
void mnist_info(FILE *fp,const char * path);
void read_pixel(FILE *fp,unsigned int f[60000][28][28]);
void print_ipxel(unsigned int f[60000][28][28]);









#endif