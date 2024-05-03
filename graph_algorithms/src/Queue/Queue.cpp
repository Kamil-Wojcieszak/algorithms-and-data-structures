//
// Created by kamil on 04.06.2023.
//

#include "Queue.h"
#include "Queue.h"

using namespace std;

Queue::Queue() {
	head = nullptr;
	tail = nullptr;
}

Queue::~Queue() {
	while (head != nullptr)
		pop();
}

void Queue::push(int value) {
	ListNode *newNode = new ListNode();
	newNode->data = value;
	if (size == 0) {
		head = newNode;
		tail = newNode;
		size++;
		return;
	}
	tail->next = newNode;
	newNode->prev = tail;
	tail = newNode;
	size++;
	return;

}

int Queue::pop() {
	int test = head->data;
	removeIndex(0);
	return test;
}

void Queue::removeIndex(int index) {
	if (index == 0) {
		// usuwamy pierwszy element listy
		ListNode *nodeToRemove = findIndex(index);
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
	ListNode *currNode = findIndex(index);
	ListNode *prevNode = currNode->prev;

	prevNode->next = currNode->next;
	if (currNode == tail) {
		tail = prevNode;
	} else {
		currNode->next->prev = prevNode;
	}
	delete currNode;
	size--;
}


void Queue::removeAll() {
	while (head != nullptr)
		removeIndex(0);
}

ListNode *Queue::findIndex(int index) {
	ListNode *currentNode;
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


bool Queue::isEmpty() {
	if (size > 0) { return false; }
	return true;
}


