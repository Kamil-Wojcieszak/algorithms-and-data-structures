//
// Created by kamil on 10.10.2023.
//

#include <fstream>
#include "Graph.h"
#include "iostream"

using namespace std;

bool Graph::load(string fileName) {
	fileName = "../bin/" + fileName;
	ifstream file(fileName);
	if (!file.is_open()) {
		cout << "Nie mozna otworzyc pliku" << endl;
		return false;
	}
	file >> numberOfNodes;
	matrix = new int *[numberOfNodes];
	for (int i = 0; i < numberOfNodes; i++) {
		matrix[i] = new int[numberOfNodes];
		for (int j = 0; j < numberOfNodes; ++j) {
			file >> matrix[i][j];
		}
	}
	file.close();
	return true;
}

int **Graph::getMatrix() {
	return matrix;
}

int Graph::getNodeCount() {
	return numberOfNodes;
}

void Graph::addUndirectedEdge(int src, int dst, int weight) {
	matrix[src][dst] = weight;
	matrix[dst][src] = weight;
}

bool Graph::setDiagonal() {
	if (!numberOfNodes)
		return false; // Matrix size is zero; cannot set the diagonal.
	else {
		for (int i = 0; i < numberOfNodes; i++) {
			matrix[i][i] = -1; // Set the diagonal elements to -1.
		}
		return true; // Diagonal set successfully.
	}
}

bool Graph::generateUndirectedGraph(int numberOfVertices) {
	numberOfNodes = numberOfVertices;
	int **buffer = nullptr;
	buffer = new int *[numberOfNodes];

	srand(time(NULL));

	for (int i = 0; i < numberOfNodes; i++) {
		buffer[i] = new int[numberOfNodes];

		for (int j = 0; j < numberOfNodes; j++) {
			buffer[i][j] = rand() % 100 + 1; // Generate random values for the matrix.
		}
	}
//	if (matrix != nullptr) {
//		for (int i = 0; i < numberOfNodes; ++i) {
//			delete matrix[i];
//		}
//		delete matrix;
//	}
	matrix = buffer; // Update the matrix with the randomly generated data.

	setDiagonal(); // Set the diagonal elements.
	return true; // Random matrix generated successfully.

}

string Graph::toString() {
	string graph = "";


	if (numberOfNodes) {
		for (int r = 0; r < numberOfNodes; r++) {
			for (int c = 0; c < numberOfNodes; c++) {
				if ((matrix[r][c] < 10) && (matrix[r][c] >= 0))
					graph += to_string(matrix[r][c]) + "    ";

				else if (((matrix[r][c] < 100) && (matrix[r][c] > 9)) || (matrix[r][c] < 0))
					graph += to_string(matrix[r][c]) + "   ";

				else
					graph += to_string(matrix[r][c]) + "  ";
			}
			graph += "\n";
		}
	} else {
		graph = "Graf pusty\n";
	}
	return graph;
}

Graph::Graph() {
	matrix = nullptr;
}

Graph::~Graph() {

}
