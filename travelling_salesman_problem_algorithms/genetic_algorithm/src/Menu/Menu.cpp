#include "Menu.h"
#include <iostream>
#include "GeneticAlgorithm/GeneticAlgorithm.h"
#include "Graph/Graph.h"

using namespace std;

void Menu::enable() {
    int select = 0;

    while (true) {
        cout << "Czas : " << time << " s\n";
        cout << "Wielkosc populacji poczatkowej: " << population << "\n";
        cout << "Wspolczynnik mutacji: " << mutations << "\n";
        cout << "Wspolczynnik krzyzowan: " << crosses << "\n";
        cout << graph.getDescription();
        cout << menu;

        cin >> select;

        switch (select) {
            case 1:
                do {
                    cout << "Nazwa pliku> ";
                    cin >> file;
                } while (file == "");
                graph.loadXML(file);
                break;
            case 2:
                do {
                    cout << "Czas> ";
                    cin >> time;
                } while (time==0);
                break;
            case 3:
                do {
                    cout << "Wielkosc populacji poczatkowej> ";
                    cin >> population;
                } while (!population);
                break;
            case 4:
                do {
                    cout << "Wspolczynnik mutacji> ";
                    cin >> mutations;
                } while (mutations == 0);
                break;
            case 5:
                do {
                    cout << "Wspolczynnik krzyzowan> ";
                    cin >> crosses;
                } while (crosses == 0);
                break;

            case 6:
                if (time == 0) {
                    cout << "Nie podano czasu wykonywania \n";
                    cin.get();
                }
                if (mutations == 0) {
                    cout << "Nie podano wspolczynnika mutacji \n";
                    cin.get();
                }
                if (population == 0) {
                    cout << "Nie podano wielkosci populacji \n";
                    cin.get();
                }
                if (crosses == 0) {
                    cout << "Nie podano wspolczynnika krzyzowania \n";
                    cin.get();
                } else {
                    GeneticAlgorithm ga(graph, time, population, crosses, mutations);
                    ga.start(true);
                    cout<<ga.toString();
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
    menu.append("1. Wczytaj graf \n");
    menu.append("2. Wprowadz czas\n");
    menu.append("3. Wprowadz wielkosc populacji poczatkowej\n");
    menu.append("4. Wprowadz wspolczynnik mutacji\n");
    menu.append("5. Wprowadz wspolczynnik krzyzowan\n");
    menu.append("6. Genetic Algorithm\n");
    menu.append("7. Koniec programu\n");
    menu.append("------------------------------\n");
    menu.append("> ");

}


Menu::~Menu() {
}
