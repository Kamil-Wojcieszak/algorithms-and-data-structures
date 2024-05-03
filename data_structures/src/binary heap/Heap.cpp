#include <iostream>
#include <fstream>
#include <cmath>
#include "Heap.h"

using namespace std;

Heap::Heap() {
	Heap::array = new int[ARRAY_SIZE]; // Inicjalizacja pola array na NULL
	Heap::size = 0; // Inicjalizacja pola size na 0
}

Heap::~Heap() {
	if (Heap::size > 0) { // Jeśli rozmiar kopca jest większy niż 0
		delete[]array; // Usuń tablicę array
	}
}

int Heap::left(int index){
	return index*2+1;
}
int Heap::right(int index){
	return index*2+2;
}

int Heap::parent(int index){
	return (index-1)/2;
}
void Heap::shiftUp(int i) {
	if (i == 0) return;
	if (array[i] > array[parent(i)]) {
		swap(array[i], array[parent(i)]);
		shiftUp(parent(i));
	}
}


void Heap::shiftDown(int i) {
	int largest = i;
	int l = left(i);
	int r = right(i);

	if (l < size && array[l] > array[largest])
		largest = l;

	if (r < size && array[r] > array[largest])
		largest = r;

	if (largest != i) {
		swap(array[i], array[largest]);

		shiftDown(largest);
	}
}


void Heap::buildHeap() {
	int startIdx = (size / 2) - 1;
	for (int i = startIdx; i >= 0; i--) {
		shiftDown(i);
	}
}

void Heap::add(int value) {
	size++; // Zwiększ rozmiar kopca o 1
	int i = size - 1;
	array[i] = value;
	shiftUp(i);

}

void Heap::removeAll(){
	size=0;
}

void Heap::removeElement(int index){
	array[index] = array[size - 1];
	size--;
	shiftUp(index);
	shiftDown(index);
}

int Heap::isInside(int value) {
	for (int i = 0; i < size; i++) {
		if (array[i] == value) {
			return i;
		}
	}
	return -1;
}


void Heap::display(string sp, string sn, int v) {
	string s;
	string cr, cl, cp;
	cr = cl = cp = "  ";
	cr[0] = 218;
	cr[1] = 196;
	cl[0] = 192;
	cl[1] = 196;
	cp[0] = 179;
	if (v < size) {
		s = sp;
		if (sn == cr) s[s.length() - 2] = ' ';
		display(s + cp, cr, 2 * v + 2);

		s = s.substr(0, sp.length() - 2);

		cout << s << sn << array[v] << endl;

		s = sp;
		if (sn == cl) s[s.length() - 2] = ' ';
		display(s + cp, cl, 2 * v + 1);
	}
}

void Heap::loadFromFile(string filename) {
	ifstream file(filename);
	if (!file.is_open()) {
		cout << "Nie mozna otworzyc pliku" << endl;
		return;
	}
	file >> size;

	for (int i = 0; i < size; i++) {
		file >> array[i];
	}
	buildHeap();
}

void Heap::loadFromFile(string filename, int structureSize) {
	ifstream file(filename);
	if (!file.is_open()) {
		cout << "Nie mozna otworzyc pliku" << endl;
		return;
	}
	size=structureSize;
	for (int i = 0; i < structureSize; i++) {
		file >> array[i];
	}
	buildHeap();
}

void Heap::generateBinaryHeap(int newSize) {
	size = newSize;
	delete[] array;
	array = new int[ARRAY_SIZE];
	for (int i = 0; i < size; i++) {
		array[i] = rand();
	}
	buildHeap();
}

void Heap::saveToFile() {
	fstream table;
	table.open("Table.txt");
	for (int i = size - 1; i >= 0; i--) {
		table << array[i];
		table << endl;
	}
	table.close();
}

