cmake_minimum_required(VERSION 2.8)
project(example1)
add_compile_options(-std=c++17)

include_directories(./include)     # 有了这一条语句之后，代码中 include 头文件的路径的时候就会到该文件夹下搜索，而且是全局有效的。

add_executable(test1 include/header.h test1.cpp)
add_executable(test2 test2.cpp)
add_executable(test3 test3.cpp)
