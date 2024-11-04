cmake_minimum_required(VERSION 3.23)
project(skirenting)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(skirenting
        main.cpp
        rentShop.hpp
        skiWarehouse.hpp rentShop.cpp skiWarehouse.cpp)
