cmake_minimum_required(VERSION 3.29)
project(trapezoidal_functional)

set(CMAKE_CXX_STANDARD 20)

add_executable(trapezoidal_functional main.cpp
        with_io_functional.cc
        bcast.cc
        reduce.cc
        quadrature_functional.cc)
