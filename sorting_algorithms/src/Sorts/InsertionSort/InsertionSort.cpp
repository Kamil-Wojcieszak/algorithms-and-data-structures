//
// Created by Kamil Wojcieszak on 19/03/2024.
//
#include "InsertionSort.h"

int* InsertionSort::sort(int array[], int N) {
	int key;
	for (int i = 1; i < N; i++) {
		key = array[i];
		int j = i;
		while (j > 0 && array[j - 1] > key) {
			array[j] = array[j - 1];
			j--;
		}
		array[j] = key;
	}

	return array;
}

InsertionSort::InsertionSort() {

}

InsertionSort::~InsertionSort() {

}
