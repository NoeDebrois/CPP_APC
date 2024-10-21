cmake_minimum_required(VERSION 3.14)
project(lab2_initial)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -Wsign-conversion")

include_directories(.)

add_executable(social_network_initial
        main.cpp
        social_network.cpp
        social_network.hpp
        user.cpp
        user.hpp)