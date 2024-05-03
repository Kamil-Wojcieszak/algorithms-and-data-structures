//
// Created by kamil on 16.10.2023.
//

#ifndef PEA_1_BRANCHANDBOUND_H
#define PEA_1_BRANCHANDBOUND_H


#include <vector>
#include "Graph/Graph.h"
#include "Stack/MyStack.h"

struct Node {
	int lBound;
	int vertex;
};

class BranchAndBound {
	int **matrix;
	int nNodes;
	int uBound;
	int tempCost;
	bool *visited;
	int *minEdges;
	int n0LowerBound;
	MyStack path;
	MyStack helperPath;

public:
	string toString();

	int lowerBound(Node arg, int next);

	void start();

	void algorithm(Node node);

	BranchAndBound(Graph graph);

	~BranchAndBound();


	int lowerBoundAlternative(Node arg, int next);
};


#endif //PEA_1_BRANCHANDBOUND_H
