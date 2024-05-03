//
// Created by kamil on 04.06.2023.
//

#ifndef SDIZO_PROJEKT_2_BELLMANFORD_H
#define SDIZO_PROJEKT_2_BELLMANFORD_H


#include "Graph/Graph.h"

class BellmanFord {
	Graph graph;
public:

	BellmanFord(Graph graph);

	void bellmanFordAdjacencyList(int startingVertex);

	void bellmanFordAdjacencyMatrix(int startingVertex);

	void print(int parent[],int distance[]);

};


#endif //SDIZO_PROJEKT_2_BELLMANFORD_H
