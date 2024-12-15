cmake_minimum_required(VERSION 3.16)
project(ArcadePlayers)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ArcadePlayers
        main.cc
        Player.cc
        Player.hh
        RandomPlayerGenerator.cc
        RandomPlayerGenerator.hh
        search.cc
        search.hh
        timing.cc
        timing.hh)
