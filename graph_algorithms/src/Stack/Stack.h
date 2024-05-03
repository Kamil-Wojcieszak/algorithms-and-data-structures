//
// Created by kamil on 04.06.2023.
//

#ifndef SDIZO_PROJEKT_2_STACK_H
#define SDIZO_PROJEKT_2_STACK_H


#include <string>

using namespace std;

struct StackNode {
	int data;
	StackNode* next= nullptr;
	StackNode* prev= nullptr;
};
class Stack {

public:
	StackNode* head;
	StackNode* tail;
	int size=0;
	Stack();

	~Stack();

	int loadFromFile(string FileName);

	int IsValueInList(int value);

	void generateList(int size);

	void push(int value);

	int pop();

	void display();

	void removeIndex(int index);

	void removeAll();

	StackNode *findIndex(int index);


	bool isEmpty();
};


#endif //SDIZO_PROJEKT_2_STACK_H
