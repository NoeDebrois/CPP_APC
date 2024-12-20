cmake_minimum_required(VERSION 3.29)
project(particles)

set(CMAKE_CXX_STANDARD 20)

add_executable(particles main.cpp
        Particle.cpp
        Simulator.cpp
        Vector2D.cpp)
