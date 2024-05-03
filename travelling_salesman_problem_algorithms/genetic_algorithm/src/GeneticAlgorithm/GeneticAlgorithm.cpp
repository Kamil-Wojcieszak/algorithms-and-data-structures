#include "GeneticAlgorithm.h"
#include <ctime>
#include <iostream>
#include "effolkronium/random.hpp"

using Random = effolkronium::random_static;

// Constructor for GeneticAlgorithm class
GeneticAlgorithm::GeneticAlgorithm(Graph graph, int stop, int population, float crossRate, float mutationRate) {
    best = INT32_MAX;
    matrix = graph.getMatrix();
    size = graph.getNodeCount();
    this->stop = stop;
    populationSize = population;
    this->crossRate = crossRate;
    this->mutationRate = mutationRate;
}

// Calculate the total cost of a given path in the graph
int GeneticAlgorithm::calculatePath(std::vector<int> &path) {
    int result = 0;

    for (int i = 0; i < size - 1; i++)
        result += matrix[path[i]][path[i + 1]];

    result += matrix[path[size - 1]][path[0]];

    return result;
}

// Perform partially-mapped crossover between two parent paths
void GeneticAlgorithm::partiallyCrossover(std::vector<int> &parent1, std::vector<int> &parent2) {
    // Initialization of descendant paths and mapping vectors
    std::vector<int> desc1(size, 0), desc2(size, 0);
    std::vector<int> map1(size, -1), map2(size, -1);
    int begin, end, temp;

    // Select a random subpath for crossover
    do {
        begin = Random::get(2, size - 1);
        end = Random::get(2, size - 1);
    } while ((0 >= (end - begin)) || !begin || !(end - (size - 1)));

    // Perform crossover and update mapping vectors
    for (int i = begin; i <= end; i++) {
        desc1[i] = parent1[i];
        desc2[i] = parent2[i];
        map1[parent1[i]] = parent2[i];
        map2[parent2[i]] = parent1[i];
    }

    for (int p = 1, d = 1; p < size && d < size;) {
        if (d == begin) {
            d = end + 1;
            p = end + 1;
        }
        if (!(isInPath(parent2[p], begin, end, desc1))) {
            desc1[d] = parent2[p];

        } else {
            temp = parent2[p];
            do {
                temp = map1[temp];
            } while (isInPath(temp, begin, end, desc1));

            desc1[d] = temp;
        }
        d++;
        p++;
    }

    for (int p = 1, d = 1; p < size && d < size;) {
        if (d == begin) {
            d = end + 1;
            p = end + 1;
        }
        if (!(isInPath(parent1[p], begin, end, desc2))) {
            desc2[d] = parent1[p];

        } else {
            temp = parent1[p];
            do {
                temp = map2[temp];
            } while (isInPath(temp, begin, end, desc2));

            desc2[d] = temp;
        }
        d++;
        p++;
    }

    // Update parent paths with the generated descendant paths
    parent1.clear();
    parent2.clear();
    parent1 = desc1;
    parent2 = desc2;
}


// Initialization of descendant paths and iterators
void GeneticAlgorithm::orderedCrossover(std::vector<int> &parent1, std::vector<int> &parent2) {
    std::vector<int> desc1(size), desc2(size);
    std::vector<int>::iterator itr1, itr2;
    int begin, end;

    do {
        begin = Random::get(2, size - 2);
        end = Random::get(2, size - 2);
    } while (end < begin);

    for (int i = begin; i <= end; i++) {
        desc1[i] = parent1[i];
        desc2[i] = parent2[i];
    }
    for (int p = 1, d = 1; p < size && d < size;) {
        if (d == begin)
            d = end + 1;
        if (!(isInPath(parent2[p], begin, end, desc1))) {
            desc1[d] = parent2[p];
            d++;
        }
        p++;
    }

    for (int p = 1, d = 1; p < size && d < size;) {
        if (d == begin)
            d = end + 1;
        if (!(isInPath(parent1[p], begin, end, desc2))) {
            desc2[d] = parent1[p];
            d++;
        }
        p++;
    }
    parent1.clear();
    parent2.clear();
    parent1 = desc1;
    parent2 = desc2;
}

// Check if an element is present in a path between specified indices
bool GeneticAlgorithm::isInPath(int element, int begin, int end, std::vector<int> &path) {
    for (int i = begin; i <= end; i++) {
        if (element == path[i])
            return true;
    }
    return false;
}

// Start the genetic algorithm with specified parameters
int GeneticAlgorithm::start(bool crossing) {
    // Initialization of populations, fitness, and permutation vector
    std::vector<std::vector<int>> population, nextPopulation;
    std::vector<int> fitness, permutation;
    int bestPathIndex;
    int tournamentSize = 5;
    int index, result, p1, p2;
    std::clock_t start;

    for (int i = 0; i < size; i++)
        permutation.push_back(i);

    // Generate the initial population
    for (int i = 0; i < populationSize; i++) {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(++permutation.begin(), permutation.end(), std::default_random_engine(seed));
        population.push_back(permutation);
    }

    start = std::clock();

    // Run the genetic algorithm until the specified stop criterion is met
    while (((std::clock() - start) / (CLOCKS_PER_SEC)) < stop) {
        fitness.clear();

        // Evaluate the fitness of individuals in the current population
        for (auto &itr: population)
            fitness.push_back(calculatePath(itr));

        // Select individuals for the next generation using tournament selection
        for (int j = 0; j < populationSize; j++) {
            result = INT32_MAX;

            // Perform tournament selection
            for (int k = 0; k < tournamentSize; k++) {
                index = Random::get(0, populationSize - 1);

                if (fitness[index] < result) {
                    result = fitness[index];
                    permutation.clear();
                    permutation = population[index];
                    auto foundTime = (clock() - start) / (double) CLOCKS_PER_SEC;
                    if (best > result) {
                        best = result;
                        bestPathIndex = index;
                        BestPath bp(foundTime, result);
                        timeRelativeToCost.push_back(bp);
                    }
                }
            }
            nextPopulation.push_back(permutation);
        }

		// Update the current population with the selected individuals
		for (auto &itr: population) {
			itr.clear();
		}


		population.clear();
		population = nextPopulation;


        for (auto &itr: nextPopulation)
            itr.clear();

        nextPopulation.clear();



        // Perform crossover between pairs of individuals
        for (int j = 0; j < (int) (crossRate * (float) populationSize); j += 2) {
            do {
                p1 = Random::get(0, populationSize - 1);
                p2 = Random::get(0, populationSize - 1);
            } while (!(p1 - p2));

            // Perform ordered or partially-mapped crossover based on the 'crossing' parameter
            if (crossing)
                orderedCrossover(population.at(j), population.at(j + 1));
            else
                partiallyCrossover(population.at(j), population.at(j + 1));
        }

        // Perform mutations on selected individuals
        for (int j = 0; j < (int) (mutationRate * (float) populationSize); j++) {
            do {
                p1 = Random::get(0, size - 1);
                p2 = Random::get(0, size - 1);
            } while (!(p1 - p2));

            std::swap(population.at(j)[p1], population.at(j)[p2]);
        }
    }
    bestPath = population[bestPathIndex];

    return best;
}

string GeneticAlgorithm::toString() {
    string msg;
    msg += "Cost: " + to_string(best);
    msg += "\nminPath: ";
    for (int i: bestPath)
        msg += to_string(i) + " ";
    msg += "0";

    return msg;
}

vector<BestPath> GeneticAlgorithm::getTimeRelativeToCost() {
    return timeRelativeToCost;
}

vector<int> GeneticAlgorithm::getFinalPath() {
    return bestPath;
}