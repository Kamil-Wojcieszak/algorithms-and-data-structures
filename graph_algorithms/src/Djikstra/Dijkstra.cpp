//
// Created by kamil on 30.05.2023.
//

#include <iostream>
#include "Dijkstra.h"
#include "Graph/Graph.h"
#include "MinHeap/MinHeap.h"

Dijkstra::Dijkstra(Graph graph) {
	this->graph = graph;
}

void Dijkstra::dijkstraAdjacencyList(int startingVertex) {
	this->startingVertex = startingVertex;

	parent = new int[graph.numberOfVertices];
	distance = new int[graph.numberOfVertices];
	sptSet = new int[graph.numberOfVertices];

	MinHeap heap(graph);
	for (int i = 0; i < graph.numberOfVertices; ++i) {
		parent[i] = i;
		distance[i] = INT_MAX;
		sptSet[i] = false;
	}

	heap.add(new Edge(0, startingVertex, 0));
	distance[startingVertex] = 0;


	while(!heap.isEmpty())  {
		auto vertex = heap.poll();
		if (sptSet[vertex.dst])
			continue;
		//auto vertex = shortestDistance();
		sptSet[vertex.dst] = true;

		auto neighbour = graph.AdjacencyList[vertex.dst].head;
		while (neighbour != graph.NULL_EDGE) {
			if (sptSet[neighbour->dst] != true) {
				relax(neighbour->src, neighbour->dst, neighbour->weight, heap);
			}
			neighbour = neighbour->next;
		}
	}
	print();
}

void Dijkstra::dijkstraAdjacencyMatrix(int startingVertex) {
	this->startingVertex = startingVertex;

	parent = new int[graph.numberOfVertices];
	distance = new int[graph.numberOfVertices];
	sptSet = new int[graph.numberOfVertices];

	MinHeap heap(graph);
	for (int i = 0; i < graph.numberOfVertices; ++i) {
		parent[i] = i;
		distance[i] = INT_MAX;
		sptSet[i] = false;
	}

	heap.add(new Edge(0, startingVertex, 0));
	distance[startingVertex] = 0;



	while(!heap.isEmpty()) {
		auto vertex = heap.poll();
		sptSet[vertex.dst] = true;

		for (int j = 0; j < graph.numberOfVertices; ++j) {
			auto neighbour = graph.AdjacencyMatrix[vertex.dst][j];
			if (neighbour != graph.NULL_EDGE && sptSet[neighbour->dst] != true) {
				relax(neighbour->src, neighbour->dst, neighbour->weight,heap);
			}
		}
	}
	print();
}

void Dijkstra::relax(int u, int v, int w,MinHeap &heap) {
	if (distance[v] > distance[u] + w) {
		distance[v] = distance[u] + w;
		parent[v] = u;
		heap.add(new Edge(0,v,distance[u]+w));
	}
}

void Dijkstra::print() {
	cout << endl << "Sciezka" << endl;
	for (int i = 1; i < graph.numberOfVertices; ++i) {
		string distancer = to_string(i);
		int vertex = i;
		do {
			distancer.insert(0, to_string(parent[vertex]) + "->");
			vertex = parent[vertex];
		} while (parent[vertex] != vertex);
		cout << distancer << " " << distance[i] << endl;
	}
}

int Dijkstra::shortestDistance() {
	int smallest = INT_MAX, minIndex;

	for (int v = 0; v < graph.numberOfVertices; v++)
		if (sptSet[v] == false && distance[v] <= smallest)
			smallest = distance[v], minIndex = v;

	return minIndex;
}







