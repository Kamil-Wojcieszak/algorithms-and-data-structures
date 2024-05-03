//
// Created by kamil on 12.06.2023.
//

#include "Tests.h"
#include <iostream>
#include <fstream>
#include "Tests.h"
#include "Time/Time.h"
#include "Graph/Graph.h"
#include "SimulatedAnnealing/SimulatedAnnealing.h"
#include "TabuSearch/TabuSearch.h"

using namespace std;

void Tests::test() {
    Graph graph;
    auto resultsFileName = "_results.csv";

    srand(time(NULL));
    vector<double> temperatureFactors{0.85, 0.9, 0.99};
    vector<int> times{30, 60, 120, 180, 240};


    vector<string> fileNames{"ftv55.xml", "ftv170.xml", "rbg358.xml"};
    for (const auto &file: fileNames) {
        vector<int> bestFilePath;
        int bestFileCost = INF;
        graph.loadXML(file);
        for (auto tempFactor: temperatureFactors) {
            for (int time: times) {
                SimulatedAnnealing sa(graph, time, tempFactor);
                sa.start();
                auto x = sa.start();
                if (x < bestFileCost) {
                    bestFileCost = x;
                    bestFilePath = sa.getBestPath();
                }
                sa.saveResults(resultsFileName);
            }
        }
        graph.savePath("SA_" + file, bestFilePath);
    }
    vector<int> neighbours{0, 1, 2};
    for (string file: fileNames) {
        vector<int> bestFilePath;
        int bestFileCost = INF;
        for (int neighbour: neighbours) {
            for (int time: times) {
                graph.loadXML(file);
                TabuSearch ts(graph, time, neighbour);
                auto x = ts.start();
                ts.saveResults(resultsFileName);
                if (x < bestFileCost) {
                    bestFileCost = x;
                    bestFilePath = ts.getBestPath();
                }
            }
        }
        graph.savePath("TS_" + file, bestFilePath);
    }
//	Graph graph;
//	auto dt = 0.99;
//	auto r = "ftv55.xml";
//	graph.loadXML(r);
////	SimulatedAnnealing sa(graph, 60, dt);
////	sa.start();
////	sa.saveResults("_results.csv");
//
//
//	TabuSearch ts(graph, 5,0);
//	ts.start();
//	ts.saveResults("_results.csv");
}