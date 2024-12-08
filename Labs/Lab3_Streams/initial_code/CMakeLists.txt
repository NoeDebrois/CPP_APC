cmake_minimum_required(VERSION 3.14)
project(StudentsFile)

set(CMAKE_CXX_STANDARD 11)

add_executable(StudentsFile main.cpp Exam.cpp Exam.h StudentsData.cpp StudentsData.h
        FileManager.cpp)