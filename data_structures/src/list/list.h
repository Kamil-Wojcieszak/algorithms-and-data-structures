//
// Created by kamil on 20.03.2023.
//

#ifndef UNTITLED_LIST_H
#define UNTITLED_LIST_H

#include <string>

using namespace std;

struct ListNode {
    int data;
    ListNode* next= nullptr;
    ListNode* prev= nullptr;
};
class List {

public:
    ListNode* head;
    ListNode* tail;
    int size=0;
    List();

    ~List();

    int loadFromFile(string FileName);

    int IsValueInList(int value);

    void generateList(int size);

    void addNode(int value,int index);

    void removeValue(int index);

    void display();

    void removeIndex(int index);

	void removeAll();

	void saveToFile();

	int loadFromFile(string FileName, int cnt);

	ListNode *findIndex(int index);

	void randomAdd(int value, int index);
};

#endif //UNTITLED_LIST_H