#include "TabuSearch.h"
#include <time.h>
#include <iostream>
#include "Graph/Graph.h"
#include <algorithm>
#include <random>
#include <fstream>
#include "effolkronium/random.hpp"
#include "GreedyPath/Prim.h"

using Random = effolkronium::random_static;

int TabuSearch::start() {
// Initializing necessary variables and data structures
	vector<vector<int>> tabuMatrix;                     // Tabu search matrix for tracking forbidden moves
	vector<int> permutation = greedyPath;
	vector<int> newPermutation;
	vector<int> next(permutation);                              // Store the next candidate permutation

	result = INF; // Initializing the result to a large value
	int firstToSwap;
	int secondToSwap;
	int nextCost;

	clock_t start; // For measuring time
	double time;


	tabuMatrix.resize(size); // Resizing the tabu search matrix

	for (int j = 0; j < size; ++j) {
		tabuMatrix[j].resize(size, 0); // Initializing tabu search matrix elements to 0
	}

	start = clock(); // Start the timer

	// Continue the algorithm until a stopping condition is met
	while (true) {
		for (int step = 0; step < 15 * size; ++step) {
			firstToSwap = 0;
			secondToSwap = 0;
			nextCost = 1 << 30;

			// Iterate through all possible swaps of elements in the permutation
			for (int first = 1; first < size; ++first) {
				for (int second = first + 1; second < size; ++second) {
					switch (neighbourSwitch) {
						case 0: {
							newPermutation = neighbourInsert(permutation, first, second);
							break;
						}
						case 1: {
							newPermutation = neighbourInvert(permutation, first, second);
							break;
						}
						case 2: {
							newPermutation = neighbourSwap(permutation, first, second);
							break;
						}
					}

					// Calculate the cost of the current permutation
					int currentCost = calculatePath(newPermutation);

					// Update the best solution found if the current one is better
					if (currentCost < result) {
						result = currentCost;
						best = permutation; // Update the best path
						foundTime =
								(clock() - start) / (double) CLOCKS_PER_SEC; // Update time taken to find this solution
					}

					// Update the next candidate solution if it satisfies certain conditions
					if (currentCost < nextCost) {
						if (tabuMatrix[second][first] < step) {
							nextCost = currentCost;
							next = newPermutation; // Update the next candidate permutation

							firstToSwap = second;
							secondToSwap = first;
						}
					}

					time = (clock() - start) / (double) CLOCKS_PER_SEC; // Calculate the current elapsed time

					// Check if the search time has been exceeded
					if (time >= timeBound) {
						// Print the best path found so far and related information
						cout << "Droga: ";

						for (int node: best) {
							cout << node << " ";
						}

						cout << "\nKoszt: " << result << endl;
						cout << "Znaleziono po: " << foundTime << " s " << endl;
						return result; // End the search
					}
				}
			}
			permutation = next; // Update the current permutation
			tabuMatrix[firstToSwap][secondToSwap] += Random::get(step, size +
																	   step); // Increment the corresponding tabu search matrix value
		}

		// Clear the permutation and reinitialize tabu search matrix for the next iteration
		permutation.clear();

		permutation = greedyPath; // Generate a new random permutation

		for (vector<vector<int>>::iterator it = tabuMatrix.begin(); it != tabuMatrix.end(); ++it) {
			it->clear(); // Clear inner vectors of tabu search matrix
		}
		tabuMatrix.clear(); // Clear the entire tabu search matrix

		tabuMatrix.resize(size); // Resize and reinitialize tabu search matrix

		for (vector<vector<int>>::iterator it = tabuMatrix.begin(); it != tabuMatrix.end(); ++it) {
			it->resize(size, 0); // Reset tabu search matrix elements to 0
		}
	}
}


vector<int> TabuSearch::randomPermutation(int _size) {
	std::vector<int> temp;
	temp.reserve(_size);

	for (int i = 0; i < _size; i++) {
		temp.push_back(i);
	}

	shuffle(temp.begin(), temp.end(), std::default_random_engine());

	return temp;
}

int TabuSearch::calculatePath(vector<int> path) {
	int cost = 0;

	for (int i = 0; i < path.size() - 1; ++i) {
		cost += matrix[path[i]][path[i + 1]];
	}

	return cost;
}


void TabuSearch::savePath(string fileName) {
	fileName = "../bin/TS_" + fileName;

	ofstream file;
	file.open(fileName);
	file << size << endl;
	for (int node: best) {
		file << node << endl;
	}
	file.close();
}

TabuSearch::TabuSearch(Graph graph, int time, int neighbourSwitch) {
	Prim prim(graph);
	auto x = prim.getMST();
	x.push_back(0);
	greedyPath = x;
	matrix = graph.getMatrix();
	size = graph.getNodeCount();
	timeBound = time;
	this->neighbourSwitch = neighbourSwitch;
}

TabuSearch::~TabuSearch() {
}

void TabuSearch::saveResults(string fileName) {
	fileName = "../bin/" + fileName;
	ofstream file;
	file.open(fileName, ios_base::app);
	file << size << ";" << "TS" << ";" << result << ";" << timeBound << ";" << foundTime << ";" << neighbourSwitch;
	file << endl;
	file.close();
}

vector<int> TabuSearch::neighbourSwap(vector<int> permutation, int firstArgument, int secondArgument) {
	swap(permutation[firstArgument], permutation[secondArgument]); // Swap elements
	return permutation;
}

vector<int> TabuSearch::neighbourInsert(vector<int> permutation, int firstArgument, int secondArgument) {
	if (firstArgument == secondArgument) {
		return permutation;
	}

	int element_to_move = permutation[firstArgument];
	if (firstArgument < secondArgument) {
		for (int i = firstArgument; i < secondArgument; ++i) {
			permutation[i] = permutation[i + 1];
		}
		permutation[secondArgument] = element_to_move;
	} else {
		for (int i = firstArgument; i > secondArgument + 1; --i) {
			permutation[i] = permutation[i - 1];
		}
		permutation[secondArgument + 1] = element_to_move;
	}

	return permutation;
}

vector<int> TabuSearch::neighbourInvert(vector<int> permutation, int firstArgument, int secondArgument) {
	if (firstArgument == secondArgument) {
		return permutation;
	}

	if (firstArgument < secondArgument) {
		while (firstArgument < secondArgument) {
			swap(permutation[firstArgument], permutation[secondArgument]); // Swap elements
			firstArgument++;
			secondArgument--;
		}
	} else {
		while (firstArgument > secondArgument) {
			swap(permutation[secondArgument], permutation[firstArgument]); // Swap elements
			firstArgument--;
			secondArgument++;
		}
	}
	return permutation;
}
vector<int> TabuSearch::getBestPath() {
    return best;
}