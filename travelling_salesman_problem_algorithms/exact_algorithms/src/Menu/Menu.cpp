#include <string>
#include "Menu.h"
#include "Graph/Graph.h"
#include "Bruteforce/Bruteforce.h"
#include "DynamicProgramming/DynamicProgramming.h"
#include "Time/Time.h"
#include "BranchAndBound/BranchAndBound.h"
#include "Tests/Tests.h"

void Menu::enable() {
	Graph graph;
	Time timer;
	graph.load("tsp_10.txt");
	while (true) {
		int select = 0;
		string pathName = "";
		bool check = false;

		cout << preview;
		cout << options;

		cin >> select;


		switch (select) {
			case 1: {
				do {
					cout << "Plik> ";
					cin >> pathName;
					check = graph.load(pathName);

					if (!check) {
						cout << "Blad odczytu\n";
					}

				} while (!check);


				preview = "Plik <" + pathName + ">\n\n";
				preview + graph.toString();

				break;
			}

			case 2: {
				if (!graph.getNodeCount()) {
					cout << "Brak danych\n";
					cin.ignore();
					cin.get();
				} else {
					Bruteforce bf(graph);
					timer.startTime();
					bf.start();
					timer.stopTime();
					cout << "------------Brute Force------------\n" + bf.toString() + " \n";
					cout << "Time: " + to_string(timer.processTime()) + "ns";
					cin.ignore();
					cin.get();
				}
				break;
			}

			case 3: {
				if (!graph.getNodeCount()) {
					cout << "Brak danych\n";
					cin.ignore();
					cin.get();
				} else {
					BranchAndBound bb(graph);
					timer.startTime();
					bb.start();
					timer.stopTime();
					cout << "-----------Branch & Bound----------\n" + bb.toString();
					cout << "Time: " + to_string(timer.processTime()) + "ns";
					cin.ignore();
					cin.get();
				}
				break;
			}

			case 4: {
				if (!graph.getNodeCount()) {
					cout << "Brak danych\n";
					cin.ignore();
					cin.get();
				} else {
					DynamicProgramming dp(graph);
					timer.startTime();
					dp.start();
					timer.stopTime();
					cout << "---------Dynamic Programming-------\n" + dp.toString() + "\n";
					cout << "Time: " + to_string(timer.processTime()) + "ns";
					cin.ignore();
					cin.get();
				}

				break;
			}

			case 5: {
				cout << graph.toString();
				cin.ignore();
				cin.get();
				break;
			}
			case 6: {
				int n;
				cout << "Podaj liczbe wierzcholkow: ";
				cin >> n;
				graph.generateUndirectedGraph(n);
				cin.ignore();
				cin.get();
				break;
			}
			case 7: {
				Tests tests;
				tests.test();
				cin.ignore();
				cin.get();
				break;
			}
			case 8: {
				return;
			}
		}
	}
}

Menu::Menu() {
	preview = "";
	options = "";
	options.append("-----------------------------------\n");
	options.append("1. Wczytywanie grafu\n");
	options.append("2. Brute Force\n");
	options.append("3. Branch & Bound\n");
	options.append("4. Dynamic Programming\n");
	options.append("5. Wypisz graf\n");
	options.append("6. Wygeneruj graf\n");
	options.append("7. Wykonaj testy\n");
	options.append("8. Koniec progamu\n");
	options.append("Wybor> ");
}


Menu::~Menu() {
}
