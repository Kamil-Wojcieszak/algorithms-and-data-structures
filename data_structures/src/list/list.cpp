//
// Created by kamil on 20.03.2023.
//

#include <iostream>
#include <fstream>
#include "list.h"

using namespace std;

List::List() {
	head = nullptr;
	tail = nullptr;
}

void List::addNode(int value, int index) {
	ListNode *newNode = new ListNode();
	newNode->data = value;
	if (size == 0) {
		head = newNode;
		tail = newNode;
		size++;
		return;
	}
	ListNode *currentNode = head;

	if (index == size) {
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
		size++;
		return;
	}
	if (index == 0) {
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
		size++;
		return;
	}
	ListNode *previousNode;
	for (int i = 0; i < index; ++i) {
		previousNode = currentNode;
		currentNode = currentNode->next;
	}
	newNode->prev = previousNode;
	newNode->next = currentNode;
	previousNode->next = newNode;
	currentNode->prev = newNode;
	size++;
}

//void List::randomAdd(int value,int index){
//	ListNode *nodeToBeReplaced = findIndex(index);
//	ListNode *newNode = new ListNode();
//	newNode->data=value;
//
//	if (size==0){
//		head=newNode;
//	}
//
//	newNode->prev=nodeToBeReplaced->prev;
//	newNode->next=nodeToBeReplaced;
//	nodeToBeReplaced->prev=newNode;
//	if (nodeToBeReplaced->prev!= nullptr){
//		nodeToBeReplaced->prev->next=newNode;
//		return;
//	}
//
//
//
//
//}

void List::removeValue(int value) {
	int index = IsValueInList(value);
	if (index < 0)
		return;
	removeIndex(index);
}

void List::removeIndex(int index) {
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


void List::removeAll() {
	while (head != nullptr)
		removeIndex(0);
}


// Funkcja wyświetlająca listę od początku do końca
void List::display() {
	// Tworzymy pomocniczy wskaźnik currentNode, który zaczyna od pierwszego elementu listy
	ListNode *currentNode = head;

	// Przechodzimy przez wszystkie elementy listy, dopóki currentNode nie jest równy nullptr
	for (int i = 0; currentNode != nullptr; i++) {
		// Wyświetlamy wartość pola data
		cout << currentNode->data << " ";
		// Przestawiamy wskaźnik currentNode na kolejny element
		currentNode = currentNode->next;
	}

	cout << endl;
	currentNode = tail;
	for (int i = size - 1; currentNode != nullptr; --i) {
		// Wyświetlamy wartość pola data
		cout << currentNode->data << " ";
		// Przestawiamy wskaźnik currentNode na kolejny element
		currentNode = currentNode->prev;
	}

	cout << endl;
}

int List::IsValueInList(int value) {
	ListNode *currentNode = head;
	for (int i = 0; currentNode != nullptr; i++) {
		if (value == currentNode->data)
			return i;
		currentNode = currentNode->next;
	}
	return -1;
}

ListNode* List::findIndex(int index) {
	ListNode *currentNode;
	if (index + 1 > size / 2) {
		currentNode = tail;
		for (int i = size-1; i > index; i--) {
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

void List::generateList(int new_size) {
	while (head != nullptr)
		removeIndex(0);

	for (int i = 0; i < new_size; ++i) {
		addNode(rand(), i);
	}
}

int List::loadFromFile(string FileName) {
	ifstream file(FileName);
	if (!file.is_open()) {
		cout << "Nie mozna otworzyc pliku" << endl;
		return -1;
	}
	while (head != nullptr)
		removeIndex(0);
	int tmp_size;
	file >> tmp_size;
	int data;
	for (int i = 0; i < tmp_size; i++) {
		file >> data;
		addNode(data, i);
	}
	file.close();
}

int List::loadFromFile(string FileName, int cnt) {
	ifstream file(FileName);
	if (!file.is_open()) {
		cout << "Nie mozna otworzyc pliku" << endl;
		return -1;
	}
	while (head != nullptr)
		removeIndex(0);

	int data;
	for (int i = 0; i < cnt; i++) {
		file >> data;
		addNode(data, i);
	}
	file.close();
}

void List::saveToFile() {
	fstream list;
	list.open("Table.txt");
	ListNode *node = head;
	while (node != nullptr) {
		list << node->data;
		list << endl;
		node= node->next;
	}
	list.close();

}

List::~List() {
	while (head != nullptr)
		removeValue(0);
}
