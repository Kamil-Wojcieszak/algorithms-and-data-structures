#ifndef PEA_PROJECT_EPISODE_1_TIME_H
#define PEA_PROJECT_EPISODE_1_TIME_H


#include <chrono>

using namespace std;
using namespace std::chrono;


class Time {
	std::chrono::high_resolution_clock::time_point x;
    high_resolution_clock::time_point startingTime;  // Stores the starting time.
    high_resolution_clock::time_point endTime;       // Stores the ending time.
public:


    void startTime();
    // Function to record the current time as the starting time.

    void stopTime();
    // Function to record the current time as the ending time.

	unsigned long long processTime();
    // Function to calculate and return the time elapsed between start and stop.

};


#endif //PEA_PROJECT_EPISODE_1_TIME_H
