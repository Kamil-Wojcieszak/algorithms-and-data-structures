#include "Graph.h"
#include <fstream>
#include <time.h>
#include <string>
#include <iostream>
#include "tinyxml2-9.0.0/tinyxml2.h"

using namespace tinyxml2;

string Graph::getDescription() {
	if (!vert_count) {
		return "Brak danych\n";
	} else {
		return description;
	}

}

void Graph::saveTimeRelativeToCost(string fileName, vector<BestPath> paths) {
	fileName = "../bin/" + fileName;

	ofstream file;
	file.open(fileName);
	file << vert_count << endl;
	for (BestPath path: paths) {
		file << path.cost << ";" << path.time << endl;
	}
	file.close();
}

bool Graph::infDiag() {
	if (!vert_count)
		return false;
	else {
		for (int i = 0; i < vert_count; i++) {
			matrix[i][i] = INF;
		}
		return true;
	}
}

void Graph::printMatrix() {
	string graph = "";
	graph.append(description);

	cout << "== CURRENT MATRIX ==" << endl << endl;
	cout << graph;

	for (int row = 0; row < vert_count; row++) {
		for (int column = 0; column < vert_count; column++) {
			if (matrix[row][column] == 100000000) {
				printf("%4s", "N"); // Print the matrix elements.
			} else {
				printf("%4d", matrix[row][column]); // Print the matrix elements.
			}
		}
		cout << endl;
	}
}


bool Graph::loadXML(string file) {
	string x = "../bin/" + file;
	const char *fileName = x.c_str();
	int **temp;

	XMLDocument doc;
	doc.LoadFile(fileName);

	if (vert_count) {
		for (int i = 0; i < vert_count; i++) {
			delete[] matrix[i];
		}

		delete[] matrix;
	}

	auto root = doc.FirstChildElement("travellingSalesmanProblemInstance");
	auto graph = root->FirstChildElement("graph");

	vert_count = 0;
	for (auto vertexElement = graph->FirstChildElement("vertex"); vertexElement; vertexElement = vertexElement->NextSiblingElement("vertex")) {
		vert_count++;
	}

	description.append("Name:" + string(root->FirstChildElement("name")->GetText()) + "\n");
	description.append("Description:" + string(root->FirstChildElement("description")->GetText()) + "\n");
	description.append("Vertex count: " + to_string(vert_count) + "\n");


	temp = new int *[vert_count];

	for (int i = 0; i < vert_count; i++) {
		temp[i] = new int[vert_count];
	}


	auto vertex = graph->FirstChildElement("vertex");
	for (int c = 0; c < vert_count; c++) {
		auto edge = vertex->FirstChildElement("edge");
		int r = 0;
		while (edge != nullptr) {
			temp[r][c] = edge->FindAttribute("cost")->DoubleValue();
			edge = edge->NextSiblingElement("edge");
			++r;
		}
		vertex = vertex->NextSiblingElement();
	}

	matrix = temp;
	return true;

}

bool Graph::load(string file) {
	file = "../bin/" + file;
	int **temp;
	description = "";
	string tempDesc = "";

	ifstream fin;
	fin.open(file);

	if (fin.fail() || fin.eof()) {
		return false;
	}

	if (vert_count) {
		for (int i = 0; i < vert_count; i++) {
			delete[] matrix[i];
		}

		delete[] matrix;
	}

	getline(fin, tempDesc);

	description.append(tempDesc + "\n");

	getline(fin, tempDesc);

	description.append(tempDesc + "\n");

	getline(fin, tempDesc);

	description.append(tempDesc + "\n");

	fin >> tempDesc;

	description.append(tempDesc);

	fin >> vert_count;


	description.append(to_string(vert_count) + "\n");


	getline(fin, tempDesc);
	getline(fin, tempDesc);
	getline(fin, tempDesc);
	getline(fin, tempDesc);

	temp = new int *[vert_count];

	for (int i = 0; i < vert_count; i++) {
		temp[i] = new int[vert_count];
	}

	for (int c = 0; c < vert_count; c++) {
		for (int r = 0; r < vert_count; r++) {
			fin >> temp[r][c];
		}
	}

	fin.close();

	matrix = temp;
	return true;
}

bool Graph::loadSmall(string file) {
	file = "../bin/" + file;
	int **temp;

	ifstream fin;
	fin.open(file);

	if (fin.fail() || fin.eof()) {
		return false;
	}

	if (vert_count) {
		for (int i = 0; i < vert_count; i++) {
			delete[] matrix[i];
		}

		delete[] matrix;
	}

	fin >> vert_count;

	temp = new int *[vert_count];

	for (int i = 0; i < vert_count; i++) {
		temp[i] = new int[vert_count];
	}

	for (int r = 0; r < vert_count; r++) {
		for (int c = 0; c < vert_count; c++) {
			fin >> temp[r][c];
		}
	}

	fin.close();

	matrix = temp;
	return true;
}

int Graph::getNodeCount() {
	return vert_count;
}

Graph::Graph() {

}

Graph::~Graph() {

}

int **Graph::getMatrix() {
	return matrix;
}

void Graph::generateRandom(int size) {
	vert_count = size;
	int **buffer = nullptr;
	buffer = new int *[vert_count];

	srand(time(NULL));

	for (int i = 0; i < vert_count; i++) {
		buffer[i] = new int[vert_count];

		for (int j = 0; j < vert_count; j++) {
			buffer[i][j] = rand() % 100 + 1;
		}
	}

	matrix = buffer;

	infDiag();
}

void Graph::savePath(string fileName, int cost, vector<int> best) {
	fileName = "../bin/" + fileName;

	ofstream file;
	file.open(fileName);
	file << cost << endl;
	for (int node: best) {
		file << node << endl;
	}
	file.close();
}
