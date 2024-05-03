//
// Created by kamil on 27.05.2023.
//

#ifndef SDIZO_PROJEKT_2_PRIM_H
#define SDIZO_PROJEKT_2_PRIM_H


#include "Graph/Graph.h"

class Prim {
public:
	Prim(Graph graph);

	Graph graph;
	void primAdjacencyMatrix();
	void primAdjacencyList();

	void printMST(Edge edgesIncluded[]);
};


#endif //SDIZO_PROJEKT_2_PRIM_H
