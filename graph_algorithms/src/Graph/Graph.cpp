//
// Created by kamil on 24.05.2023.
//

#include <iostream>
#include <fstream>
#include <cmath>
#include "Graph.h"

using namespace std;

Graph::Graph() {
	NULL_EDGE = new Edge(0, 0, 0);
	NULL_EDGE->next = nullptr;
	AdjacencyList = nullptr;
	AdjacencyMatrix = nullptr;
}

void Graph::createGraph(int vertices) {
//	deleteGraph();
	NULL_EDGE = new Edge(0, 0, 0);
	NULL_EDGE->next = nullptr;
	numberOfVertices = vertices;
	AdjacencyList = new VertexList[vertices];
	for (int i = 0; i < vertices; i++) {
		AdjacencyList[i].head = NULL_EDGE;
	}

	AdjacencyMatrix = new Edge **[vertices];
	for (int i = 0; i < vertices; i++)
		AdjacencyMatrix[i] = new Edge *[vertices];

	for (int i = 0; i < numberOfVertices; i++) {
		for (int j = 0; j < numberOfVertices; j++) {
			AdjacencyMatrix[i][j] = NULL_EDGE;
		}
	}

}

void Graph::addUndirectedEdge(int src, int dst, int weight) {
	Edge *prevHead;

	prevHead = AdjacencyList[src].head;
	AdjacencyList[src].head = new Edge(src, dst, weight);
	AdjacencyList[src].head->next = prevHead;

	prevHead = AdjacencyList[dst].head;
	AdjacencyList[dst].head = new Edge(dst, src, weight);
	AdjacencyList[dst].head->next = prevHead;

	AdjacencyMatrix[src][dst] = new Edge(src, dst, weight);
	AdjacencyMatrix[dst][src] = new Edge(dst, src, weight);
	numberOfEdges += 2;
}


void Graph::addDirectedEdge(int src, int dst, int weight) {
	Edge *prevHead;

	prevHead = AdjacencyList[src].head;
	AdjacencyList[src].head = new Edge(src, dst, weight);
	AdjacencyList[src].head->next = prevHead;

	AdjacencyMatrix[src][dst] = new Edge(src, dst, weight);
	numberOfEdges += 1;
}

void Graph::printMatrix() {
	cout << endl << " ";
	for (int i = 0; i < numberOfVertices; ++i) {
		cout << " " << i;
	}
	cout << endl;

	for (int i = 0; i < numberOfVertices; i++) {
		cout << i << "|";
		for (int j = 0; j < numberOfVertices; j++) {
			cout << AdjacencyMatrix[i][j]->weight << " ";
		}
		cout << endl;
	}
}

void Graph::generateUndirectedGraph(int numberOfVertices, int density) {
	srand(time(NULL));
	createGraph(numberOfVertices);
//	if (density == 99) {
//		double V = numberOfVertices;
//		double D = density;
//		double edgesToAdd = 2*floor((V * (V - 1) * (D / 100)) / 2);
//
//		Edge *array[numberOfVertices-1];
//		for (int i = 0; i + 1 <= V - 1; ++i) {
//			addUndirectedEdge(i, i + 1, rand() % 10 + 1);
//			array[i] = AdjacencyMatrix[i][i + 1];
//			edgesToAdd -= 2;
//		}
//		int src, dst, wght;
//		for (int i = 0; i < numberOfVertices; ++i) {
//			for (int j = i+2; j < numberOfVertices; ++j) {
//				wght = rand() % 20 + 1;
//				addUndirectedEdge(i, j, wght);
//				edgesToAdd -= 2;
//			}
//		}
//		while (edgesToAdd != 0) {
//			src = rand() % numberOfVertices;
//			dst = rand() % numberOfVertices;
//			if (array[src] != AdjacencyMatrix[src][dst] && AdjacencyMatrix[src][dst]!= NULL_EDGE) {
//				if (!removeUndirectedEdge(src, dst))
//					continue;
//				edgesToAdd += 2;
//			}
//		}
//		return;
//	}
	double V = numberOfVertices;
	double D = density;
	double edgesToAdd = floor((V * (V - 1) * (D / 100)) / 2);
	for (int i = 0; i + 1 <= V - 1; ++i) {
		addUndirectedEdge(i, i + 1, rand() % 10 + 1);
	}
	int remainingEdges = edgesToAdd - numberOfVertices + 1;
	int src, dst, wght;
	for (int i = 0; i < remainingEdges; ++i) {
		src = rand() % numberOfVertices;
		dst = rand() % numberOfVertices;
		if (AdjacencyMatrix[src][dst] != NULL_EDGE || src == dst) {
			i--;
			continue;
		}
		wght = rand() % 20 + 1;
		addUndirectedEdge(src, dst, wght);
	}
}

bool Graph::removeDirectedEdge(int src, int dst) {
	auto edge = AdjacencyList[src].head;
	auto prevEdge = edge;
	while (edge->dst != dst && edge != NULL_EDGE) {
		prevEdge = edge;
		edge = edge->next;
	}
	if (edge == NULL_EDGE)
		return false;
	prevEdge->next = edge->next;
	delete edge;


	edge = AdjacencyMatrix[src][dst];
	AdjacencyMatrix[src][dst] = NULL_EDGE;
	delete edge;
	numberOfEdges-=1;
	return true;


}

bool Graph::removeUndirectedEdge(int src, int dst) {
	if (removeDirectedEdge(src, dst)) {
		removeDirectedEdge(dst, src);
		return true;
	}
	return false;

}

void Graph::generateDirectedGraph(int numberOfVertices, int density) {
//	srand(time(NULL));
//	createGraph(numberOfVertices);
//	if (density == 99) {
//		srand(time(NULL));
//		createGraph(numberOfVertices);
//		double V = numberOfVertices;
//		double D = density;
//		double edgesToAdd = 2 * floor((V * (V - 1) * (D / 100)) / 2);
//
//		Edge *array[numberOfVertices-1];
//		for (int i = 0; i + 1 <= V - 1; ++i) {
//			addDirectedEdge(i, i + 1, rand() % 20 + 1);
//			array[i] = AdjacencyMatrix[i][i + 1];
//			edgesToAdd -= 1;
//		}
//		int src, dst, wght;
//		for (int i = 0; i < numberOfVertices; ++i) {
//			for (int j = 0; j < numberOfVertices; ++j) {
//				if (j==i)
//					continue;
//				wght = rand() % 20 + 1;
//				addDirectedEdge(i, j, wght);
//				edgesToAdd -= 1;
//			}
//		}
//		while (edgesToAdd != 0) {
//			src = rand() % numberOfVertices;
//			dst = rand() % numberOfVertices;
//			if (array[src] != AdjacencyMatrix[src][dst]) {
//				if (!removeDirectedEdge(src, dst))
//					continue;
//				edgesToAdd += 1;
//			}
//		}
//		return;
//	}
	srand(time(NULL));
	createGraph(numberOfVertices);
	double V = numberOfVertices;
	double D = density;
	double edgesToAdd = 2 * floor((V * (V - 1) * (D / 100)) / 2);
	for (int i = 0; i + 1 <= V - 1; ++i) {
		addDirectedEdge(i, i + 1, rand() % 10 + 1);
	}
	int remainingEdges = edgesToAdd - numberOfVertices + 1;
	int src, dst, wght;
	for (int i = 0; i < remainingEdges; ++i) {
		src = rand() % numberOfVertices;
		dst = rand() % numberOfVertices;
		if (AdjacencyMatrix[src][dst] != NULL_EDGE || src == dst) {
			i--;
			continue;
		}
		wght = rand() % 20 + 1;
		addDirectedEdge(src, dst, wght);
	}
}

void Graph::print() {
	printList();
	printMatrix();
}


void Graph::printList() {
	Edge *vertexEdge;
	for (int i = 0; i < numberOfVertices; i++) {
		cout << endl << i << '|';
		vertexEdge = AdjacencyList[i].head;
		while (vertexEdge != NULL_EDGE) {
			cout << "->[" << vertexEdge->dst << " " << vertexEdge->weight << "]";
			vertexEdge = vertexEdge->next;
		}
	}
	cout << endl;
}

void Graph::deleteList() {
	for (int i = 0; i < numberOfVertices; ++i) {
		Edge *prevhead;
		while (AdjacencyList[i].head != NULL_EDGE) {
			prevhead = AdjacencyList[i].head;
			AdjacencyList[i].head = AdjacencyList[i].head->next;
			delete prevhead;
		}
	}
	delete[] AdjacencyList;
	AdjacencyList = nullptr;
}

void Graph::deleteMatrix() {
	for (int i = 0; i < numberOfVertices; ++i) {
		for (int j = 0; j < numberOfVertices; ++j) {
			if (AdjacencyMatrix[i][j] == NULL_EDGE) {
				continue;
			}
			delete AdjacencyMatrix[i][j];
		}
	}
	delete[] AdjacencyMatrix;
	AdjacencyMatrix = nullptr;
}

void Graph::deleteGraph() {
	deleteList();
	deleteMatrix();
	numberOfVertices = 0;
	numberOfEdges=0;
}

void Graph::loadFromFileMst(string fileName) {
	deleteGraph();
	ifstream file(fileName);
	if (!file.is_open()) {
		cout << "Nie mozna otworzyc pliku" << endl;
		return;
	}
	int edges;
	file >> edges >> numberOfVertices;
	createGraph(numberOfVertices);
	int src, dst, wght;
	for (int i = 0; i < edges; i++) {
		file >> src >> dst >> wght;
		addUndirectedEdge(src, dst, wght);
	}
	file.close();
}

int *Graph::loadFromFloat(string fileName) {
	deleteGraph();
	ifstream file(fileName);
	if (!file.is_open()) {
		cout << "Nie mozna otworzyc pliku" << endl;
		return nullptr;
	}
	static int SandT[2];
	int edges, startVertex, endVertex;
	file >> edges >> numberOfVertices >> startVertex >> endVertex;
	createGraph(numberOfVertices);
	int src, dst, wght;
	for (int i = 0; i < edges; i++) {
		file >> src >> dst >> wght;
		addDirectedEdge(src, dst, wght);
	}
	SandT[0] = startVertex;
	SandT[1] = endVertex;
	file.close();
	return SandT;
}

int Graph::loadFromSP(string fileName) {
	deleteGraph();
	ifstream file(fileName);
	if (!file.is_open()) {
		cout << "Nie mozna otworzyc pliku" << endl;
		return -1;
	}
	int edges;
	int startingVertex;
	file >> edges >> numberOfVertices >> startingVertex;
	createGraph(numberOfVertices);
	int src, dst, wght;
	for (int i = 0; i < edges; i++) {
		file >> src >> dst >> wght;
		addDirectedEdge(src, dst, wght);
	}
	file.close();
	return startingVertex;
}


Graph::~Graph() = default;