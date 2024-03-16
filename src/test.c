#include<stdio.h>
#include<stdlib.h>
#include "type.h"
#include "read_dataset.h"
#define PATH "../dateset/train-images-idx3-ubyte"
int main()
{
FILE *fp;
uint4 pixel[60000][28][28];
mnist_info(fp,PATH);
read_pixel(fp,pixel);
print_ipxel(pixel);
return 0;

}