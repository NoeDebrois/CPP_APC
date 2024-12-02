cmake_minimum_required(VERSION 3.29)
project(NameSpaceInPractice)

set(CMAKE_CXX_STANDARD 23)

add_executable(NameSpaceInPractice main.cpp MyFriendLibrary.cpp MyFriendLibrary.h)
