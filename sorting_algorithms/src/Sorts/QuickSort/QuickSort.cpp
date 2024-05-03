//
// Created by Kamil Wojcieszak on 19/03/2024.
//

#include <iostream>
#include <cmath>
#include "QuickSort.h"
#include "Random/random.hpp"

using Random = effolkronium::random_static;


int QuickSort::partition(int *array, int left, int right, char pivotPosition) {
	int pivot;
	switch (pivotPosition) {
		case 'l': //left
			pivot = array[left];
			break;
		case 'm': //middle
			pivot = array[((left + right) / 2)];
			break;
		case 'r': //right
			pivot = array[right];
			break;
		case 'd': //random
			pivot = array[Random::get(left, right)];
			break;
		default:
			std::cout << "Error: wrong pivot position option chosen";
			exit(-1);
	}
	int l = left;
	int r = right;
	while (true) {
		while (array[l] < pivot) ++l;
		while (array[r] > pivot) --r;
		if (l < r) {
			std::swap(array[l], array[r]);
			++l;
			--r;
		} else {
			if (r == right) r--;
			return r;
		}
	}
}

int * QuickSort::sort(int *array, int left, int right, char pivotPosition) { // NOLINT(*-no-recursion)
	if (left >= right) return array;
	int m = partition(array, left, right, pivotPosition);
	sort(array, left, m, pivotPosition);
	sort(array, m + 1, right, pivotPosition);
	return array;
}

int* QuickSort::sort(int *array,int N, char pivotPosition) {
	return sort(array,0,N-1,pivotPosition);
}


