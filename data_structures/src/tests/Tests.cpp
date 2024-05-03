#include <iostream>
#include <fstream>
#include "Tests.h"
#include "time/Time.h"
#include "table/table.h"
#include "list/list.h"
#include "binary heap/Heap.h"
#include "tree/Tree.h"
#include <conio.h>

using namespace std;

void Tests::tableTest() {
	int testRanges[8];
	testRanges[0] = 40000;
	testRanges[1] = 80000;
	testRanges[2] = 120000;
	testRanges[3] = 160000;
	testRanges[4] = 200000;
	testRanges[5] = 240000;
	testRanges[6] = 280000;
	testRanges[7] = 320000;
	char opt;
	int repeats = 10;
	int numberOfOperations = 100;
	Time timeCounter;
	Table table;
	fstream fileTests;
	fstream fileTests2;

	do {
		cout << endl << ("--- Test Tablicy ---") << endl;
		cout << "1.  Czas czytania z pliku" << endl;
		cout << "2.  Dodaj i usun z poczatku" << endl;
		cout << "3.  Dodaj i usun z konca" << endl;
		cout << "4.  Dodaj i usun z losowego indeksu" << endl;
		cout << "5.  Znajdz wartosc" << endl;
		cout << "0.  Powrot" << endl;
		cout << "Wybierz opcje: ";


		cin >> opt;
		switch (opt) {
			case '1': {
				srand(time(NULL));
				fileTests.open("TableRead.txt");
				for (int j = 0; j < sizeof(testRanges) / sizeof(int); j++) {
					fileTests << testRanges[j] << ";";
					for (int i = 0; i < repeats; i++) {
						table.generateTable(testRanges[j]);
						table.saveTableToFile();
						table.deleteTab();
						timeCounter.startTime();
						table.loadFromFile("Table.txt", testRanges[j]);
						timeCounter.stopTime();
						fileTests << timeCounter.processTime() << ";";
					}
					fileTests << endl;
				}
				fileTests.close();
				break;
			}


			case '2': {
				int val;
				srand(time(NULL));
				fileTests.open("TableAdd.txt");
				for (int j = 0; j < sizeof(testRanges) / sizeof(int); j++) {
					fileTests << testRanges[j] << ";";
					for (int i = 0; i < repeats; i++) {
						table.deleteTab();
						table.generateTable(testRanges[j]);
						timeCounter.startTime();
						for (int j = 0; j < numberOfOperations; j++) {
							val = rand() % 100;
							table.addValue(0, val);
						}
						timeCounter.stopTime();
						fileTests << timeCounter.processTime() << ";";
					}
					fileTests << endl;
				}
				fileTests.close();
				fileTests.open("TableDelete.txt");
				for (int j = 0; j < sizeof(testRanges) / sizeof(int); j++) {
					fileTests << testRanges[j] << ";";
					for (int i = 0; i < repeats; i++) {
						table.deleteTab();
						table.generateTable(testRanges[j]);
						timeCounter.startTime();
						for (int j = 0; j < numberOfOperations; j++) {
							table.deleteFromTable(0);
						}
						timeCounter.stopTime();
						fileTests << timeCounter.processTime() << ";";
					}
					fileTests << endl;
				}
				fileTests.close();
				break;
			}
			case '3': {
				int val;
				srand(time(NULL));
				fileTests.open("TableAdd.txt");
				for (int j = 0; j < sizeof(testRanges) / sizeof(int); j++) {
					fileTests << testRanges[j] << ";";
					for (int i = 0; i < repeats; i++) {
						table.deleteTab();
						table.generateTable(testRanges[j]);
						timeCounter.startTime();
						for (int j = 0; j < numberOfOperations; j++) {
							val = rand() % 100;
							table.addValue(table.cnt-1, val);
						}
						timeCounter.stopTime();
						fileTests << timeCounter.processTime() << ";";
					}
					fileTests << endl;
				}
				fileTests.close();
				fileTests.open("TableDelete.txt");
				for (int j = 0; j < sizeof(testRanges) / sizeof(int); ++j) {
					fileTests << testRanges[j] << ";";
					for (int i = 0; i < repeats; i++) {
						table.deleteTab();
						table.generateTable(testRanges[j]);
						timeCounter.startTime();
						for (int j = 0; j < numberOfOperations; j++) {
							table.deleteFromTable(table.cnt-1);
						}
						timeCounter.stopTime();
						fileTests << timeCounter.processTime() << ";";
					}
					fileTests << endl;
				}
				fileTests.close();
				break;

			}
			case '4': {
				int val;
				srand(time(NULL));
				fileTests.open("TableAdd.txt");
				for (int j = 0; j < sizeof(testRanges) / sizeof(int); j++) {
					fileTests << testRanges[j] << ";";
					for (int i = 0; i < repeats; i++) {
						table.deleteTab();
						table.generateTable(testRanges[j]);
						timeCounter.startTime();
						for (int j = 0; j < numberOfOperations; j++) {
							val = rand() % 100;
							table.addValue(rand() % table.cnt,val);
						}
						timeCounter.stopTime();
						fileTests << timeCounter.processTime() << ";";
					}
					fileTests << endl;
				}
				fileTests.close();
				fileTests.open("TableDelete.txt");
				for (int j = 0; j < sizeof(testRanges) / sizeof(int); j++) {
					fileTests << testRanges[j] << ";";
					for (int i = 0; i < repeats; i++) {
						table.deleteTab();
						table.generateTable(testRanges[j]);
						timeCounter.startTime();
						for (int j = 0; j < numberOfOperations; j++) {
							table.deleteFromTable(rand() % table.cnt);
						}
						timeCounter.stopTime();
						fileTests << timeCounter.processTime() << ";";
					}
					fileTests << endl;
				}
				fileTests.close();
				break;
			}
			case '5': {
				int val;
				fileTests.open("TableFind.txt");
				srand(time(NULL));
				for (int j = 0; j < sizeof(testRanges) / sizeof(int); ++j) {
					fileTests << testRanges[j] << ";";
					for (int i = 0; i < repeats; i++) {
						table.deleteTab();
						table.generateTable(testRanges[j]);
						timeCounter.startTime();
						for (int j = 0; j < numberOfOperations; j++) {
							table.IsValueInTable(rand());
						}
						timeCounter.stopTime();
						fileTests << timeCounter.processTime() << ";";
					}
					fileTests << endl;
				}
				fileTests.close();
				break;
			}
		}
	} while (opt != '0');
}

void Tests::listTest() {
	int testRanges[8];
	testRanges[0] = 40000;
	testRanges[1] = 80000;
	testRanges[2] = 120000;
	testRanges[3] = 160000;
	testRanges[4] = 200000;
	testRanges[5] = 240000;
	testRanges[6] = 280000;
	testRanges[7] = 320000;
	char opt;
	int repeats = 10;
	int numberOfOperations = 100;
	Time timeCounter;
	List myList;
	fstream fileTests;
	fstream fileTests2;

	do {
		cout << endl << ("--- Test listy ---") << endl;
		cout << "1.  Czas czytania z pliku" << endl;
		cout << "2.  Dodaj i usun z poczatku" << endl;
		cout << "3.  Dodaj i usun z konca" << endl;
		cout << "4.  Dodaj i usun z losowego indeksu" << endl;
		cout << "5.  Znajdz wartosc" << endl;
		cout << "0.  Powrot" << endl;
		cout << "Wybierz opcje: ";


		cin >> opt;
		switch (opt) {
			case '1': {
				srand(time(NULL));
				fileTests.open("TableRead.txt");
				for (int j = 0; j < sizeof(testRanges) / sizeof(int); j++) {
					fileTests << testRanges[j] << ";";
					for (int i = 0; i < repeats; i++) {
						myList.generateList(testRanges[j]);
						myList.saveToFile();
						myList.removeAll();
						timeCounter.startTime();
						myList.loadFromFile("Table.txt", testRanges[j]);
						timeCounter.stopTime();
						fileTests << timeCounter.processTime() << ";";
					}
					fileTests << endl;
				}
				fileTests.close();
				break;
			}


			case '2': {
				int val;
				srand(time(NULL));
				fileTests.open("TableAdd.txt");
				for (int j = 0; j < sizeof(testRanges) / sizeof(int); j++) {
					fileTests << testRanges[j] << ";";
					for (int i = 0; i < repeats; i++) {
						myList.removeAll();
						myList.generateList(testRanges[j]);
						timeCounter.startTime();
						for (int j = 0; j < numberOfOperations; j++) {
							val = rand() % 100;
							myList.addNode(val, 0);
						}
						timeCounter.stopTime();
						fileTests << timeCounter.processTime() << ";";
					}
					fileTests << endl;
				}
				fileTests.close();
				fileTests.open("TableDelete.txt");
				for (int j = 0; j < sizeof(testRanges) / sizeof(int); j++) {
					fileTests << testRanges[j] << ";";
					for (int i = 0; i < repeats; i++) {
						myList.removeAll();
						myList.generateList(testRanges[j]);
						timeCounter.startTime();
						for (int j = 0; j < numberOfOperations; j++) {
							myList.removeIndex(0);
						}
						timeCounter.stopTime();
						fileTests << timeCounter.processTime() << ";";
					}
					fileTests << endl;
				}
				fileTests.close();
				break;
			}
			case '3': {
				int val;
				srand(time(NULL));
				fileTests.open("TableAdd.txt");
				for (int j = 0; j < sizeof(testRanges) / sizeof(int); j++) {
					fileTests << testRanges[j] << ";";
					for (int i = 0; i < repeats; i++) {
						myList.removeAll();
						myList.generateList(testRanges[j]);
						timeCounter.startTime();
						for (int j = 0; j < numberOfOperations; j++) {
							val = rand() % 100;
							myList.addNode(val, myList.size);
						}
						timeCounter.stopTime();
						fileTests << timeCounter.processTime() << ";";
					}
					fileTests << endl;
				}
				fileTests.close();
				fileTests.open("TableDelete.txt");
				for (int j = 0; j < sizeof(testRanges) / sizeof(int); ++j) {
					fileTests << testRanges[j] << ";";
					for (int i = 0; i < repeats; i++) {
						myList.removeAll();
						myList.generateList(testRanges[j]);
						timeCounter.startTime();
						for (int j = 0; j < numberOfOperations; j++) {
							myList.removeIndex(myList.size);
						}
						timeCounter.stopTime();
						fileTests << timeCounter.processTime() << ";";
					}
					fileTests << endl;
				}
				fileTests.close();
				break;

			}
			case '4': {
				int val;
				srand(time(NULL));
				fileTests.open("TableAdd.txt");
				for (int j = 0; j < sizeof(testRanges) / sizeof(int); j++) {
					fileTests << testRanges[j] << ";";
					for (int i = 0; i < repeats; i++) {
						myList.removeAll();
						myList.generateList(testRanges[j]);
						timeCounter.startTime();
						for (int j = 0; j < numberOfOperations; j++) {
							val = rand() % 100;
							myList.addNode(val, rand()%myList.size);
						}
						timeCounter.stopTime();
						fileTests << timeCounter.processTime() << ";";
					}
					fileTests << endl;
				}
				fileTests.close();
				fileTests.open("TableDelete.txt");
				for (int j = 0; j < sizeof(testRanges) / sizeof(int); j++) {
					fileTests << testRanges[j] << ";";
					for (int i = 0; i < repeats; i++) {
						myList.removeAll();
						myList.generateList(testRanges[j]);
						timeCounter.startTime();
						for (int j = 0; j < numberOfOperations; j++) {
							myList.removeIndex(rand()%myList.size);
						}
						timeCounter.stopTime();
						fileTests << timeCounter.processTime() << ";";
					}
					fileTests << endl;
				}
				fileTests.close();
				break;
			}
			case '5': {
				int val;
				fileTests.open("TableFind.txt");
				srand(time(NULL));
				for (int j = 0; j < sizeof(testRanges) / sizeof(int); ++j) {
					fileTests << testRanges[j] << ";";
					for (int i = 0; i < repeats; i++) {
						myList.removeAll();
						myList.generateList(testRanges[j]);
						timeCounter.startTime();
						for (int j = 0; j < numberOfOperations; j++) {
							myList.IsValueInList(rand());
						}
						timeCounter.stopTime();
						fileTests << timeCounter.processTime() << ";";
					}
					fileTests << endl;
				}
				fileTests.close();
				break;
			}
		}
	} while (opt != '0');
}

void Tests::heapTest() {
	int testRanges[8];
	testRanges[0] = 40000;
	testRanges[1] = 80000;
	testRanges[2] = 120000;
	testRanges[3] = 160000;
	testRanges[4] = 200000;
	testRanges[5] = 240000;
	testRanges[6] = 280000;
	testRanges[7] = 320000;
	char opt;
	int repeats = 10;
	int numberOfOperations = 100;
	Time timeCounter;
	Heap myHeap;
	Table myTable;
	fstream fileTests;

	do {
		cout << endl << ("--- Test Kopca ---") << endl;
		cout << "1.  Czas czytania z pliku" << endl;
		cout << "2.  Dodaj i usun" << endl;
		cout << "3.  Znajdz wartosc" << endl;
		cout << "0.  Powrot" << endl;
		cout << "Wybierz opcje: ";


		cin >> opt;
		switch (opt) {
			case '1': {
				srand(time(NULL));
				fileTests.open("TableRead.txt");
				for (int j = 0; j < sizeof(testRanges) / sizeof(int); j++) {
					fileTests << testRanges[j] << ";";
					for (int i = 0; i < repeats; i++) {
						myTable.generateTable(testRanges[j]);
						myTable.saveTableToFile();
						myTable.deleteTab();
						timeCounter.startTime();
						myHeap.loadFromFile("Table.txt", testRanges[j]);
						timeCounter.stopTime();
						fileTests << timeCounter.processTime() << ";";
					}
					fileTests << endl;
				}
				fileTests.close();
				break;
			}


			case '2': {
				int val;
				srand(time(NULL));
				fileTests.open("TableAdd.txt");
				for (int j = 0; j < sizeof(testRanges) / sizeof(int); j++) {
					fileTests << testRanges[j] << ";";
					for (int i = 0; i < repeats; i++) {
						myHeap.removeAll();
						myHeap.generateBinaryHeap(testRanges[j]);
						timeCounter.startTime();
						for (int j = 0; j < numberOfOperations; j++) {
							val = rand() % 100;
							myHeap.add(val);
						}
						timeCounter.stopTime();
						fileTests << timeCounter.processTime() << ";";
					}
					fileTests << endl;
				}
				fileTests.close();
				fileTests.open("TableDelete.txt");
				for (int j = 0; j < sizeof(testRanges) / sizeof(int); j++) {
					fileTests << testRanges[j] << ";";
					for (int i = 0; i < repeats; i++) {
						myHeap.removeAll();
						myHeap.generateBinaryHeap(testRanges[j]);
						timeCounter.startTime();
						for (int j = 0; j < numberOfOperations; j++) {
							myHeap.removeElement(rand()%myHeap.size);
						}
						timeCounter.stopTime();
						fileTests << timeCounter.processTime() << ";";
					}
					fileTests << endl;
				}
				fileTests.close();
				break;
			}
			case '3': {
				int val;
				fileTests.open("TableFind.txt");
				srand(time(NULL));
				for (int j = 0; j < sizeof(testRanges) / sizeof(int); ++j) {
					fileTests << testRanges[j] << ";";
					for (int i = 0; i < repeats; i++) {
						myHeap.removeAll();
						myHeap.generateBinaryHeap(testRanges[j]);
						timeCounter.startTime();
						for (int j = 0; j < numberOfOperations; j++) {
							myHeap.isInside(rand());
						}
						timeCounter.stopTime();
						fileTests << timeCounter.processTime() << ";";
					}
					fileTests << endl;
				}
				fileTests.close();
				break;
			}
		}
	} while (opt != '0');

}

void Tests::treeTest() {
	int testRanges[8];
	testRanges[0] = 40000;
	testRanges[1] = 80000;
	testRanges[2] = 120000;
	testRanges[3] = 160000;
	testRanges[4] = 200000;
	testRanges[5] = 240000;
	testRanges[6] = 280000;
	testRanges[7] = 320000;
	char opt;
	int repeats = 10;
	int numberOfOperations = 100;
	Time timeCounter;
	Tree myTree;
	Table myTable;
	fstream fileTests;

	do {
		cout << endl << ("--- Test Drzewa ---") << endl;
		cout << "1.  Czas czytania z pliku" << endl;
		cout << "2.  Dodaj i usun" << endl;
		cout << "3.  Znajdz wartosc" << endl;
		cout << "0.  Powrot" << endl;
		cout << "Wybierz opcje: ";


		cin >> opt;
		switch (opt) {
			case '1': {
				srand(time(NULL));
				fileTests.open("TableRead.txt");
				for (int j = 0; j < sizeof(testRanges) / sizeof(int); j++) {
					fileTests << testRanges[j] << ";";
					for (int i = 0; i < repeats; i++) {
						myTable.generateTable(testRanges[j]);
						myTable.saveTableToFile();
						myTable.deleteTab();
						timeCounter.startTime();
						myTree.loadFromFile("Table.txt", testRanges[j]);
						timeCounter.stopTime();
						fileTests << timeCounter.processTime() << ";";
					}
					fileTests << endl;
				}
				fileTests.close();
				break;
			}


			case '2': {
				int val;
				srand(time(NULL));
				fileTests.open("TableAdd.txt");
				for (int j = 0; j < sizeof(testRanges) / sizeof(int); j++) {
					fileTests << testRanges[j] << ";";
					for (int i = 0; i < repeats; i++) {
						myTree.removeAll();
						myTree.generateTree(testRanges[j]);
						timeCounter.startTime();
						for (int j = 0; j < numberOfOperations; j++) {
							val = rand() % 100;
							TreeNode* node = new TreeNode();
							node->key-val;
							myTree.insert(node);
						}
						timeCounter.stopTime();
						fileTests << timeCounter.processTime() << ";";
					}
					fileTests << endl;
				}
				fileTests.close();
				fileTests.open("TableDelete.txt");
				for (int j = 0; j < sizeof(testRanges) / sizeof(int); j++) {
					fileTests << testRanges[j] << ";";
					for (int i = 0; i < repeats; i++) {
						myTree.removeAll();
						myTree.generateTree(testRanges[j]);
						timeCounter.startTime();
						for (int j = 0; j < numberOfOperations; j++) {
							myTree.deleteNode(myTree.root);
						}
						timeCounter.stopTime();
						fileTests << timeCounter.processTime() << ";";
					}
					fileTests << endl;
				}
				fileTests.close();
				break;
			}
			case '3': {
				int val;
				fileTests.open("TableFind.txt");
				srand(time(NULL));
				for (int j = 0; j < sizeof(testRanges) / sizeof(int); j++) {
					fileTests << testRanges[j] << ";";
					for (int i = 0; i < repeats; i++) {
						myTree.removeAll();
						myTree.generateTree(testRanges[j]);
						timeCounter.startTime();
						for (int j = 0; j < numberOfOperations; j++) {
							myTree.findNode(rand());
						}
						timeCounter.stopTime();
						fileTests << timeCounter.processTime() << ";";
					}
					fileTests << endl;
				}
				fileTests.close();
				break;
			}
		}
	} while (opt != '0');

}