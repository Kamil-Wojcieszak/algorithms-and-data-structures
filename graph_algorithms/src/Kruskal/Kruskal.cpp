//
// Created by kamil on 24.05.2023.
//

#include "Kruskal.h"
#include "Graph/Graph.h"
//#include "MaxHeap/MaxHeap.h"
#include "MinHeap/MinHeap.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

Kruskal::Kruskal(Graph graph) {
	this->graph = graph;
	this->rank = new int[graph.numberOfVertices];
	this->parent = new int[graph.numberOfVertices];
	for (int i = 0; i < graph.numberOfVertices; ++i) {
		parent[i] = i;
	}
	for (int i = 0; i < graph.numberOfVertices; ++i) {
		rank[i] = 0;
	}
}

void Kruskal::init() {
	delete[]rank;
	delete[]parent;
	rank = new int[graph.numberOfVertices];
	parent = new int[graph.numberOfVertices];
	for (int i = 0; i < graph.numberOfVertices; ++i) {
		parent[i] = i;
	}
	for (int i = 0; i < graph.numberOfVertices; ++i) {
		rank[i] = 0;
	}
}

Kruskal::~Kruskal() {
	delete[]parent;
}

int Kruskal::find(int x) {
	if (parent[x] != x)
		parent[x] = find(parent[x]);
	return parent[x];
}

// A utility function to do union of two subsets
void Kruskal::Union(int x, int y) {
	int a = find(x);
	int b = find(y);
	if (rank[a] < rank[b])
		parent[a] = b;
	else
		parent[b] = a;
	if (rank[a] = rank[b])
		rank[a] = rank[a] + 1;
}

void Kruskal::kruskalAdjacencyList() {
	init();

	MinHeap heap(graph);

	heap.loadGraphFromAdjacencyList();

	auto includedEdges = new Edge[graph.numberOfVertices - 1];
	for (int i = 0; i < graph.numberOfVertices - 1; ++i) {
		auto edge = heap.poll();
		if (find(edge.src) != find(edge.dst)) {
			includedEdges[i] = edge;
			Union(edge.src, edge.dst);
			continue;
		}
		i--;
	}
	printMST(includedEdges);

}

void Kruskal::printMST(Edge edgesIncluded[]) {
	std::printf("Src|Dst|Wght\n");
	for (int i = 0; i < graph.numberOfVertices - 1; ++i) {
		std::printf("  %d|  %d|   %d\n", edgesIncluded[i].src, edgesIncluded[i].dst, edgesIncluded[i].weight);
	}
	int result = 0;
	for (int i = 0; i < graph.numberOfVertices - 1; ++i) {
		result += edgesIncluded[i].weight;
	}
	cout << result << endl;
}

void Kruskal::kruskalAdjacencyMatrix() {
	init();

	MinHeap heap(graph);

	heap.loadGraphFromAdjacencyMatrix();


	auto includedEdges = new Edge[graph.numberOfVertices - 1];
	for (int i = 0; i < graph.numberOfVertices - 1; ++i) {
		auto edge = heap.poll();
		if (find(edge.src) != find(edge.dst)) {
			includedEdges[i] = edge;
			Union(edge.src, edge.dst);
			continue;
		}
		i--;
	}
	printMST(includedEdges);
}



