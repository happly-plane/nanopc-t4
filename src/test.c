#include <CL/cl.h>
#include <stdio.h>

int main() {
    cl_int err;
    cl_uint numPlatforms;
    cl_platform_id platform;
    cl_device_id device;
    char deviceName[128];

    // 获取平台数量
    err = clGetPlatformIDs(1, &platform, &numPlatforms);
    if (err != CL_SUCCESS) {
        printf("Error: Failed to get platform IDs!\n");
        return 1;
    }

    // 获取设备
    err = clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU, 1, &device, NULL);
    if (err != CL_SUCCESS) {
        printf("Error: Failed to get device IDs!\n");
        return 1;
    }

    // 获取设备名称
    err = clGetDeviceInfo(device, CL_DEVICE_NAME, sizeof(deviceName), deviceName, NULL);
    if (err != CL_SUCCESS) {
        printf("Error: Failed to get device name!\n");
        return 1;
    }

    // 打印设备名称
    printf("Device Name: %s\n", deviceName);

    return 0;
}
