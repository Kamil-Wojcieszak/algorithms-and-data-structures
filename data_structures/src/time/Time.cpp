#include <chrono>
#include "Time.h"

using namespace std;
using namespace std::chrono;

void Time::startTime() {
	startingTime = high_resolution_clock::now();
}

void Time::stopTime() {
	endTime = high_resolution_clock::now();
}

long Time::processTime() {

	return duration_cast<nanoseconds>(Time::endTime - Time::startingTime).count();

}