cmake_minimum_required(VERSION 3.24)
project(SDIZO_PROJEKT_2)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_executable(
        SDIZO_PROJEKT_2
        src/main.cpp
        src/Kruskal/Kruskal.cpp
        src/Kruskal/Kruskal.h
        src/Graph/Graph.cpp
        src/Graph/Graph.h
        src/MinHeap/MinHeap.cpp
        src/MinHeap/MinHeap.h
        src/Time/Time.cpp
        src/Time/Time.h
        src/Prim/Prim.cpp
        src/Prim/Prim.h
        src/Djikstra/Dijkstra.cpp
        src/Djikstra/Dijkstra.h
        src/Ford-Bellman/BellmanFord.cpp
        src/Ford-Bellman/BellmanFord.h
        src/Ford-Fulkerson/FordFulkerson.cpp
        src/Ford-Fulkerson/FordFulkerson.h
        src/Queue/Queue.cpp
        src/Queue/Queue.h
        src/Stack/Stack.cpp
        src/Stack/Stack.h
        src/Tests/Tests.cpp
        src/Tests/Tests.h
)