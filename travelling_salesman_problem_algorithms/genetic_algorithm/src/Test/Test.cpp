//
// Created by Kamil Wojcieszak on 03/01/2024.
//

#include "Test.h"
#include <map>
#include "Graph/Graph.h"
#include "GeneticAlgorithm/GeneticAlgorithm.h"

void Test::test() {
    Graph graph;
    std::map<std::string, int> fileTimes;
    fileTimes["ftv55.xml"] = 120;
    fileTimes["ftv170.xml"] = 240;
    fileTimes["rbg358.xml"] = 360;

    vector<string> fileNames{/*"ftv55.xml",*/ "ftv170.xml"/*, "rbg358.xml"*/};

//    vector<int> populations{100, 500, 1000};
//    vector<int> crossRates{100, 500, 1000};
    vector<float> mutationRates{/*0.02, 0.05,*/ 0.1};
	int population = 5000;
	float crossRate = 0.8;
    for (const auto &fileName: fileNames) {
        graph.loadXML(fileName);
        vector<BestPath> bestCosts;
        int bestFileCost = INF;
        vector<int> bestPath;
        for (auto mutationRate: mutationRates) {

            // OX crossover
            string fileNameTimeRelativeToCostOX =
                    "GA_TimeRelativeToCost_OX_MUTATION_RATE_" + to_string(mutationRate) + "_FILE_" + fileName;
            string fileNamePathOX = "GA_Path_OX_MUTATION_RATE_" + to_string(mutationRate) + "_FILE_" + fileName;
            GeneticAlgorithm gaOX(graph, fileTimes[fileName], population, crossRate, mutationRate);
            int pathCostOX = gaOX.start(true);
            graph.saveTimeRelativeToCost(fileNameTimeRelativeToCostOX, gaOX.getTimeRelativeToCost());
            graph.savePath(fileNamePathOX, pathCostOX, gaOX.getFinalPath());

            // PX crossover
            string fileNameTimeRelativeToCostPX ="GA_TimeRelativeToCost_PX_MUTATION_RATE_" + to_string(mutationRate) + "_FILE_" + fileName;
            string fileNamePathPX = "GA_Path_PX_MUTATION_RATE_" + to_string(mutationRate) + "_FILE_" + fileName;
            GeneticAlgorithm gaPX(graph, fileTimes[fileName], population, crossRate, mutationRate);
            int pathCostPX = gaPX.start(true);
            graph.saveTimeRelativeToCost(fileNameTimeRelativeToCostPX, gaPX.getTimeRelativeToCost());
            graph.savePath(fileNamePathPX, pathCostPX, gaPX.getFinalPath());
        }
    }
}