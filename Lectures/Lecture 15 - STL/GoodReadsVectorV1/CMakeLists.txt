cmake_minimum_required(VERSION 3.29)
project(GoodReadsVectorV1)

set(CMAKE_CXX_STANDARD 20)

add_executable(GoodReadsVectorV1 main.cpp Book.cpp Review.cpp GoodReads.cpp)
