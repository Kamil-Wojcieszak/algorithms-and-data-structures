//
// Created by kamil on 20.03.2024.
//

#pragma once


#include <string>

class Results {
private:
	int arraySize;
	char dataArrangement;
	std::string algorithmName;
	char algorithmParameter;
	unsigned long long time;
public:


	Results(int arraySize, char dataArrangement, std::string algorithmName,
			char algorithmParameters, unsigned long long time);

	void save();
};
