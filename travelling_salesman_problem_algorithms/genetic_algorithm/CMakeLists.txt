cmake_minimum_required(VERSION 3.25)
project(E3)

set(CMAKE_CXX_STANDARD 20)

include_directories(src)
include_directories(bin)
include_directories(lib)

add_executable(E3
        src/main.cpp
        src/Graph/Graph.cpp
        src/Graph/Graph.h
        src/GeneticAlgorithm/GeneticAlgorithm.cpp
        src/GeneticAlgorithm/GeneticAlgorithm.h
        src/Menu/Menu.cpp
        src/Menu/Menu.h
        lib/tinyxml2-9.0.0/tinyxml2.h
        lib/tinyxml2-9.0.0/tinyxml2.cpp
        src/Test/Test.cpp src/Test/Test.cpp src/Test/Test.h)