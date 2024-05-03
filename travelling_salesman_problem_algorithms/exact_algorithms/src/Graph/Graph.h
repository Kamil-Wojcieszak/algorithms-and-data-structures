//
// Created by kamil on 10.10.2023.
//

#ifndef PEA_1_GRAPH_H
#define PEA_1_GRAPH_H

#include <string>

using namespace std;

class Graph {
	int **matrix;
	int numberOfNodes;
	void addUndirectedEdge(int src, int dst, int weight);
public:

    Graph();
    ~Graph();


	bool load(string fileName);

	string toString();

	int **getMatrix();

	int getNodeCount();

	bool generateUndirectedGraph(int numberOfVertices);


	bool setDiagonal();
};


#endif //PEA_1_GRAPH_H
