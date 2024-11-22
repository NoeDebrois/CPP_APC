cmake_minimum_required(VERSION 3.16)
project(DocumentStore_initial)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(DocumentStore_initial
        Document.cpp
        Document.h
        DocumentStore.cpp
        DocumentStore.h
        main.cpp)
