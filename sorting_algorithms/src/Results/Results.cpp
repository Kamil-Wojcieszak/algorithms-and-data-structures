//
// Created by kamil on 20.03.2024.
//

#include <iostream>
#include "Results.h"
#include "fstream"

void Results::save() {
	std::string path = "../bin/results/";

	std::string filename = std::string(1,dataArrangement) + "_" +algorithmName+"_"+algorithmParameter+"_"+".txt";

	std::ofstream file;
	file.open(path + filename, std::ios_base::app);

	file << std::to_string(arraySize) + ";" + std::string(1,dataArrangement) + ";" + algorithmName + ";" + std::string(1, algorithmParameter) + ";" +
			std::to_string(time) + "\n";
	file.close();
}

Results::Results(int arraySize, char dataArrangement, std::string algorithmName,
				 char algorithmParameters, unsigned long long time) : arraySize(arraySize),
													   dataArrangement(dataArrangement),
													   algorithmName(algorithmName),
													   algorithmParameter(algorithmParameters),
													   time(time) {}

