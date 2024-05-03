//
// Created by kamil on 04.06.2023.
//

#include "Stack.h"
#include "Stack.h"

using namespace std;

Stack::Stack() {
	head = nullptr;
	tail = nullptr;
}

Stack::~Stack() {
	while (head != nullptr)
		pop();
}

void Stack::push(int value) {
	StackNode *newNode = new StackNode();
	newNode->data = value;
	if (size == 0) {
		head = newNode;
		tail = newNode;
		size++;
		return;
	}
	newNode->next = head;
	head->prev = newNode;
	head = newNode;
	size++;
	return;
}

int Stack::pop() {
	int test = head->data;
	removeIndex(0);
	return test;
}

void Stack::removeIndex(int index) {
	if (index == 0) {
		// usuwamy pierwszy element listy
		StackNode *nodeToRemove = findIndex(index);
		head = nodeToRemove->next;
		if (head) {
			head->prev = nullptr;
		} else {
			tail = nullptr;
		}
		delete nodeToRemove;
		size--;
		return;
	}
	StackNode *currNode = findIndex(index);
	StackNode *prevNode = currNode->prev;

	prevNode->next = currNode->next;
	if (currNode == tail) {
		tail = prevNode;
	} else {
		currNode->next->prev = prevNode;
	}
	delete currNode;
	size--;
}


void Stack::removeAll() {
	while (head != nullptr)
		removeIndex(0);
}

StackNode *Stack::findIndex(int index) {
	StackNode *currentNode;
	if (index + 1 > size / 2) {
		currentNode = tail;
		for (int i = size - 1; i > index; i--) {
			currentNode = currentNode->prev;
		}
		return currentNode;
	} else {
		currentNode = head;
		for (int i = 0; i != index; i++) {
			currentNode = currentNode->next;
		}
		return currentNode;
	}
}


bool Stack::isEmpty() {
	if (size > 0) { return false; }
	return true;
}


