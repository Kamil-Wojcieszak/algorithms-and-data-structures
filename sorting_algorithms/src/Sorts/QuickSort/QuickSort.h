//
// Created by kamil on 20.03.2024.
//

#pragma once

class QuickSort {
private:
	static int partition(int *array, int left, int right,char pivotPosition);
	int * sort(int *array, int left, int right, char pivotPosition);
public:

	int *sort(int *array, int N, char pivotPosition);
};
