//
// Created by kamil on 20.03.2023.
//

#include <string>
#include <iostream>
#include <fstream>
#include <iterator>
#include"Array.h"
#include "../lib/Random/random.hpp"
#include "Sorts/InsertionSort/InsertionSort.h"

// get base random alias which is auto seeded and has static API and internal state
using Random = effolkronium::random_static;


using namespace std;

Array::Array() {
	array = nullptr;
	sortedArray = nullptr;
	arrayCopy = nullptr;
	N = 0;
}

Array::~Array() {
	delete[] array;
}

int Array::load(const string &filename) {
	delete[] array;

	FILE *file;

	file = fopen(filename.c_str(), "r");
	if (file == nullptr) {
		printf("Nie mozna otworzyc pliku.\n");
		return (-1);
	}
	fscanf(file, "%d", &N);
	array = new int[N];

	for (int i = 0; i < N; i++) {
		fscanf(file, "%d", &array[i]);
	}
	fclose(file);

	return 0;
}

bool Array::isValueInArray(int val) {
	for (int i = 0; i < N; i++) {
		if (array[i] == val) {
			return true;
		}
	}
	return false;
}

void Array::addValue(int idx, int val) {
	int *tmp_tab = new int[++N];
	for (int i = 0; i < idx; i++) {
		tmp_tab[i] = array[i];
	}
	tmp_tab[idx] = val;
	for (int i = idx + 1; i < N; i++) {
		tmp_tab[i] = array[i - 1];
	}
	array = tmp_tab;
}

void Array::deleteFromArray(int idx) {
	int *tmp_tab = new int[N - 1];
	for (int i = 0, j = 0; i < N; i++) {
		if (i != idx) {
			tmp_tab[j] = array[i];
			j++;
		}
	}
	--N;
	delete[] array;
	array = tmp_tab;
}

void Array::printSorted() {
	for (int i = 0; i < N; i++) {
		cout << sortedArray[i] << " ";
	}
}

void Array::printCopy() {
	for (int i = 0; i < N; i++) {
		cout << arrayCopy[i] << " ";
	}
}

void Array::printOriginal() {
	for (int i = 0; i < N; i++) {
		cout << array[i] << " ";
	}
}

void Array::generateArray(int size) {
	N = size;
	delete[] array;

	array = new int[size];
	for (int i = 0; i < size; ++i) {
		array[i] = Random::get(0, 10000);
	}

}

void Array::sortArray() {
	delete[] sortedArray;
	sortedArray = new int[N];

	for (int i = 0; i < N; ++i) {
		sortedArray[i] = array[i];
	}

	InsertionSort is;

	sortedArray = is.sort(sortedArray, N);
}

bool Array::check(int *a1) {
	sortArray();

	for (int i = 0; i < N; ++i) {
		if (a1[i] != sortedArray[i])
			return false;
	}
	return true;
}

void Array::saveTableToFile() {
	fstream table;
	table.open("Array.txt");

	for (int i = 0; i < N; i++) {
		table << array[i];
		table << endl;
	}
	table.close();
}

void Array::deleteArray() {
	delete[] array;
	N = 0;
}

int *Array::getArray() {
	delete[] arrayCopy;
	arrayCopy = new int[N];
	for (int i = 0; i < N; ++i) {
		arrayCopy[i] = array[i];
	}
	return arrayCopy;
}


int Array::getSize() const {
	return N;
}

void Array::generateArrayDescending(int size) {
	N = size;
	delete[] array;

	array = new int[size];
	for (int i = 0, j = N - 1; i < N; i++) {
		array[i] = j--;
	}
}

void Array::generateArrayAscending(int size) {
	N = size;
	delete[] array;

	array = new int[size];
	for (int i = 0; i < size; ++i) {
		array[i] = i;
	}
}

