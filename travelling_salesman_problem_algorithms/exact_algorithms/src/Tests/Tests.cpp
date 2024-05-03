//
// Created by kamil on 12.06.2023.
//

#include "Tests.h"
#include <iostream>
#include <fstream>
#include "Tests.h"
#include "Time/Time.h"
#include "Graph/Graph.h"
#include <conio.h>
#include "DynamicProgramming/DynamicProgramming.h"
#include "BranchAndBound/BranchAndBound.h"
#include "Bruteforce/Bruteforce.h"

using namespace std;

void Tests::test() {
	Graph graph;
	Time timeCounter;
	fstream fileTests;
	fileTests.open("../bin/test2.csv");
	srand(time(NULL));
	for (int j = 6; j < 20; j++) {
		graph.generateUndirectedGraph(j);
		cout << "Iteration: " << j << "\n";

		if (j < 15) {
			//Brute Force
			cout << "BF" << endl;
			timeCounter.startTime();
			Bruteforce(graph).start();
			timeCounter.stopTime();
			fileTests << timeCounter.processTime() << ";";
		}

		//Branch And Bound
		cout << "BB" << endl;
		timeCounter.startTime();
		BranchAndBound(graph).start();
		timeCounter.stopTime();
		fileTests << timeCounter.processTime() << ";";

		// Dynamic Programming
		cout << "DP" << endl;
		timeCounter.startTime();
		DynamicProgramming(graph).start();
		timeCounter.stopTime();
		fileTests << timeCounter.processTime();

		fileTests << endl;
	}
	fileTests.close();

}