cmake_minimum_required(VERSION 3.26)
project(Assignment1_2024)

set(CMAKE_CXX_STANDARD 23)

add_executable(Assignment1_2024 main.cpp
        matrixhelpers.h
        matrixhelpers.cpp
        squarematrix.cpp
        squarematrix.h
        vectorhelpers.h
        vectorhelpers.cpp
        power_iteration.cpp
        power_iteration.h
        inverse_power_iteration.cpp
        inverse_power_iteration.h
        shift_inverse_power_iteration.cpp
        shift_inverse_power_iteration.h
        eig_finder_helpers.h
)
