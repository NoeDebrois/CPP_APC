cmake_minimum_required(VERSION 3.16)
project(TaxiCallCenter_disjoint)

set(CMAKE_CXX_STANDARD 11)

add_executable(TaxiCallCenter_disjoint main.cpp date.cpp date.h taxi.cpp taxi.h place.cpp place.h callcenter.cpp callcenter.h)