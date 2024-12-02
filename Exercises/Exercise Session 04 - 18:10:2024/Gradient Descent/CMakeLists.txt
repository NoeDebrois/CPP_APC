cmake_minimum_required(VERSION 3.14)
project(MinR)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(MinR
        Function.cpp
        Function.hpp
        FunctionMin.cpp
        FunctionMin.hpp
        main.cpp)
