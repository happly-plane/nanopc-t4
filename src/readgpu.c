//包含头文件
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>
#include <errno.h>
#include "oled_app.h"

extern int fd;


int main()
{
 FILE *file;
    unsigned long user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
    unsigned long prev_idle, prev_total, idle_delta, total_delta;
    double usage;

    int i = 0; //用于循环

    OLED_Init(); //初始化oled
    usleep(1000 * 100);
    OLED_Fill(0xff); //全屏填充

while (1)
{
    file = fopen("/proc/stat", "r");
    if (file == NULL) {
        perror("Error opening /proc/stat");
        return 1;
    }

    if (fscanf(file, "cpu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu",
               &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice) != 10) {
        printf("Error reading CPU stats from /proc/stat\n");
        fclose(file);
        return 1;
    }

    fclose(file);

    prev_idle = idle;
    prev_total = user + nice + system + idle + iowait + irq + softirq + steal;

    sleep(1); // 等待一段时间

    file = fopen("/proc/stat", "r");
    if (file == NULL) {
        perror("Error opening /proc/stat");
        return 1;
    }

    if (fscanf(file, "cpu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu",
               &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice) != 10) {
        printf("Error reading CPU stats from /proc/stat\n");
        fclose(file);
        return 1;
    }

    fclose(file);

    idle_delta = idle - prev_idle;
    total_delta = (user + nice + system + idle + iowait + irq + softirq + steal) - prev_total;

    usage = 100.0 * (1.0 - ((double)idle_delta) / total_delta);
    // printf("CPU usage: %.2f%%\n", usage);

        OLED_CLS(); //清屏
        sleep(0.5);

        // OLED_ShowStr(0, 3, (unsigned char *)usage, 1);  //测试6*8字符
      
     // OLED_ShowStr(0, 4, (unsigned char *)"Hello wildfire", 2); //测试8*16字符
        OLED_ShowNum(2,1,123,5);
        sleep(0.5);
        OLED_CLS(); //清屏
}

    return 0;
}