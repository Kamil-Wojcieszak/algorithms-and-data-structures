//
// Created by kamil on 20.03.2023.
//
#include <string>
#ifndef UNTITLED_TABLE_H
#define UNTITLED_TABLE_H
using namespace std;

class Table {

public:
    int *tab;
    int cnt;


    Table(); //konstruktor - wywoływany automatycznie przy tworzeniu obieku
    ~Table(); //destrukor - wywływany automatycznie przy usuwaniu obiektu

    int loadFromFile(string FileName);

    bool IsValueInTable(int val);

    void addValue(int index, int value);

    void deleteFromTable(int index);

    void display();

    void generateTable(int size);


	void deleteTab();


	void saveTableToFile();

	int loadFromFile(string FileName, int size);
};


#endif //UNTITLED_TABLE_H
