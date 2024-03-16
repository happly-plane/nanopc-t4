cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(nanopc-t4 LANGUAGES C)
include_directories(include)


set(CMAKE_BUILD_TYPE Debug)

# add_executable(read_gpu src/readgpu.c include/gpu_read.c)
# target_sources(read_gpu PRIVATE include/gpu_read.h)

add_executable(read_dataset src/test.c include/read_dataset.c)



add_definitions(-DCL_TARGET_OPENCL_VERSION=120)
add_executable(device-opencl src/opencl.c)
target_link_libraries(device-opencl OpenCL)



# 编译静态库
# add_library(gpu-read
#     STATIC
#     include/gpu_read.h
#     include/gpu_read.c
#   ) 

# # 链接库
# target_link_libraries(read_gpu gpu-read)