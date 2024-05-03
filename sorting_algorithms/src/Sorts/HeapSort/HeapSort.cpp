#include <iostream>
#include <cmath>
#include "HeapSort.h"

using namespace std;

HeapSort::HeapSort() = default;

HeapSort::~HeapSort() = default;

int HeapSort::left(int index) {
	return index * 2 + 1;
}

int HeapSort::right(int index) {
	return index * 2 + 2;
}

int HeapSort::parent(int index) {
	return (index - 1) / 2;
}

void HeapSort::siftDown(int *array, int N, int i) { // NOLINT(*-no-recursion)
	int largest = i;
	int l = left(i);
	int r = right(i);

	if (l < N && array[l] > array[largest])
		largest = l;

	if (r < N && array[r] > array[largest])
		largest = r;

	if (largest != i) {
		swap(array[i], array[largest]);
		siftDown(array, N, largest);
	}
}


void HeapSort::buildHeap(int *array, int N) {
	int startIdx = (N / 2) - 1;
	for (int i = startIdx; i >= 0; i--) {
		siftDown(array, N, i);
	}
}

int* HeapSort::sort(int *array, int N) {
	buildHeap(array, N);

	for (int i = N - 1; i > 0; i--) {
		swap(array[0], array[i]);      //zamiana
		siftDown(array, i, 0); //naprawa
	}
	return array;
}
//
//
//#pragma clang diagnostic push
//#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"
//#pragma clang diagnostic ignored "-Wconstant-conversion"
//#pragma ide diagnostic ignored "misc-no-recursion"
//
//void HeapSort::display(const string &sp, const string &sn, int v) {
//	string s;
//	string cr, cl, cp;
//	cr = cl = cp = "  ";
//	cr[0] = 218;
//	cr[1] = 196;
//	cl[0] = 192;
//	cl[1] = 196;
//	cp[0] = 179;
//	if (v < size) {
//		s = sp;
//		if (sn == cr) s[s.length() - 2] = ' ';
//		display(s + cp, cr, 2 * v + 2);
//
//		s = s.substr(0, sp.length() - 2);
//
//		cout << s << sn << array[v] << endl;
//
//		s = sp;
//		if (sn == cl) s[s.length() - 2] = ' ';
//		display(s + cp, cl, 2 * v + 1);
//	}
//}
//
//#pragma clang diagnostic pop
