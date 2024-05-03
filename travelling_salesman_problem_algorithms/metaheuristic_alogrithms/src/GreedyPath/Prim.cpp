//
// Created by kamil on 27.05.2023.
//

#include <vector>
#include <queue>
#include "Prim.h"
#include "Graph/Graph.h"


bool operator>(const Node &arg1, const Node &arg2) {
    if (arg1.wght > arg2.wght)
        return true;
    else
        return false;
}

bool operator<(const Node &arg1, const Node &arg2) {
    if (arg1.wght < arg2.wght)
        return true;
    else
        return false;
}

bool operator==(const Node &arg1, const Node &arg2) {
    if (arg1.wght == arg2.wght)
        return true;
    else
        return false;
}

Prim::Prim(Graph graph) {
    matrix = graph.getMatrix();
    nodes = graph.getNodeCount();
}


vector<int> Prim::getMST() {
    vector<int> path;
    bool visited[nodes];
    for (int i = 0; i < nodes; i++)
        visited[i] = false;

    visited[0] = true;
    path.push_back(0);

    std::priority_queue<Node, std::vector<Node>, std::greater<>> queue;
    int prev = 0;
    Node node;
    for (int i = 0; i < nodes - 1; i++) {
        for (int v = 0; v < nodes; v++) {
            if (!visited[v] && matrix[prev][v] != INF) {
                node = Node(matrix[prev][v], v);
                queue.push(node);
            }
        }
        visited[prev] = true;
        do {
            node = queue.top();
            queue.pop();
        } while (visited[node.dst]);
        prev = node.dst;
        path.push_back(prev);
    }

    return path;
}
