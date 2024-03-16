#include <stdio.h>
#include <stdlib.h>
#include "read_dataset.h"
#include "type.h"


unsigned int littleEndianToBigEndian(unsigned int num)
{
    return ((num >> 24) & 0xFF) |      // 将第一个字节移到最后一个位置
           ((num >> 8) & 0xFF00) |     // 将第二个字节移到倒数第二个位置
           ((num << 8) & 0xFF0000) |   // 将第三个字节移到倒数第三个位置
           ((num << 24) & 0xFF000000); // 将第四个字节移到第一个位置
}

void mnist_info(FILE *fp,const char * path)
{
    unsigned int a = 0, b = 0, c = 0, d = 0;
    if ((fp = fopen(path, "rb")) == NULL)
    {
        printf("open %s failure", path);
        exit(EXIT_FAILURE);
    }
    fread(&a, sizeof(a), 1, fp);
    a = littleEndianToBigEndian(a);
    printf("Magic number is %d\n", a);

    fseek(fp, 4L, SEEK_SET);
    fread(&b, sizeof(b), 1, fp);
    b = littleEndianToBigEndian(b);
    printf("Number of images is %d\n", b);

    fseek(fp, 8L, SEEK_SET);
    fread(&c, sizeof(c), 1, fp);
    c = littleEndianToBigEndian(c);
    printf("Number of rows is %d\n", c);

    fseek(fp, 12L, SEEK_SET);
    fread(&d, sizeof(d), 1, fp);
    d = littleEndianToBigEndian(d);
    printf("Number of columns is %d\n", d);

    // fclose(fp);
}

void read_pixel(FILE *fp,unsigned int f[60000][28][28])
{
    // unsigned int f[60000][28][28];
    byte e;
    long  offset = 16;

    for (long number = 0; number < 60000; number++)   //图片数量
    {
        for (long pixel_columns = 0; pixel_columns < 28; pixel_columns++) //像素列
        {
            for (long pixel_rows = 0; pixel_rows < 28; pixel_rows++) //像素行
            {
                fseek(fp,offset,SEEK_SET);
                fread(&e,sizeof(e),1,fp);  // 像素总字节 = 47,039,984
                f[number][pixel_columns][pixel_rows] = (unsigned int)e;
                offset++;

                if (pixel_rows == 28)
                {
                    pixel_rows = 0;
                }

            }

                if (pixel_columns == 28)
                {
                    pixel_columns = 0;
                }
                
        }
           
    }
    if (offset == 47039984)
    {
        printf("Read succes\n");
    }
}

void print_ipxel(unsigned int f[60000][28][28])
{

    for (long number = 0; number < 60000; number++)   //图片数量
    {
        for (long pixel_columns = 0; pixel_columns < 28; pixel_columns++) //像素列
        {
            for (long pixel_rows = 0; pixel_rows < 28; pixel_rows++) //像素行
            {

                 printf("%d\n",f[number][pixel_columns][pixel_rows]);

                if (pixel_rows == 28)
                {
                    pixel_rows = 0;
                }

            }

                if (pixel_columns == 28)
                {
                    pixel_columns = 0;
                }
                
        }
           
    }



}

