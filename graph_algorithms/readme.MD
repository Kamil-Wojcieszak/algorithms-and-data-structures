# Implementation of various Graph algorithms in C++

## Introduction
This document provides documentation for the C++ program implementing various graph algorithms and data structures. The implemented algorithms include Dijkstra, Ford-Bellman, Ford-Fulkerson, Kruskal, and Prim. The program also includes implementations of MinHeap, Queue, and Stack data structures.


## Graph Algorithms:

#### Dijkstra's Algorithm
- [Dijkstra.cpp](src%2FDjikstra%2FDijkstra.cpp)
- **Description:** Dijkstra's algorithm is used to find the shortest path between nodes in a weighted graph. It operates by iteratively selecting the node with the smallest known distance from the starting node and updating the distances to its neighboring nodes. This process continues until all nodes have been visited.

#### Bellman-Ford Algorithm
- [BellmanFord.cpp](src%2FFord-Bellman%2FBellmanFord.cpp)
- **Description:** The Bellman-Ford algorithm is employed to find the shortest paths from a single source node to all other nodes in a weighted graph, even in the presence of negative edge weights. It iteratively relaxes edges, attempting to decrease the distance to each node until no further improvement is possible or negative-weight cycles are detected.

#### Ford-Fulkerson Algorithm
- [FordFulkerson.cpp](src%2FFord-Fulkerson%2FFordFulkerson.cpp)
- **Description:** The Ford-Fulkerson algorithm is utilized to compute the maximum flow in a flow network. It achieves this by iteratively augmenting paths from the source to the sink, increasing the flow along these paths until no more augmenting paths can be found.

#### Kruskal's Algorithm
- [Kruskal.cpp](src%2FKruskal%2FKruskal.cpp)
- **Description:** Kruskal's algorithm is employed to find the minimum spanning tree of a connected, undirected graph. It operates by iteratively selecting the shortest edge that does not create a cycle in the spanning tree until all vertices are included.

#### Prim's Algorithm
- [Prim.cpp](src%2FPrim%2FPrim.cpp)
- **Description:** Prim's algorithm is utilized to find the minimum spanning tree of a connected, undirected graph. It begins with an arbitrary vertex and repeatedly adds the shortest edge that connects a vertex in the tree to a vertex outside the tree, ensuring that the tree remains connected and acyclic.



**Data Structures:**
- [MinHeap.cpp](src%2FMinHeap%2FMinHeap.cpp): Implementation of a minimum heap data structure.
- [Queue.cpp](src%2FQueue%2FQueue.cpp): Implementation of a queue data structure.
- [Stack.cpp](src%2FStack%2FStack.cpp): Implementation of a stack data structure.

**Main Program:**
- The [**main.cpp**](https://github.com/Kamil-Wojcieszak/graphs_algorithms/src/main.cpp) file contains the main function and menu for interacting with the implemented algorithms and data structures.

## Usage
To use the program:
1. Compile the program using a C++ compiler.
2. Run the compiled executable.
3. Follow the menu prompts to select algorithms or data structures and provide necessary inputs.

## Menu Options
The program provides the following menu options:
- Load graph from file for MST (Minimum Spanning Tree) or SP (Shortest Paths).
- Generate a random graph.
- Display the graph.
- Run Prim's algorithm.
- Run Kruskal's algorithm.
- Run Dijkstra's algorithm.
- Run Bellman-Ford algorithm.
- Run Ford-Fulkerson algorithm.
- Load flow from file.

## Report
- [graph_algorithms_report.pdf](graph_algorithms_report.pdf): Report on the implementation of various graph algorithms and data structures.
- Report on the performance of Kurskal, Prim, Dijkstra, Ford-Bellman and Ford Fulkerson algorithms.

## License
This project is under open-source license that allows users to freely use, modify, and distribute the software for any purpose, including commercial purposes, without requiring payment or attribution. The license also includes a disclaimer of liability, stating that the software is provided "as is" without warranties. 