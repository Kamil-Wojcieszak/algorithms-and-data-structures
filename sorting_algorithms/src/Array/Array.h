//
// Created by kamil on 20.03.2023.
//
#include <string>

#pragma once
using namespace std;

class Array {
private:
	int *array;
	int *sortedArray;
	int *arrayCopy;
	int N;
public:
	Array();

	~Array();

	int *getArray();


	int getSize() const;


	int load(const string& filename);

	bool isValueInArray(int val);

	void addValue(int idx, int val);

	void deleteFromArray(int idx);

	void display();

	void generateArray(int size);

	void deleteArray();

	void saveTableToFile();

	void sortArray();

	bool check(int *a1);

	void printCopy();

	void printSorted();

	void generateArrayDescending(int size);

	void generateArrayAscending(int size);

	void printOriginal();
};