#include <iostream>
#include <fstream>
#include <cmath>
#include "MinHeap.h"

using namespace std;
MinHeap::MinHeap(Graph graph) {
	array = new Edge[ARRAY_SIZE]; // Inicjalizacja pola array na NULL
	size = 0; // Inicjalizacja pola size na 0
	this->graph=graph;
}

MinHeap::~MinHeap() {
	if (MinHeap::size > 0) { // Jeśli rozmiar kopca jest większy niż 0
		delete[]array; // Usuń tablicę array
	}
}

int MinHeap::left(int index){
	return index*2+1;
}
int MinHeap::right(int index){
	return index*2+2;
}

int MinHeap::parent(int index){
	return (index-1)/2;
}
void MinHeap::shiftUp(int i) {
	if (i == 0) return;
	if (array[i].weight < array[parent(i)].weight) {
		swap(array[i], array[parent(i)]);
		shiftUp(parent(i));
	}
}


void MinHeap::shiftDown(int i) {
	int smallest = i;
	int l = left(i);
	int r = right(i);

	if (l < size && array[l].weight < array[smallest].weight)
		smallest = l;

	if (r < size && array[r].weight < array[smallest].weight)
		smallest = r;

	if (smallest != i) {
		swap(array[i], array[smallest]);

		shiftDown(smallest);
	}
}


void MinHeap::buildHeap() {
	int startIdx = (size / 2) - 1;
	for (int i = startIdx; i >= 0; i--) {
		shiftDown(i);
	}
}

void MinHeap::add(Edge* edge) {
	size++; // Zwiększ rozmiar kopca o 1
	int i = size - 1;
	array[i] = *edge;
	shiftUp(i);

}

void MinHeap::removeAll(){
	size=0;
}

void MinHeap::removeElement(int index){
	array[index] = array[size - 1];
	size--;
	shiftUp(index);
	shiftDown(index);
}

int MinHeap::isInside(int value) {
	for (int i = 0; i < size; i++) {
		if (array[i].weight == value) {
			return i;
		}
	}
	return -1;
}


void MinHeap::display(string sp, string sn, int v) {
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

		cout << s << sn << array[v].weight << endl;

		s = sp;
		if (sn == cl) s[s.length() - 2] = ' ';
		display(s + cp, cl, 2 * v + 1);
	}
}


// Main function to do heap sort
void MinHeap::heapSort()
{
	// MinHeap sort
	for (int i = size - 1; i >= 0; i--) {

		swap(array[0], array[i]);

		// Heapify root element to get highest element at
		// root again
		size--;
		shiftDown(0);
	}
}

void MinHeap::loadGraphFromAdjacencyList() {
	for (int i = 0; i < graph.numberOfVertices; ++i) {
		Edge* edge = graph.AdjacencyList[i].head;
		while(edge != graph.NULL_EDGE){
			add(edge);
			edge=edge->next;
		}
	}
}

void MinHeap::loadGraphFromAdjacencyMatrix() {
	for (int i = 0; i < graph.numberOfVertices; ++i) {
		for (int j = 0; j < graph.numberOfVertices; ++j) {
			auto edge= graph.AdjacencyMatrix[i][j];
			if (edge==graph.NULL_EDGE)
				continue;
			add(edge);
		}
	}
}

bool MinHeap::isEmpty() {
	if (size>0) { return false; }
	return true;
}

Edge MinHeap::poll() {
	Edge edge = array[0];
	removeElement(0);
	return edge;
}

