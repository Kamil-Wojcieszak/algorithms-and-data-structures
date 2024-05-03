//
// Created by kamil on 12.06.2023.
//

#include "Tests.h"
#include <iostream>
#include <fstream>
#include "Tests.h"
#include "time/Time.h"
#include "Graph/Graph.h"
#include "Kruskal/Kruskal.h"
#include "Prim/Prim.h"
#include "Djikstra/Dijkstra.h"
#include "Ford-Bellman/BellmanFord.h"
#include "Ford-Fulkerson/FordFulkerson.h"
#include <conio.h>

using namespace std;

void Tests::tests() {
	Graph graph;
	int density[3];
	int testRanges[7]; //liczba wierzcholkow
	testRanges[0] = 10;
	testRanges[1] = 20;
	testRanges[2] = 30;
	testRanges[3] = 40;
	testRanges[4] = 50;
	testRanges[5] = 60;
	testRanges[6] = 70;

	density[0] = 20;
	density[1] = 60;
	density[2] = 99;

	Time timeCounter;
	fstream fileTests;
	fileTests.open("K.txt");
	srand(time(NULL));
	for (int j = 0; j < sizeof(testRanges) / sizeof(int); ++j) {
		fileTests << testRanges[j] << ";";
		for (int i = 0; i < sizeof(density) / sizeof(int); i++) {
			graph.generateUndirectedGraph(testRanges[j], density[i]);
			Kruskal kruskal(graph);
			timeCounter.startTime();
			kruskal.kruskalAdjacencyMatrix();
			timeCounter.stopTime();
			fileTests << timeCounter.processTime() << ";";
		}
		fileTests << endl;
	}
	fileTests.close();

	fileTests.open("P.txt");
	srand(time(NULL));
	for (int j = 0; j < sizeof(testRanges) / sizeof(int); ++j) {
		fileTests << testRanges[j] << ";";
		for (int i = 0; i < sizeof(density) / sizeof(int); i++) {
			graph.generateUndirectedGraph(testRanges[j], density[i]);
			Prim prim(graph);
			timeCounter.startTime();
			prim.primAdjacencyMatrix();
			timeCounter.stopTime();
			fileTests << timeCounter.processTime() << ";";
		}
		fileTests << endl;
	}
	fileTests.close();

	fileTests.open("D.txt");
	srand(time(NULL));
	for (int j = 0; j < sizeof(testRanges) / sizeof(int); ++j) {
		fileTests << testRanges[j] << ";";
		for (int i = 0; i < sizeof(density) / sizeof(int); i++) {
			graph.generateDirectedGraph(testRanges[j], density[i]);
			Dijkstra dijkstra(graph);
			timeCounter.startTime();
			dijkstra.dijkstraAdjacencyMatrix(0);
			timeCounter.stopTime();
			fileTests << timeCounter.processTime() << ";";
		}
		fileTests << endl;
	}
	fileTests.close();

	fileTests.open("FB.txt");
	srand(time(NULL));
	for (int j = 0; j < sizeof(testRanges) / sizeof(int); ++j) {
		fileTests << testRanges[j] << ";";
		for (int i = 0; i < sizeof(density) / sizeof(int); i++) {
			graph.generateDirectedGraph(testRanges[j], density[i]);
			BellmanFord bf(graph);
			timeCounter.startTime();
			bf.bellmanFordAdjacencyMatrix(0);
			timeCounter.stopTime();
			fileTests << timeCounter.processTime() << ";";
		}
		fileTests << endl;
	}
	fileTests.close();
	fileTests.open("FF.txt");
	srand(time(NULL));
	for (int j = 0; j < sizeof(testRanges) / sizeof(int); ++j) {
		fileTests << testRanges[j] << ";";
		for (int i = 0; i < sizeof(density) / sizeof(int); i++) {
			graph.generateDirectedGraph(testRanges[j], density[i]);
			FordFulkerson ff(graph);
			timeCounter.startTime();
			ff.fordFulkersonDFSAdjacencyMatrix(0,graph.numberOfVertices-1);
			timeCounter.stopTime();
			fileTests << timeCounter.processTime() << ";";
		}
		fileTests << endl;
	}
	fileTests.close();

	//Matrix


//	fileTests.open("K.txt");
//	srand(time(NULL));
//	for (int j = 0; j < sizeof(testRanges) / sizeof(int); ++j) {
//		fileTests << testRanges[j] << ";";
//		for (int i = 0; i < sizeof(density) / sizeof(int); i++) {
//			graph.generateUndirectedGraph(testRanges[j], density[i]);
//			Kruskal kruskal(graph);
//			timeCounter.startTime();
//			kruskal.kruskalAdjacencyMatrix();
//			timeCounter.stopTime();
//			fileTests << timeCounter.processTime() << ";";
//		}
//		fileTests << endl;
//	}
//	fileTests.close();
//
//	fileTests.open("P.txt");
//	srand(time(NULL));
//	for (int j = 0; j < sizeof(testRanges) / sizeof(int); ++j) {
//		fileTests << testRanges[j] << ";";
//		for (int i = 0; i < sizeof(density) / sizeof(int); i++) {
//			graph.generateUndirectedGraph(testRanges[j], density[i]);
//			Prim prim(graph);
//			timeCounter.startTime();
//			prim.primAdjacencyMatrix();
//			timeCounter.stopTime();
//			fileTests << timeCounter.processTime() << ";";
//		}
//		fileTests << endl;
//	}
//	fileTests.close();
//
//	fileTests.open("D.txt");
//	srand(time(NULL));
//	for (int j = 0; j < sizeof(testRanges) / sizeof(int); ++j) {
//		fileTests << testRanges[j] << ";";
//		for (int i = 0; i < sizeof(density) / sizeof(int); i++) {
//			graph.generateDirectedGraph(testRanges[j], density[i]);
//			Dijkstra dijkstra(graph);
//			timeCounter.startTime();
//			dijkstra.dijkstraAdjacencyMatrix(0);
//			timeCounter.stopTime();
//			fileTests << timeCounter.processTime() << ";";
//		}
//		fileTests << endl;
//	}
//	fileTests.close();
//
//	fileTests.open("FB.txt");
//	srand(time(NULL));
//	for (int j = 0; j < sizeof(testRanges) / sizeof(int); ++j) {
//		fileTests << testRanges[j] << ";";
//		for (int i = 0; i < sizeof(density) / sizeof(int); i++) {
//			graph.generateDirectedGraph(testRanges[j], density[i]);
//			BellmanFord bf(graph);
//			timeCounter.startTime();
//			bf.bellmanFordAdjacencyMatrix(0);
//			timeCounter.stopTime();
//			fileTests << timeCounter.processTime() << ";";
//		}
//		fileTests << endl;
//	}
//	fileTests.close();
}

