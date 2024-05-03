cmake_minimum_required(VERSION 3.26)
project(PEA_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(PEA_1
        src/BranchAndBound/BranchAndBound.cpp
        src/BranchAndBound/BranchAndBound.h
        src/Bruteforce/Bruteforce.cpp
        src/Bruteforce/Bruteforce.h
        src/DynamicProgramming/DynamicProgramming.cpp
        src/DynamicProgramming/DynamicProgramming.h
        src/Graph/Graph.cpp
        src/Graph/Graph.h
        src/Menu/Menu.cpp
        src/Menu/Menu.h
        src/Queue/Queue.cpp
        src/Queue/Queue.h
        src/Stack/MyStack.cpp
        src/Stack/MyStack.h
        src/Time/Time.cpp
        src/Time/Time.h
        src/main.cpp
        src/Tests/Tests.cpp)
