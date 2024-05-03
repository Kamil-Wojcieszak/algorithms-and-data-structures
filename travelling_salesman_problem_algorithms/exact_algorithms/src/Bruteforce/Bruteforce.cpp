//
// Created by kamil on 24.10.2023.
//
#include <iostream>
#include <vector>
#include <map>
#include "Bruteforce.h"


void Bruteforce::start() {
	int mask = 1;
	int startingNode = 0;
	cost = algorithm(mask, startingNode);
	int index = 0;
	for (int i = 0;; ++i) {
		path[i]=index;
		auto nextIndex = prev[mask][index];
		if (nextIndex==-1) break;
		auto nextMask = mask |(1<< nextIndex);
		mask= nextMask;
		index = nextIndex;
	}
	path[nNodes] = 0;

}


int Bruteforce::algorithm(int mask, int pos) {
	// if mask indicates all node have been visited
	// return cost of going to starting node

	if (mask == VISITED_ALL) {
		return matrix[pos][0];
	}

	int ans = INT_MAX;
	int index;
	//searching for unvisited city
	for (int node = 0; node < nNodes; ++node) {
		//example
		//0100 & 0100 = 0100
		//0100 & 0001 = 0000
		if ((mask & (1 << node)) == 0) {
			int newAns = matrix[pos][node] + algorithm(mask | (1 << node), node);
			if (newAns < ans) {
				ans = newAns;
				index = node;
			}
		}
	}
	prev[mask][pos] = index;
	return ans;
}

string Bruteforce::toString() {
	string msg;
	msg += "Cost: " + to_string(cost);
	msg += "\nminPath: ";
	for (int i = 0; i < nNodes + 1; ++i) {
		msg += to_string(path[i]) + " ";
	}
	return msg;
}


Bruteforce::Bruteforce(Graph graph) {
	matrix = graph.getMatrix();
	nNodes = graph.getNodeCount();
	path = new int[nNodes + 1];
	//making an array to memoize all distinct states
	memo = new int *[1 << nNodes];
	for (int mask = 0; mask < (1 << nNodes); ++mask) {
		memo[mask] = new int[nNodes];
		for (int pos = 0; pos < nNodes; ++pos) {
			memo[mask][pos] = -1;
		}
	}prev = new int *[1 << nNodes];
	for (int mask = 0; mask < (1 << nNodes); ++mask) {
		prev[mask] = new int[nNodes];
		for (int pos = 0; pos < nNodes; ++pos) {
			prev[mask][pos] = -1;
		}
	}
	VISITED_ALL = (1 << nNodes) - 1;
}

Bruteforce::~Bruteforce() {
	for (int i = 0; i < (1 << nNodes); ++i) {
		delete memo[i];
	}
	delete memo;
}
