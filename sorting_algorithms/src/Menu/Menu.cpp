#include "Menu.h"
#include "Sorts/InsertionSort/InsertionSort.h"
#include "Sorts/QuickSort/QuickSort.h"
#include "Sorts/HeapSort/HeapSort.h"
#include "Sorts/ShellSort/ShellSort.h"
#include "Test/Test.h"
#include <iostream>

using namespace std;

void Menu::showMenu() {
	int select = 0;
	bool enableChecking = false;
	int *sortedArray = nullptr;
	std::cout << std::boolalpha;

	int size = 0;


	while (true) {
		cout << menu;
		cin >> select;

		cout.flush();
		switch (select) {
			case 1: {
				do {
					cout << "Filename> ";
					cin >> file;
				} while (file.empty());
				array.load(file);
				break;
			}
			case 2: {
				do {
					cout << "Array size> ";
					cin >> size;
				} while (size == -1);
				array.generateArray(size);
				break;
			}
			case 3: {
				if (enableChecking) {
					enableChecking = false;
					cout << "Info: checking disabled\n";
				} else {
					enableChecking = true;
					cout << "Info: checking enabled\n";
				}
				break;
			}

			case 4: {
				InsertionSort is;
				sortedArray = is.sort(array.getArray(), array.getSize());
				break;
			}
			case 5: {
				char pivotPosition = ' ';
				do {
					cout << "Pivot position> ";
					cin >> pivotPosition;
				} while (pivotPosition == ' ');
				QuickSort qs;
				sortedArray = qs.sort(array.getArray(), array.getSize(), pivotPosition);
				break;
			}
			case 6: {
				HeapSort hs;
				sortedArray = hs.sort(array.getArray(), array.getSize());
				break;
			}
			case 7: {
				int spaceSelector = 0;
				do {
					cout << "1. Pratt equation 1971\n";
					cout << "2. Tokuda equation 1965\n";
					cout << "Space selector> ";
					cin >> spaceSelector;
				} while (!spaceSelector);
				ShellSort sh;
				sortedArray = sh.sort(array.getArray(), array.getSize(), spaceSelector);
				break;
			}
			case 8:
				Test().test();
				break;
			case 9:
				return;
			default:
				cout << "Error: wrong option chosen\n";
				break;


		}
		if (enableChecking && sortedArray != nullptr) {
			cout << "Array is sorted correctly: " << array.check(sortedArray) << endl;
			cout << "Sorted by Insertion Sort (for comparison): ";
			array.printSorted();
			cout << endl << "Sorted by chosen Algorithm:              : ";
			array.printCopy();


			sortedArray = nullptr;
		}

		cin.ignore();
	}


}

Menu::Menu() {
	menu.append("------------------------------\n");
	menu.append("1. Load array \n");
	menu.append("2. Generate array\n");
	menu.append("3. Enable checking\n");
	menu.append("4. Insertion sort\n");
	menu.append("5. Quick sort\n");
	menu.append("6. Heap sort\n");
	menu.append("7. Shell sort\n");
	menu.append("8. Testing methods\n");
	menu.append("9. End program\n");
	menu.append("------------------------------\n");
	menu.append("> ");
}


Menu::~Menu() = default;
