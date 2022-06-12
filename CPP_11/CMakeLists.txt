cmake_minimum_required(VERSION 2.8)
project(CPP_11)
add_compile_options(-std=c++11)

add_executable(test wheels_struct_pointer.cpp)
add_executable(test2 multi_construction.cpp)