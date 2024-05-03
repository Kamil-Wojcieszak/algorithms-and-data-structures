cmake_minimum_required(VERSION 3.25)
project(AiZO_1)

MATH(EXPR stack_size "256 * 1024 * 1024") # 256 Mb
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")

set(CMAKE_CXX_STANDARD 17)
include_directories(src)
include_directories(lib)

add_executable(AiZO_1 src/main.cpp
        src/Sorts/QuickSort/QuickSort.cpp
        src/Array/Array.cpp
        src/Array/Array.h
        src/Sorts/InsertionSort/InsertionSort.cpp
        src/Sorts/InsertionSort/InsertionSort.h
        src/Results/Results.h
        src/Results/Results.cpp
        src/Menu/Menu.cpp
        src/Sorts/HeapSort/HeapSort.cpp
        src/Sorts/ShellSort/ShellSort.h
        src/Sorts/ShellSort/ShellSort.cpp
        src/Test/Test.h
        src/Test/Test.cpp
        src/Time/Time.cpp
)
