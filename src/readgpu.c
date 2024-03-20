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

    char str[5];

    OLED_Init(); //初始化oled
    OLED_Fill(0xff);
    usleep(1000 * 100);
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
        OLED_CLS();
        // OLED_ShowStr(0, 3, (unsigned char *)usage, 1);  //测试6*8字符
        snprintf(str, 5, "%.2f%%", usage); // 将浮点数转换为字符串
     // OLED_ShowStr(0, 4, (unsigned char *)"Hello wildfire", 2); //测试8*16字符
        OLED_ShowChar(1,4,'A');
        OLED_ShowNumber(2,1,3456);
        sleep(4);
}

    return 0;
}