//
// Created by kamil on 24.05.2023.
//

#ifndef SDIZO_PROJEKT_2_GRAPH_H
#define SDIZO_PROJEKT_2_GRAPH_H


#include <string>

using namespace std;

typedef struct Edge {
	int src;
	int dst;
	int weight;
	Edge *next;


	Edge(int src, int destination, int weight) {
		this->src = src;
		this->dst = destination;
		this->weight = weight%32000;
	}
	Edge() {}
};



struct VertexList {
	Edge *head = nullptr;
};

class Graph {
	void createGraph(int vertices);
	void addUndirectedEdge(int src, int dst, int weight);
	void printMatrix();
	void addDirectedEdge(int src, int dst, int weight);
	void printList();
public:
	int numberOfVertices = 0;
	int numberOfEdges = 0;
	VertexList *AdjacencyList = nullptr;

	Edge ***AdjacencyMatrix;

	Edge *NULL_EDGE;

	Graph();

	~Graph();







	void loadFromFileMst(string fileName);

	void deleteEdge(int source, int destination);

	int* loadFromFloat(string fileName);

	void deleteTest(Edge **e1, Edge **e2);

	void generateUndirectedGraph(int numberOfVertices, int density);



	void print();

	void deleteList();

	void deleteMatrix();

	void deleteGraph();

	int loadFromSP(string fileName);



	void generateDirectedGraph(int numberOfVertices, int density);

	bool removeDirectedEdge(int src, int dst);

	bool removeUndirectedEdge(int src, int dst);
};


#endif //SDIZO_PROJEKT_2_GRAPH_H
