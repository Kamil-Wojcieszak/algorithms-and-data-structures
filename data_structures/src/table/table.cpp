//
// Created by kamil on 20.03.2023.
//

#include <string>
#include <iostream>
#include <fstream>
#include"table.h"

using namespace std;

Table::Table() {
	tab = NULL;
	cnt = 0;
}

Table::~Table() {
	delete[] tab;
}

int Table::loadFromFile(string FileName) {
	FILE *file;

	file = fopen(FileName.c_str(), "r");
	if (file == NULL) {
		printf("Nie mozna otworzyc pliku.\n");
		return (-1);
	}

	fscanf(file, "%d", &cnt);
	tab = new int[cnt];

	for (int i = 0; i < cnt; i++) {
		fscanf(file, "%d", &tab[i]);
	}
	fclose(file);
	return 0;
}

int Table::loadFromFile(string FileName, int size) {
	FILE *file;

	file = fopen(FileName.c_str(), "r");
	if (file == NULL) {
		printf("Nie mozna otworzyc pliku.\n");
		return (-1);
	}

	cnt = size;
	tab = new int[cnt];

	for (int i = 0; i < cnt; i++) {
		fscanf(file, "%d", &tab[i]);
	}
	fclose(file);
	return 0;
}

bool Table::IsValueInTable(int val) {
	for (int i = 0; i < cnt; i++) {
		if (tab[i] == val) {
			return true;
		}
	}
	return false;
}

void Table::addValue(int index, int value) {
	int *tmp_tab = new int[++cnt];
	for (int i = 0; i < index; i++) {
		tmp_tab[i] = tab[i];
	}
	tmp_tab[index] = value;
	for (int i = index + 1; i < cnt; i++) {
		tmp_tab[i] = tab[i - 1];
	}
	tab = tmp_tab;
}

void Table::deleteFromTable(int index) {
	int *tmp_tab = new int[cnt - 1];
	for (int i = 0, j = 0; i < cnt; i++) {
		if (i != index) {
			tmp_tab[j] = tab[i];
			j++;
		}
	}
	--cnt;
	delete[] tab;
	tab = tmp_tab;
}

void Table::display() {
	cout << "Ilosc elementow w tablicy: " << cnt << "\n";
	for (int i = 0; i < cnt; i++) {
		cout << i << "   " << tab[i] << "\n";
	}
}

void Table::generateTable(int size) {
	cnt = size;
	tab = new int[cnt];
	for (int i = 0; i < cnt; ++i) {
		tab[i] = rand();
	}
}

void Table::saveTableToFile() {
	fstream table;
	table.open("Table.txt");

	for (int i = 0; i < cnt; i++) {
		table << tab[i];
		table << endl;
	}
	table.close();
}

void Table::deleteTab() {
	delete[] tab;
	cnt = 0;
}
