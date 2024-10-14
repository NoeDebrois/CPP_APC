cmake_minimum_required(VERSION 3.23)
project(LibraryInitialCode)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(LibraryInitialCode
        Book.cpp
        Book.h
        Library.cpp
        Library.h
        main.cpp)
