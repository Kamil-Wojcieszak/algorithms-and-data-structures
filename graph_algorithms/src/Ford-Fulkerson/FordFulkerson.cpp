//
// Created by kamil on 04.06.2023.
//
#include <cstring>
#include "iostream"
#include "FordFulkerson.h"
#include "Graph/Graph.h"
#include "MinHeap/MinHeap.h"
#include "Queue/Queue.h"
#include "Stack/Stack.h"

FordFulkerson::FordFulkerson(Graph graph) {
	this->graph = graph;
}


void FordFulkerson::fordFulkersonBFSAdjacencyMatrix(int startVertex, int endVertex) {
	int u, v;
	auto V = graph.numberOfVertices;
	int **rGraph;
	rGraph = new int *[V];
	for (int i = 0; i < V; ++i) {
		rGraph[i] = new int[V];
	}
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			rGraph[i][j] = graph.AdjacencyMatrix[i][j]->weight;;
		}
	}

	int parent[V]; // This array is filled by BFS and to
	// store path

	int max_flow = 0; // There is no flow initially

	// Augment the flow while there is path from source to
	// sink
	while (bfsAdjacencyMatrix(rGraph, startVertex, endVertex, parent)) {
		// Find minimum residual capacity of the edges along
		// the path filled by BFS. Or we can say find the
		// maximum flow through the path found.
		int path_flow = INT_MAX;
		for (v = endVertex; v != startVertex; v = parent[v]) {
			u = parent[v];
			path_flow = min(path_flow, rGraph[u][v]);
		}

		// update residual capacities of the edges and
		// reverse edges along the path
		for (v = endVertex; v != startVertex; v = parent[v]) {
			u = parent[v];
			rGraph[u][v] -= path_flow;
			rGraph[v][u] += path_flow;
		}

		// Add path flow to overall flow
		max_flow += path_flow;
	}

	// Return the overall flow
	cout << max_flow<<endl;
}

void FordFulkerson::fordFulkersonDFSAdjacencyMatrix(int startVertex, int endVertex) {
	int u, v;
	auto V = graph.numberOfVertices;
	int **rGraph;
	rGraph = new int *[V];
	for (int i = 0; i < V; ++i) {
		rGraph[i] = new int[V];
	}
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			rGraph[i][j] = graph.AdjacencyMatrix[i][j]->weight;;
		}
	}

	int parent[V]; // This array is filled by BFS and to
	// store path

	int max_flow = 0; // There is no flow initially

	// Augment the flow while there is path from source to
	// sink
	while (dfsAdjacencyMatrix(rGraph, startVertex, endVertex, parent, nullptr)) {
		// Find minimum residual capacity of the edges along
		// the path filled by BFS. Or we can say find the
		// maximum flow through the path found.
		int path_flow = INT_MAX;
		for (v = endVertex; v != startVertex; v = parent[v]) {
			u = parent[v];
			path_flow = min(path_flow, rGraph[u][v]);
		}

		// update residual capacities of the edges and
		// reverse edges along the path
		for (v = endVertex; v != startVertex; v = parent[v]) {
			u = parent[v];
			rGraph[u][v] -= path_flow;
			rGraph[v][u] += path_flow;
		}

		// Add path flow to overall flow
		max_flow += path_flow;
	}

	// Return the overall flow
	cout << max_flow << endl;
}


bool FordFulkerson::bfsAdjacencyMatrix(int **residualGraph, int startVertex, int endVertex, int parent[]) {
	bool visited[graph.numberOfVertices];
	for (int i = 0; i < graph.numberOfVertices; ++i) {
		visited[i] = false;
	}
	Queue queue;
	queue.push(startVertex);
	visited[startVertex] = true;
	parent[startVertex] = -1;

	while (!queue.isEmpty()) {
		int u = queue.pop();

		for (int v = 0; v < graph.numberOfVertices; v++) {
			if (visited[v] == false && residualGraph[u][v] > 0) {
				if (v == endVertex) {
					parent[v] = u;
					return true;
				}
				queue.push(v);
				parent[v] = u;
				visited[v] = true;
			}
		}
	}
	return false;
}



bool
FordFulkerson::dfsAdjacencyMatrix(int **residualGraph, int startVertex, int endVertex, int parent[], bool *visited) {
	if (visited == nullptr) {
		visited = new bool[graph.numberOfVertices];
		parent[startVertex] = -1;

		for (int i = 0; i < graph.numberOfVertices; ++i) {
			visited[i] = false;
			parent[i] = i;
		}
	}
	Stack stack;
	stack.push(startVertex);
	visited[startVertex] = true;
	bool isPath = false;


	while (!stack.isEmpty()) {
		int u = stack.pop();
		for (int v = 0; v < graph.numberOfVertices; v++) {
			if (visited[v] == false && residualGraph[u][v] > 0) {
				if (v == endVertex) {
					parent[v] = u;
					return true;
				}
				stack.push(v);
				parent[v] = u;
				visited[v] = true;
				isPath = dfsAdjacencyMatrix(residualGraph, v, endVertex, parent, visited);
				if (isPath)
					return true;
			}
		}
	}
	return false;
}

//void FordFulkerson::print() {
//
//}