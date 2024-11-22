cmake_minimum_required(VERSION 3.16)
project(Calendars_initial)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(Calendars_initial
        Calendar.cpp
        Calendar.h
        Event.cpp
        Event.h
        main.cpp)
