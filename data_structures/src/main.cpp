#include<string>
#include<iostream>
#include <chrono>
#include <fstream>
#include"table/table.h"
#include "list/list.h"
#include "binary heap/Heap.h"
#include "tree/Tree.h"
#include "tests/Tests.h"


using namespace std;


Table myTab;
List myList;
Heap myHeap;
Tree myTree;
Tests tests;

void displayMenu(string info) {
    cout << endl;
    cout << info << endl;
    cout << "1.Wczytaj z pliku" << endl;
    cout << "2.Usun" << endl;
    cout << "3.Dodaj" << endl;
    cout << "4.Znajdz" << endl;
    cout << "5.Utworz losowo" << endl;
    cout << "6.Wyswietl" << endl;
    cout << "7.Test (pomiary)" << endl;
    cout << "0.Powrot do menu" << endl;
    cout << "Podaj opcje:";
}


void menu_table() {
    char opt;
    string fileName;
    int index, value;


    do {
        displayMenu("--- TABLICA ---");
        cin >> opt;
        cout << endl;
        switch (opt) {
            case '1': //tutaj wczytytwanie  tablicy z pliku
                cout << " Podaj nazwe zbioru:";
                cin >> fileName;
                myTab.loadFromFile(fileName);
                myTab.display();
                break;

            case '2': //tutaj usuwanie elemenu z tablicy
                cout << " podaj index:";
                cin >> index;
                myTab.deleteFromTable(index);
                myTab.display();
                break;

            case '3': //tutaj dodawanie elemetu do tablicy
                cout << " podaj index:";
                cin >> index;
                cout << " podaj waertosc:";
                cin >> value;

                myTab.addValue(index, value);
                myTab.display();
                break;

            case '4': //tutaj znajdowanie elemetu w tablicy
                cout << " podaj wartosc:";
                cin >> value;
                if (myTab.IsValueInTable(value))
                    cout << "poadana wartosc jest w tablicy";
                else
                    cout << "poadanej wartosci NIE ma w tablicy";
                break;

            case '5':  //tutaj generowanie  tablicy
                cout << "Podaj ilosc elementow tablicy:";
                cin >> value;
                myTab.generateTable(value);
                myTab.display();
                break;

            case '6':  //tutaj wyświetlanie tablicy
                myTab.display();
                break;

            case '7':
				tests.tableTest();
                break;
        }

    } while (opt != '0');
    myTab.~Table();
}

void menu_list() {
    char opt;
    string fileName;
    int index, value;


    do {
        displayMenu("--- LISTA ---");
        cin >> opt;
        cout << endl;
        switch (opt) {
            case '1':
                cout << " Podaj nazwe zbioru:";
                cin >> fileName;
                myList.loadFromFile(fileName);
                myList.display();
                break;

            case '2': //tutaj usuwanie elemenu z tablicy
                cout << " podaj wartosc:";
                cin >> index;
                myList.removeValue(index);
                myList.display();
                break;

            case '3': //tutaj dodawanie elemetu do tablicy
                cout << " podaj index:";
                cin >> index;
                cout << " podaj wartosc:";
                cin >> value;

                myList.addNode(value, index);
                myList.display();
                break;

            case '4': //tutaj znajdowanie elemetu w tablicy
                cout << " podaj wartosc:";
                cin >> value;
                if (myList.IsValueInList(value) >= 0)
                    cout << "poadana wartosc jest w liście";
                else
                    cout << "poadanej wartosci NIE ma w liście";
                break;

            case '5':  //tutaj generowanie  tablicy
                cout << "Podaj ilosc elementów listy:";
                cin >> value;
                myList.generateList(value);
                myList.display();
                break;

            case '6':  //tutaj wyświetlanie tablicy
                myList.display();
                break;

            case '7':
				tests.listTest();
                break;
        }

    } while (opt != '0');
}


void menu_tree() {
    char opt;
    string fileName;
    int index, value;


    do {
        displayMenu("--- Drzewo Czerwono-Czarne ---");
        cin >> opt;
        cout << endl;
        switch (opt) {
            case '1': {
                cout << " Podaj nazwe zbioru:";
                cin >> fileName;
                myTree.loadFromFile(fileName);
                myTree.display();
                break;
            }
            case '2': {
                cout << " podaj index:";
                cin >> value;
                TreeNode *node = myTree.findNode(value);
                myTree.deleteNode(node);
                myTree.display();
                break;
            }
            case '3': {
                cout << " podaj waertość:";
                cin >> value;
                TreeNode *newNode = new TreeNode();
                newNode->key = value;
                myTree.insert(newNode);
                myTree.display();
                break;
            }

            case '4': //tutaj znajdowanie elemetu w tablicy
                cout << " podaj wartosc:";
                cin >> value;
                if (myTree.findNode(value) != nullptr)
                    cout << "poadana wartosc jest w drzewie";
                else
                    cout << "poadanej wartosci NIE ma w drzewie";
                break;

            case '5':  //tutaj generowanie  tablicy
                cout << "Podaj ilosc elementów drzewa:";
                cin >> value;
                myTree.generateTree(value);
                myTree.display();
                break;

            case '6':  //tutaj wyświetlanie tablicy
                myTree.display();
                break;
//
            case '7':
				tests.treeTest();
                break;
        }

    } while (opt != '0');
}

void menu_heap() {
    char opt;
    string fileName;
    int index, value;


    do {
        displayMenu("--- KOPIEC ---");
        cin >> opt;
        cout << endl;
        switch (opt) {
            case '1':
                cout << " Podaj nazwe zbioru:";
                cin >> fileName;
                myHeap.loadFromFile(fileName);
                myHeap.display("","",0);
                break;

            case '2': //tutaj usuwanie elemenu z tablicy
				cout << " Podaj indeks elementu:";
				cin >> index;
				myHeap.removeElement(index);
                myHeap.display("","",0);
                break;

            case '3': //tutaj dodawanie elemetu do tablicy
                cout << " podaj wartosc:";
                cin >> value;

                myHeap.add(value);
                myHeap.display("","",0);
                break;

            case '4': //tutaj znajdowanie elemetu w tablicy
                cout << " podaj wartosc:";
                cin >> value;
                if (myHeap.isInside(value))
                    cout << "poadana wartosc jest w kopcu";
                else
                    cout << "poadanej wartosci NIE ma w kopcu";
                break;

            case '5':  //tutaj generowanie  tablicy
                cout << "Podaj ilosc elementów kopca:";
                cin >> value;
                myHeap.generateBinaryHeap(value);
                myHeap.display("","",0);
                break;

            case '6':
                myHeap.display("","",0);
                break;

            case '7':
				tests.heapTest();
                break;
        }

    } while (opt != '0');
}

int main(int argc, char *argv[]) {
    char option;
    do {
        cout << endl;
        cout << "==== MENU GLOWNE ===" << endl;
        cout << "1.Tablica" << endl;
        cout << "2.Lista" << endl;
        cout << "3.Heap" << endl;
        cout << "4.Drzewo Czerwono-Czarne" << endl;
        cout << "0.Wyjscie" << endl;
        cout << "Podaj opcje:";
        cin >> option;
        cout << endl;

        switch (option) {
            case '1':
                menu_table();
                break;

            case '2':
                menu_list();
                break;

            case '3':
                menu_heap();
                break;
            case '4':
                menu_tree();
                break;
        }


    } while (option != '0');


    return 0;
}

