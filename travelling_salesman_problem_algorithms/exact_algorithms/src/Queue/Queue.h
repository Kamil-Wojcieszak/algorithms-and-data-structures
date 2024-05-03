//
// Created by kamil on 04.06.2023.
//

#ifndef SDIZO_PROJEKT_2_QUEUE_H
#define SDIZO_PROJEKT_2_QUEUE_H


#include <string>

using namespace std;

struct ListNode {
	int data;
	ListNode* next= nullptr;
	ListNode* prev= nullptr;
};
class Queue {

public:
	ListNode* head;
	ListNode* tail;
	int size=0;
	Queue();

	~Queue();

	int loadFromFile(string FileName);

	int IsValueInList(int value);

	void generateList(int size);

	void push(int value);

	int pop();

	void display();

	void removeIndex(int index);

	void removeAll();

	ListNode *findIndex(int index);


	bool isEmpty();
};


#endif //SDIZO_PROJEKT_2_QUEUE_H
