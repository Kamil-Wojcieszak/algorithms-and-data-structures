//
// Created by kamil on 24.03.2024.
//

#include "ShellSort.h"
#include <cmath>


int *ShellSort::sort() {
	int k = calculateK_0();
	int space = calculateSpace(k--);

	while (k >= 0) {
		for (int i = space; i < N; i += 1) {
			// add a[i] to the elements that have been gap sorted
			// save a[i] in temp and make a hole at position i
			int temp = array[i];

			// shift earlier gap-sorted elements up until the correct
			// location for a[i] is found
			int j;
			for (j = i; j >= space && array[j - space] > temp; j -= space)
				array[j] = array[j - space];

			//  put temp (the original a[i]) in its correct location
			array[j] = temp;
		}
		space = calculateSpace(k--);
	}

	return array;
}

int ShellSort::calculateSpace(int k) {
	switch (spaceSelector) {
		case 1: {
			int n = (int) (pow(2, k) -1); //Pratt
			return n;
		}
		case 2: {
			int n = ceil(1.8 * pow(2.25, k - 1) - 0.8); //Tokuda
			return n;
		}
	}


}

int ShellSort::calculateK_0() {
	int k = 0;
	switch (spaceSelector) {
		case 1: {
			while((pow(2, k) - 1)<N)
				k++;
			return --k;
		}
		case 2: {
			while (ceil(1.8 * pow(2.25, k - 1) - 0.8) < N) k++;
			return --k;
		}
	}
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wshadow"

int *ShellSort::sort(int *array, int N, int spaceSelector) {
	this->array = array;
	this->N = N;
	this->spaceSelector = spaceSelector;

	return sort();
}

#pragma clang diagnostic pop


ShellSort::ShellSort() {
}

ShellSort::~ShellSort() {

}














