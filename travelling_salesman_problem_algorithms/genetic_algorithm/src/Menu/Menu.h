#pragma once

#include <string>
#include "Graph/Graph.h"

class Menu {
private:

    std::string menu = "";
    std::string file = "";
    Graph graph;
    int time=0;
    int population=0;
    float crosses=0;
    float mutations=0;

public:

    void enable();

    Menu();

    ~Menu();
};

