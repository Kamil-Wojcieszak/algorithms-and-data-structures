//
// Created by kamil on 30.05.2023.
//

#ifndef SDIZO_PROJEKT_2_DIJKSTRA_H
#define SDIZO_PROJEKT_2_DIJKSTRA_H


#include "Graph/Graph.h"
#include "MinHeap/MinHeap.h"

class Dijkstra {
public:
	Dijkstra(Graph);
	Graph graph;
	void dijkstraAdjacencyList(int startingVertex);

	void dijkstraAdjacencyMatrix(int startingVertex);
	int* parent,*distance,*sptSet;

	int countDistance(int startingVertex);

	int startingVertex;

	int find(int x);

	void relax(int u, int v, int w,MinHeap &heap);

	int shortestDistance();

	void print();
};


#endif //SDIZO_PROJEKT_2_DIJKSTRA_H
