//
// Created by kamil on 27.05.2023.
//

#include <iostream>
#include "Prim.h"
#include "Graph/Graph.h"
#include "MinHeap/MinHeap.h"

Prim::Prim(Graph graph) {
	this->graph = graph;
}

void Prim::primAdjacencyList() {
	Edge edgesIncluded[graph.numberOfVertices - 1];
	int mstSet[graph.numberOfVertices];
	for (int i = 0; i < graph.numberOfVertices; i++)
		mstSet[i] = false;
	MinHeap minHeap(graph);
	int lastAddedVertex = 0;
	Edge addedEdge;
	for (int i = 0; i < graph.numberOfVertices - 1; i++) {
		auto vEdges = graph.AdjacencyList[lastAddedVertex].head;
		for (int v = 0; vEdges != graph.NULL_EDGE; v++) {
			if (mstSet[vEdges->dst] == false && vEdges->weight > 0)
				minHeap.add(vEdges);
			vEdges = vEdges->next;
		}
		mstSet[lastAddedVertex] = true;
		do {
			addedEdge = minHeap.poll();
		} while (mstSet[addedEdge.dst] == true);
		lastAddedVertex = addedEdge.dst;
		edgesIncluded[i] = addedEdge;
	}
	printMST(edgesIncluded);
}


void Prim::printMST(Edge edgesIncluded[]) {
	std::printf("Src|Dst|Wght\n");
	for (int i = 0; i < graph.numberOfVertices - 1; ++i) {
		std::printf("  %d|  %d|   %d\n", edgesIncluded[i].src, edgesIncluded[i].dst, edgesIncluded[i].weight);
	}
	int result =0;
	for (int i = 0; i < graph.numberOfVertices-1; ++i) {
		result+=edgesIncluded[i].weight;
	}
	cout<<result<<endl;
}


void Prim::primAdjacencyMatrix() {
	Edge edgesIncluded[graph.numberOfVertices - 1];
	int mstSet[graph.numberOfVertices];
	for (int i = 0; i < graph.numberOfVertices; i++)
		mstSet[i] = false;
	MinHeap minHeap(graph);
	int lastAddedVertex = 0;
	Edge addedEdge;
	for (int i = 0; i < graph.numberOfVertices - 1; i++) {
		auto vEdges = graph.AdjacencyMatrix[lastAddedVertex];
		for (int v = 0; v < graph.numberOfVertices; v++) {
			if (mstSet[v] == false && vEdges[v]->weight > 0)
				minHeap.add(vEdges[v]);
		}
		mstSet[lastAddedVertex] = true;
		do {
			addedEdge = minHeap.poll();
		} while (mstSet[addedEdge.dst] == true);
		lastAddedVertex = addedEdge.dst;
		edgesIncluded[i] = addedEdge;
	}

	printMST(edgesIncluded); // Print the constructed MST
}
