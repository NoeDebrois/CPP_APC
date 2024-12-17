cmake_minimum_required(VERSION 3.16)
project(TaxiCallCenter_initial)

set(CMAKE_CXX_STANDARD 11)

add_executable(TaxiCallCenter_initial_code main.cpp date.cpp date.h place.cpp place.h taxi.cpp taxi.h callcenter.cpp callcenter.h)