//
// Created by kamil on 24.10.2023.
//

#ifndef PEA_1_DYNAMICPROGRAMMING_H
#define PEA_1_DYNAMICPROGRAMMING_H

#include "Graph/Graph.h"

class DynamicProgramming {



	int **matrix;

	int nNodes;

	int cost;

	int VISITED_ALL;

	int** memo;

	int* path;

    int** prev;

	int algorithm(int mask, int pos);

public:
	void start();

	DynamicProgramming(Graph graph);

	~DynamicProgramming();


	string toString();


};

#endif //PEA_1_DYNAMICPROGRAMMING_H
