cmake_minimum_required(VERSION 3.29)
project(Date)

set(CMAKE_CXX_STANDARD 20)

add_executable(Date testDates.cpp Date.cpp)
