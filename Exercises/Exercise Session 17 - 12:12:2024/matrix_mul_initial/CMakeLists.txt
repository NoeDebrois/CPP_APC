cmake_minimum_required(VERSION 3.29)
project(matrix_mul_initial)

set(CMAKE_CXX_STANDARD 20)

add_executable(matrix_mul_initial main.cpp
        dense_matrix.cc)
