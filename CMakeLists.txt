cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(nanopc-t4 LANGUAGES C)
add_executable(read_gpu src/readgpu.c)
# include_directories()
# target_sources(read_gpu PRIVATE include/gpu_read.h)


# 编译静态库
add_library(gpu-read
    STATIC
    include/gpu_read.h
    include/gpu_read.c
  ) 

# 链接库
target_link_libraries(read_gpu gpu-read)