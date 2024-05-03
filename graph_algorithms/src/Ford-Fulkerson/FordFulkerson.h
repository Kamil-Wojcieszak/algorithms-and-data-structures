//
// Created by kamil on 04.06.2023.
//

#ifndef SDIZO_PROJEKT_2_FORDFULKERSON_H
#define SDIZO_PROJEKT_2_FORDFULKERSON_H


#include "Graph/Graph.h"

class FordFulkerson {
	Graph graph;

	bool bfsAdjacencyMatrix(int **residualGraph, int startVertex, int endVertex, int parent[]);

	bool dfsAdjacencyMatrix(int **residualGraph, int startVertex, int endVertex, int parent[], bool *visited);

	bool bfsAdjacencyList(VertexList *residualGraph, int startVertex, int endVertex, int *parent);

public:
	FordFulkerson(Graph graph);

	void fordFulkersonBFSAdjacencyMatrix(int startVertex, int endVertex);

	void fordFulkersonDFSAdjacencyMatrix(int startVertex, int endVertex);

};


#endif //SDIZO_PROJEKT_2_FORDFULKERSON_H
