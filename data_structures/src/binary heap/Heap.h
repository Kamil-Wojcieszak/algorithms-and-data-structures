#ifndef SDIZO_PROJEKT_HEAP_H
#define SDIZO_PROJEKT_HEAP_H

using namespace std;

class Heap {
public:
	const int ARRAY_SIZE=321000;
    int *array;
    unsigned int size;

    Heap();

    ~Heap();

    void add(int);

    int isInside(int);

    void loadFromFile(string fileName);

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
};


#endif //SDIZO_PROJEKT_HEAP_H