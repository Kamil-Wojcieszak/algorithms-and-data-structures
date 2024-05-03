//
// Created by kamil on 27.05.2023.
//

#pragma once

#include "vector"
#include "Graph/Graph.h"

struct Node {
    int wght;
    int dst;

    Node(int wght, int dst) : wght(wght), dst(dst) {}

    Node() {}
};

class Prim {

private:
    int** matrix;
    int nodes;
public:

    Prim(Graph graph);

    vector<int> getMST();
};