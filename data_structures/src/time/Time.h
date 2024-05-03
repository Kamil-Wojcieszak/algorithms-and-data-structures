#include <iostream>
#include <chrono>

#ifndef PROJECT_SDIZO_TIME_H
#define PROJECT_SDIZO_TIME_H

using namespace std;
using namespace std::chrono;

class Time {
public:
	high_resolution_clock::time_point startingTime;
	high_resolution_clock::time_point endTime;

	void startTime();

	void stopTime();

	long processTime();
};

#endif