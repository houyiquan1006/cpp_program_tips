cmake_minimum_required(VERSION 2.8)
project(example1)
add_compile_options(-std=c++11)

add_executable(test1 test1.cpp)
add_executable(test2 test2.cpp source.cpp)
