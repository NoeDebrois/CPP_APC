cmake_minimum_required(VERSION 3.14)
project(MatrixComputationInitialCode)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(MatrixComputationInitialCode
        block.cpp
        block.hpp
        block_matrix.cpp
        block_matrix.hpp
        dense_matrix.cpp
        dense_matrix.hpp
        main.cpp
        matrix.cpp
        matrix.hpp)
