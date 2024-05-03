#pragma once

using namespace std;

class HeapSort {
private:


	static int right(int index);

	static int left(int index);

	static int parent(int index);

	static void siftDown(int *array, int N, int i);

	void display(const string& sp, const string& sn, int v);


	static void buildHeap(int *array, int N);

public:



	HeapSort();

	~HeapSort();


	int* sort(int *array, int N);
};

