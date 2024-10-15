cmake_minimum_required(VERSION 3.16)
project(new_complex)

set(CMAKE_CXX_STANDARD 11)

add_executable(complex main.cpp
        Complex.h
        Complex.cpp)