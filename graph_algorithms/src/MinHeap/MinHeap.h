#ifndef SDIZO_PROJEKT_MINHEAP_H
#define SDIZO_PROJEKT_MINHEAP_H

#include <string>
#include "Graph/Graph.h"

using namespace std;

class MinHeap {
public:
	MinHeap(Graph graph);

	const int ARRAY_SIZE=321000;
    Edge *array;
    unsigned int size;


    ~MinHeap();

	Graph graph;

    void add(Edge*);

    int isInside(int);

    void generateBinaryHeap(int newSize);

    void buildHeap();

	void loadFromFile(string filename, int structureSize);

	void display(string sp, string sn, int v);

	void shiftDown(int index);

	void shiftUp(int index);

	void removeElement(int index);

	void removeAll();

	int right(int index);

	int left(int index);

	int parent(int index);

	void saveToFile();

	void loadGraphFromAdjacencyList();

	void loadGraphFromAdjacencyMatrix();

	void setGraph(Graph graph);

	void heapSort();

	bool isEmpty();

	Edge poll();
};


#endif //SDIZO_PROJEKT_MINHEAP_H