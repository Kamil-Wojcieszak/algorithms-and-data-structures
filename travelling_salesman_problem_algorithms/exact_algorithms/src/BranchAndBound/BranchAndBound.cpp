#include "BranchAndBound.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Custom comparison operators for the Node class
bool operator>(const Node &n1, const Node &n2) {
	if (n1.lBound > n2.lBound)
		return true;
	else
		return false;
}

bool operator<(const Node &n1, const Node &n2) {
	if (n1.lBound < n2.lBound)
		return true;
	else
		return false;
}

bool operator==(const Node &n1, const Node &n2) {
	if (n1.lBound == n2.lBound)
		return true;
	else
		return false;
}

// Implementation of the BranchAndBound class

// Convert the BranchAndBound object to a string for display
string BranchAndBound::toString() {
	string msg;
	msg += "Cost: " + to_string(uBound);
	msg += "\nminPath: ";

	msg += path.toString() + to_string(0);

	return msg;
}

// Calculate the lower bound for a given node and the next vertex
int BranchAndBound::lowerBound(Node arg, int next) {
	int result = arg.lBound;
	result -= minEdges[arg.vertex];
	result += matrix[arg.vertex][next];

	return result;
}

// Entry point for the branch and bound algorithm
void BranchAndBound::start() {
	Node start;
	start.vertex = 0;
	start.lBound = n0LowerBound;

	algorithm(start);
}

// Recursive function for the branch and bound algorithm
void BranchAndBound::algorithm(Node node) {
	helperPath.push(node.vertex);
	visited[node.vertex] = true;
	Node temp;
	priority_queue<Node, vector<Node>, greater<Node>> bounds;

	// Calculate the lower bound for each unvisited node and add to the priority queue
	for (int i = 0; i < nNodes; i++) {
		if (!visited[i]) {
			temp.vertex = i;
			temp.lBound = lowerBound(node, i);
			bounds.push(temp);
		}
	}

	// If no more unvisited nodes, update the upper bound if a better solution is found
	if (bounds.empty()) {
		if (lowerBound(node, 0) < uBound) {
			uBound = lowerBound(node, 0);
			helperPath.copy(&path);
		}
	} else {
		// Explore each branch in order of increasing lower bound
		while (!bounds.empty()) {
			temp = bounds.top();
			bounds.pop();

			if (temp.lBound < uBound) {
				algorithm(temp);
			} else
				break;
		}
	}
	helperPath.pop();
	visited[node.vertex] = false;
}

// Constructor for the BranchAndBound class, initializes data members based on the given graph
BranchAndBound::BranchAndBound(Graph graph) {
	nNodes = graph.getNodeCount();
	matrix = graph.getMatrix();
	uBound = INT_MAX;
	tempCost = 0;
	minEdges = new int[nNodes];
	visited = new bool[nNodes];
	n0LowerBound = 0;
	int min = INT_MAX;

	// Calculate the lower bound for the starting node (vertex 0)
	for (int r = 0; r < nNodes; r++) {
		for (int c = 0; c < nNodes; c++) {
			if (matrix[r][c] < min)
				min = matrix[r][c];
		}
		minEdges[r] = min;
		n0LowerBound += min;
		min = INT_MAX;
	}

	// Initialize the visited array
	for (int r = 0; r < nNodes; r++) {
		visited[r] = false;
	}
}

// Destructor for the BranchAndBound class
BranchAndBound::~BranchAndBound() {
	// Clean up dynamically allocated memory if any
}
