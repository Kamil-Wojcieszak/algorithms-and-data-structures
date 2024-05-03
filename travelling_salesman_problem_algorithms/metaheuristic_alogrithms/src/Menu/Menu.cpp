#include "Menu.h"
#include <iostream>
#include "TabuSearch/TabuSearch.h"
#include "SimulatedAnnealing/SimulatedAnnealing.h"

using namespace std;

void Menu::enable() {
	int select = 0;
	int neighbourhoodSwitch;

	while (true) {
		cout << "Czas : " << time << " s\n";
		cout << "Wspolczynnik dT: " << temperatureFactor << "\n";
		cout << graph.getDescription();
		cout << menu;

		cin >> select;

		switch (select) {
			case 1:
				do {
					cout << "Czas [s]> ";
					cin >> time;
				} while (!time);
				break;

			case 2:
				do {
					cout << "Wspolczynnik dT> ";
					cin >> temperatureFactor;
				} while (temperatureFactor == 0.0);
				break;
			case 3:
				do {
					cout << "0: Insert\n";
					cout << "1: Invert\n";
					cout << "2: Swap\n";
					cout << "Typ sąsiedztwa> ";
					cin >> neighbourhoodSwitch;
				} while (!neighbourhoodSwitch);
				break;
			case 4:
				do {
					cout << "Nazwa pliku> ";
					cin >> file;
				} while (file == "");
				graph.loadXML(file);

				break;

			case 5:
				if (!time) {
					cout << "Nie podano czasu wykonywania ";
					cin.get();
				} else {
					TabuSearch ts(graph, time, neighbourhoodSwitch);
					ts.start();
					cin.get();
				}
				break;

			case 6:
				if (!time || !temperatureFactor) {
					cout << "Nie podano czasu lub wsp�czynnika dT ";
					cin.get();
				} else {
					SimulatedAnnealing sa(graph, time, temperatureFactor);
					sa.start();
					cin.get();
				}
				break;

			case 7:
				return;
		}

		cin.ignore();
		system("cls");
	}


}

Menu::Menu() {
	menu.append("------------------------------\n");
	menu.append("1. Wprowadz czas\n");
	menu.append("2. Wprowadz wspolczynnik dT\n");
	menu.append("3. Wprowadz typ sasiedztwa\n");
	menu.append("4. Wczytaj graf\n");
	menu.append("5. TabuSearch\n");
	menu.append("6. Simulated Annealing\n");
	menu.append("7. Koniec programu\n");
	menu.append("------------------------------\n");
	menu.append("> ");

}


Menu::~Menu() {
}
