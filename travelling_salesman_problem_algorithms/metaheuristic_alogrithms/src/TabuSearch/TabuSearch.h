#pragma once

#include "Graph/Graph.h"
#include <vector>

class TabuSearch {

private:

    int **matrix = nullptr;
    int size = 0;
    int timeBound = 0;
    int result;
    vector<int> best;

    vector<int> randomPermutation(int _size);

    int calculatePath(vector<int> path);

    vector<int> greedyPath;
    double foundTime;
    int neighbourSwitch;

    vector<int> neighbourInsert(vector<int> permutation, int firstArgument, int secondArgument);

    vector<int> neighbourInvert(vector<int> permutation, int firstArgument, int secondArgument);

    vector<int> neighbourSwap(vector<int> permutation, int firstArgument, int secondArgument);

public:
    void savePath(string);

    int start();

    TabuSearch(Graph graph, int time, int neighbourSwitch);

    ~TabuSearch();

    void saveResults(string fileName);

    vector<int> getBestPath();
};

