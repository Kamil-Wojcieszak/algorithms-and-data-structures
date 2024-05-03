cmake_minimum_required(VERSION 3.15)
project(PEA_2)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)
include_directories(lib)
include_directories(bin)

add_executable(PEA_2
        src/main.cpp
        src/Time/Time.h
        src/Time/Time.cpp
        src/Tests/Tests.h
        src/Tests/Tests.cpp
        src/Menu/Menu.cpp
        src/Menu/Menu.h
        src/Graph/Graph.h
        src/Graph/Graph.cpp
        lib/tinyxml2-9.0.0/tinyxml2.cpp
        lib/tinyxml2-9.0.0/tinyxml2.h
        src/SimulatedAnnealing/SimulatedAnnealing.cpp
        src/SimulatedAnnealing/SimulatedAnnealing.h
        src/GreedyPath/Prim.h
        src/GreedyPath/Prim.cpp
        src/TabuSearch/TabuSearch.cpp)
