//
// Created by kamil on 10.10.2023.
//

#ifndef PEA_1_BRUTEFORCE_H
#define PEA_1_BRUTEFORCE_H

#include "Graph/Graph.h"

class Bruteforce {

	int **matrix;

	int nNodes;

	int** memo;

	int cost;

	int VISITED_ALL;

	int* path;

	int** prev;

	int algorithm(int mask, int pos);

public:
	void start();

	Bruteforce(Graph graph);

	~Bruteforce();


	string toString();


};


#endif //PEA_1_BRUTEFORCE_H
