cmake_minimum_required(VERSION 3.29)
project(KMeans_initial)

set(CMAKE_CXX_STANDARD 20)

add_executable(KMeans_initial Point.cpp Clustering.cpp Centroid.cpp KMeans.cpp)
