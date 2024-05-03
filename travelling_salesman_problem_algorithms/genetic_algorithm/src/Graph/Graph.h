#pragma once

#include <string>
#include <vector>

#define INF 100000000

using namespace std;

struct BestPath {
	double time;
	int cost;
	BestPath(double time,int cost){
		this->time = time;
		this->cost = cost;
	}
	BestPath()= default;
};

class Graph {
private:

	int **matrix = nullptr;
	int vert_count = 0;
	string description = "";

public:
	void saveTimeRelativeToCost(string fileName, vector<BestPath> paths);

	string getDescription();

	void printMatrix();

	bool infDiag();

	bool loadSmall(string file);

	int getNodeCount();

	int **getMatrix();

	void generateRandom(int size);

	bool loadXML(string file);

	bool load(string file);

	Graph();

	~Graph();

	void savePath(string fileName, int cost, vector<int> best);
};

