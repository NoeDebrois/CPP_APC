cmake_minimum_required(VERSION 3.23)
project(useOfThis)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(useOfThis
        main.cpp
        X.cpp
        X.h)
