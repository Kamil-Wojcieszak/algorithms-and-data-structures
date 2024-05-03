//
// Created by kamil on 04.06.2023.
//

#include <iostream>
#include "BellmanFord.h"

BellmanFord::BellmanFord(Graph graph) {
	this->graph = graph;
}

void BellmanFord::bellmanFordAdjacencyList(int startingVertex) {
	int V = graph.numberOfVertices;
	int distance[V];
	int parent[V];
	for (int i = 0; i < V; i++) {
		parent[i] = i;
		distance[i] = INT_MAX;
	}
	distance[startingVertex] = 0;
	Edge *vertexNeighbours;
	for (int i = 0; i < V - 1; i++) {
		for (int j = 0; j < graph.numberOfVertices; ++j) {
			vertexNeighbours = graph.AdjacencyList[j].head;
			while (vertexNeighbours != graph.NULL_EDGE) {
				int u = vertexNeighbours->src;
				int v = vertexNeighbours->dst;
				int w = vertexNeighbours->weight;
				if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
					distance[v] = distance[u] + w;
					parent[v] = u;
				}
				vertexNeighbours = vertexNeighbours->next;
			}
		}
	}
	for (int j = 0; j < graph.numberOfVertices; ++j) {
		vertexNeighbours = graph.AdjacencyList[j].head;
		while (vertexNeighbours != graph.NULL_EDGE) {
			int u = vertexNeighbours->src;
			int v = vertexNeighbours->dst;
			int w = vertexNeighbours->weight;
			if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
				printf("Wykryto ujemny cykl!\n");
				return; // If negative cycle is detected, simply
				// return
			}
			vertexNeighbours = vertexNeighbours->next;
		}
	}
	print(parent,distance);
}

void BellmanFord::bellmanFordAdjacencyMatrix(int startingVertex) {
	int V = graph.numberOfVertices;
	int distance[V];
	int parent[V];
	for (int i = 0; i < V; i++) {
		parent[i] = i;
		distance[i] = INT_MAX;
	}
	distance[startingVertex] = 0;

	for (int i = 0; i < V - 1; i++) {
		for (int j = 0; j < V; j++) {
			for (int k = 0; k < V; ++k) {
				int u = graph.AdjacencyMatrix[j][k]->src;
				int v = graph.AdjacencyMatrix[j][k]->dst;
				int weight = graph.AdjacencyMatrix[j][k]->weight;
				if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
					distance[v] = distance[u] + weight;
					parent[v] = u;
				}
			}
		}
	}
	for (int i = 0; i < graph.numberOfVertices; i++) {
		for (int j = 0; j < graph.numberOfVertices; ++j) {
			if (graph.AdjacencyMatrix[i][j] == graph.NULL_EDGE)
				continue;
			int u = graph.AdjacencyMatrix[i][j]->src;
			int v = graph.AdjacencyMatrix[i][j]->dst;
			int weight = graph.AdjacencyMatrix[i][j]->weight;
			if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
				printf("Wykryto ujemny cykl!\n");
				return; // If negative cycle is detected, simply
				// return
			}
		}

	}

	print(parent, distance);
}

void BellmanFord::print(int parent[], int distance[]) {
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