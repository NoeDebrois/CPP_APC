cmake_minimum_required(VERSION 3.14)
project(initial_code)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -Wsign-conversion")

add_executable(sudoku_initial sudoku_initial.cpp)