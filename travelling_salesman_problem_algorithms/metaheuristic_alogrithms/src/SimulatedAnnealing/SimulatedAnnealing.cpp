#include "SimulatedAnnealing.h"
#include "Graph/Graph.h"
#include "GreedyPath/Prim.h"
#include <vector>
#include <algorithm>
#include <time.h>
#include <iostream>
#include <cstdlib>      // std::rand, std::srand
#include <random>
#include <fstream>
#include "effolkronium/random.hpp"

using Random = effolkronium::random_static;
using namespace std;

// Define the Simulated Annealing class and its methods
int SimulatedAnnealing::start() {
    // Initialize variables
    vector<int> mst = prim.getMST();
    mst.push_back(0);

    vector<int> permutation(mst);

    clock_t start;
    int firstToSwap;
    int secondToSwap;
    temperature = temperatureBuffer;
    result = INF;
    double time = 0;
    start = clock();
    int difference;
    int currCost = calculatePath(mst);
    // Main loop for simulated annealing
    while (time < timeBound && temperature >= pow(10, -15)) {
        // Number of steps for each temperature
        int steps = 600 * size;

        // Iterate over the specified number of steps
        for (int i = steps; i > 0; i--) {
            if (time >= timeBound)
                break;
            vector<int> next = permutation;
            // Generate two random indices to swap
            do {
                firstToSwap = Random::get(1, size - 1);
                secondToSwap = Random::get(1, size - 1);
            } while (firstToSwap == secondToSwap);

            // Swap elements at the generated indices
            swap(next[firstToSwap], next[secondToSwap]);

            // Calculate the cost of the new solution
            int nextCost = calculatePath(next);

            // Calculate the difference between the current and new solutions
            difference = currCost - nextCost;

            // Update the best solution if the new solution is better
            if (difference > 0) {
                result = nextCost;
                currCost = nextCost;
                best = next;
                permutation = next;
                foundTime = (clock() - start) / (double) CLOCKS_PER_SEC;
            } else {
                if (getProbability(difference, temperature) > Random::get<double>(0, 1)) {
                    permutation = next;
                    currCost = nextCost;
                }
            }
            // Check if the specified time bound is reached
            time = (clock() - start) / (double) CLOCKS_PER_SEC;
        }
        // Decrease the temperature according to the cooling rate
        temperature *= coolingRate;


    }
    // Output the best solution and information
    cout << "Droga: ";
    for (int node: best) {
        cout << node << " ";
    }

    cout << "\nKoszt: " << result << endl;
    cout << "Znaleziono po: " << foundTime << " s " << endl;
    cout << "Temperatura koncowa: " << temperature << endl;
    cout << "Wartosc wspolczynnik: " << getProbability(difference, temperature) << endl;
    cout << endl;
    return result;
}

// Generate a random permutation of integers from 0 to _size
vector<int> SimulatedAnnealing::randomPermutation(int _size) {
    vector<int> temp;
    temp.reserve(_size);

    // Fill the vector with consecutive integers
    for (int i = 0; i < _size; i++) {
        temp.push_back(i);
    }

    // Shuffle the vector to create a random permutation
    shuffle(temp.begin(), temp.end(), default_random_engine());

    return temp;
}

// Calculate the initial temperature using a set of random swaps
double SimulatedAnnealing::calculateTemperature() {
    vector<int> origin;

    int firstToSwap;
    int secondToSwap;
    int delta = 0;
    int buffer = 0;

    // Perform a set number of random swaps to estimate the temperature
    for (int i = 0; i < 10000; i++) {
        do {
            firstToSwap = Random::get(1, size - 1);
            secondToSwap = Random::get(1, size - 1);
        } while (firstToSwap == secondToSwap);

        // Generate a random permutation and its neighbor
        origin = randomPermutation(size);
        vector<int> neighbour(origin);
        swap(neighbour[firstToSwap], neighbour[secondToSwap]);

        // Calculate the cost difference between the original and the neighbor
        delta = fabs(calculatePath(origin) - calculatePath(neighbour));
        buffer += delta;
    }

    // Calculate the average cost difference and use it to estimate the initial temperature
    buffer /= 10000;
    return (-1 * buffer) / log(0.99);
}

void SimulatedAnnealing::savePath(string fileName) {
    fileName = "../bin/SA_" + fileName;

    ofstream file;
    file.open(fileName);
    file << size << endl;
    for (int node: best) {
        file << node << endl;
    }
    file << endl;
    file.close();
}

void SimulatedAnnealing::saveResults(string fileName) {
    fileName = "../bin/" + fileName;
    ofstream file;
    file.open(fileName, ios_base::app);
    file << size << ";" << "SA" << ";" << result << ";" << timeBound << ";" << foundTime << ";" << coolingRate << ";"
         << temperature;
    file << endl;
    file.close();
}


// Calculate the cost of a given path
int SimulatedAnnealing::calculatePath(vector<int> path) {
    int cost = 0;

    // Calculate the total cost of the path by summing the distances between consecutive nodes
    for (int i = 0; i < path.size() - 1; ++i) {
        cost += matrix[path[i]][path[i + 1]];
    }
    // Add the distance from the last node to the first node to complete the cycle
//    cost += matrix[path[size - 1]][path[0]];

    return cost;
}

// Calculate the probability of accepting a worse solution
double SimulatedAnnealing::getProbability(int diff, double temperature) {
    // Use the exponential function to determine the acceptance probability
    return exp(diff / temperature);
}

// Constructor for the SimulatedAnnealing class
SimulatedAnnealing::SimulatedAnnealing(Graph graph, int time, double rate) : prim(graph) {
    // Initialize the matrix, size, time bound, cooling rate, and initial temperature
    matrix = graph.getMatrix();
    size = graph.getNodeCount();
    timeBound = time;
    coolingRate = rate;
    temperatureBuffer = calculateTemperature();
    prim = Prim(graph);
}

// Destructor for the SimulatedAnnealing class
SimulatedAnnealing::~SimulatedAnnealing() {
}

vector<int> SimulatedAnnealing::getBestPath() {
    return best;
}
