cmake_minimum_required(VERSION 3.20)
project(Tensors)

set(CMAKE_CXX_STANDARD 11)

add_executable(Tensors main.cpp Tensor.cpp Tensor.h)
