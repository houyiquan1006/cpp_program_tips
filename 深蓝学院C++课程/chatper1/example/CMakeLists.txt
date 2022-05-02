cmake_minimum_required(VERSION 2.8)
project(example)
add_compile_options(-std=c++11)

add_executable(helloworld helloworld.cpp)
add_executable(struct struct_cpp.cpp)
add_executable(system_io system_io.cpp)