cmake_minimum_required(VERSION 3.21)
project(SDIZO_PROJEKT)
enable_testing()
set(CMAKE_CXX_STANDARD 23)
include_directories(src)

add_executable(
    SDIZO_PROJEKT
        src/table/table.h
        src/table/table.cpp
        src/list/list.cpp
        src/list/list.h
        src/main.cpp
        # test/testTable.cpp
        "src/binary heap/Heap.cpp"
        "src/binary heap/Heap.h"
        src/tree/Tree.cpp
        src/tree/Tree.h
        src/tests/Tests.cpp
        src/time/Time.cpp
)



