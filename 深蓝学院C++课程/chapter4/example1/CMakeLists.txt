cmake_minimum_required(VERSION 2.8)
project(example1)
add_compile_options(-std=c++2a)

add_executable(test1 test1.cpp)
add_executable(test2 test2.cpp source.cpp)
add_executable(test3 test3.cpp)
add_executable(test4 test4.cpp)
add_executable(test5 test5.cpp)
