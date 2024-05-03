//
// Created by kamil on 23.04.2023.
//

#ifndef SDIZO_PROJEKT_TREE_H
#define SDIZO_PROJEKT_TREE_H

#include <string>

enum Color {
	Red, Black
};
struct TreeNode {
	int key;
	Color color;
	TreeNode *parent = nullptr;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;
};

class Tree {
public:
	TreeNode *root = nullptr;
	TreeNode *TNIL;
	int size = 0;

	void left_rotate(TreeNode *x);

	void right_rotate(TreeNode *x);

	void insert(TreeNode *x);

	void insert_fixup(TreeNode *z);

	Tree();

	~Tree();

	void loadFromFile(std::string basicString);

	void display();

	void printBT(const std::string &prefix, const TreeNode *node, bool isLeft);

	void transplant(TreeNode *u, TreeNode *v);

	void deleteNode(TreeNode *z);

	TreeNode *findMinimum(TreeNode *x);

	void deleteFixUp(TreeNode *x);

	TreeNode *findNode(int value);

	void generateTree(int cnt);

	void loadFromFile(std::string fileName, int cnt);

	void removeAll();
};


#endif //SDIZO_PROJEKT_TREE_H
