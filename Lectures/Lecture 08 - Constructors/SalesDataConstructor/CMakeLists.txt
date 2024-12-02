cmake_minimum_required(VERSION 3.15)
project(SalesDataConstructor)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(SalesDataConstructor
        main.cpp
        Sales_data.cpp
        Sales_data.h)
