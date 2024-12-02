cmake_minimum_required(VERSION 3.16)
project(MinRnInitial)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(MinRnInitial
        FunctionMin3.cpp
        FunctionMinRn.cpp
        FunctionMinRn.h
        FunctionRn.cpp
        FunctionRn.h
        Monomial.cpp
        Monomial.h
        Point.cpp
        Point.h)
