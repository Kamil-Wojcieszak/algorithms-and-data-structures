
#pragma once
#include "Graph/Graph.h"
#include <vector>

class GeneticAlgorithm
{
private:

    int stop;
    int populationSize;
    float crossRate;
    float mutationRate;
    int **matrix;
    int size;
    int best;
    vector<int> bestPath;
    vector<BestPath> timeRelativeToCost;


public:

    GeneticAlgorithm(Graph graph, int stop, int population, float crossRate, float mutationRate);
    int calculatePath(std::vector<int> &path);
    void orderedCrossover(std::vector<int> &parent1, std::vector<int> &parent2);
    void partiallyCrossover(std::vector<int> &parent1, std::vector<int> &parent2);
    bool isInPath(int element, int begin, int end, std::vector<int> &path);
    int start(bool crossing);
    vector<BestPath> getTimeRelativeToCost();
    vector<int> getFinalPath();
    string toString();
};

