#pragma once

#include <vector>
#include "Graph/Graph.h"
#include "GreedyPath/Prim.h"

class SimulatedAnnealing {
	double temperatureBuffer = 0;
	double coolingRate = 0;
	double timeBound = 0;
	int **matrix;
	int size;
	Prim prim;
	vector<int> best;
	int result;
	double foundTime = 0;
    double temperature;
public:

	int start();

	vector<int> randomPermutation(int size);
	vector<int> getBestPath();


	double calculateTemperature();

	int calculatePath(vector<int> path);

	double getProbability(int diff, double temperature);

	SimulatedAnnealing(Graph graph, int time, double rate);

	~SimulatedAnnealing();

	void savePath(string fileName);

	void saveResults(string fileName);
};

