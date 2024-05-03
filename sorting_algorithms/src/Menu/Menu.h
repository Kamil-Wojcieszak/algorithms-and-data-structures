#pragma once

#include <string>
#include "Array/Array.h"

class Menu {
private:
	std::string menu;
	std::string file;
	Array array;
public:

	void showMenu();

	Menu();

	~Menu();
};

