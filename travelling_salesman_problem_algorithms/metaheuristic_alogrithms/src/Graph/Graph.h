#pragma once

#include <string>

#define INF 100000000

using namespace std;

class Graph {
private:

    int **matrix = nullptr;
    int vert_count = 0;
    string description = "";

public:
    void savePath(string fileName, vector<int> path);

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
};

