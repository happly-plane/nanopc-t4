cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(nanopc-t4 LANGUAGES C)
add_executable(read_gpu src/readgpu.c)
include_directories(include)


# 编译静态库
# add_library(message
#  STATIC
#    Message.hpp
#    Message.cpp
#  ) 

# 链接库
# target_link_libraries(hello-word message)