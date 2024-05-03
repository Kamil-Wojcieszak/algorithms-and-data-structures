//
// Created by kamil on 24.03.2024.
//

#pragma once


class ShellSort {
private:
	int spaceSelector{};
	int *array{};
	int N{};

	int *sort();

public:
	ShellSort();

	~ShellSort();

	int *sort(int *array, int N, int spaceSelector);

	int calculateK_0();

	int calculateSpace(int k);
};
