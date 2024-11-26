cmake_minimum_required(VERSION 3.26)
project(Assignment2_2024)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Assignment2_2024
        cnn.cpp
        cnn.hpp
        convolutional_layer.cpp
        convolutional_layer.hpp
        dataset.cpp
        dataset.hpp
        fc_layer.cpp
        fc_layer.hpp
        feature_layer.hpp
        main.cpp
        matrix.cpp
        matrix.hpp
        max_pooling_layer.cpp
        max_pooling_layer.hpp
        relu.cpp
        relu.hpp
        sigmoid.cpp
        sigmoid.hpp
        tensor_3d.cpp
        tensor_3d.hpp
        activation_function.hpp
        test.hpp
)
