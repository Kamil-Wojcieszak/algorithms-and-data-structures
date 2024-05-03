//
// Created by kamil on 24.05.2023.
//

#ifndef SDIZO_PROJEKT_2_KRUSKAL_H
#define SDIZO_PROJEKT_2_KRUSKAL_H


#include "Graph/Graph.h"

class Kruskal {
public:
	Kruskal(Graph graph);
	~Kruskal();

	Graph graph;

	int find(int x);

	void Union(int x, int y);

	int* parent;

	int* rank;

	void kruskalAdjacencyList();

	void kruskalAdjacencyMatrix();

	void init();

	void printMST(Edge edgesIncluded[]);
};


#endif //SDIZO_PROJEKT_2_KRUSKAL_H
