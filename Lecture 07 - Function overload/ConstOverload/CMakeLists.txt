cmake_minimum_required(VERSION 3.15)
project(ConstOverload)

set(CMAKE_CXX_STANDARD 11)

add_executable(ConstOverload main.cpp C.cpp C.h)