//
// Created by kamil on 25.03.2024.
//

#include "Test.h"
#include "Sorts/InsertionSort/InsertionSort.h"
#include "Sorts/QuickSort/QuickSort.h"
#include "Sorts/HeapSort/HeapSort.h"
#include "Sorts/ShellSort/ShellSort.h"
#include "Array/Array.h"
#include <fstream>
#include <vector>
#include "Time/time.h"

void Test::test() {
	Array array;
	Time time;

	vector<char> arrangements = {/*'n', 'a',*/ 'd'};
	vector<int> arraySizes = {1000, 2000, 5000, 10000, 20000, 50000, 100000};


	for (auto arrangement: arrangements) {
		for (auto size: arraySizes) {
			for (int i = 0; i < 10; ++i) {
				switch (arrangement) {
					case 'n': {
						array.generateArray(size);
						break;
					}
					case 'a': {
						array.generateArrayAscending(size);
						break;
					}
					case 'd': {
						array.generateArrayDescending(size);
						break;
					}
				}
				InsertionSort is;
				QuickSort qs;
				HeapSort hs;
				ShellSort sh;
				int *x;

				x = array.getArray();
				time.startTime();
				is.sort(x, size);
				time.stopTime();
				Results(size, arrangement, "InsertionSort", ' ', time.processTime()).save();

				vector<char> qsParameters = {'l', 'm', 'r', 'd'};
				for (auto qsParameter: qsParameters) {
					x = array.getArray();
					time.startTime();
					qs.sort(x, size, qsParameter);
					time.stopTime();
					Results(size, arrangement, "QuickSort", qsParameter, time.processTime()).save();
				}

				x = array.getArray();
				time.startTime();
				hs.sort(x, size);
				time.stopTime();
				Results(size, arrangement, "HeapSort", ' ', time.processTime()).save();

				vector<int> shParameters = {1, 2};
				for (auto shParameter: shParameters) {
					x = array.getArray();
					time.startTime();
					sh.sort(x, size, shParameter);
					time.stopTime();
					Results(size, arrangement, "ShellSort", (char) (shParameter + '0'), time.processTime()).save();
				}


			}
		}
	}
}