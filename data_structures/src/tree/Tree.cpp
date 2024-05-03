//
// Created by kamil on 23.04.2023.
//

#include <fstream>
#include <iostream>
#include "Tree.h"

void Tree::left_rotate(TreeNode *x) {
	TreeNode *y = x->right;
	x->right = y->left;
	if (y->left != TNIL) {
		y->left->parent = x;
	}
	y->parent = x->parent;
	if (x->parent == TNIL) {
		root = y;
	} else if (x == x->parent->left) {
		x->parent->left = y;
	} else {
		x->parent->right = y;
	}
	y->left = x;
	x->parent = y;
}

void Tree::right_rotate(TreeNode *x) {
	TreeNode *y = x->left;
	x->left = y->right;
	if (y->right != TNIL) {
		y->right->parent = x;
	}
	y->parent = x->parent;
	if (x->parent == TNIL) {
		root = y;
	} else if (x == x->parent->right) {
		x->parent->right = y;
	} else {
		x->parent->left = y;
	}
	y->right = x;
	x->parent = y;
}

void Tree::insert(TreeNode *z) {
	TreeNode *x = root;
	TreeNode *y = TNIL;
	while (x != TNIL) {
		y = x;
		if (z->key < x->key) {
			x = x->left;
		} else x = x->right;
	}
	z->parent = y;
	if (y == TNIL) {
		root = z;
	} else if (z->key < y->key) { y->left = z; }
	else { y->right = z; }
	z->left = TNIL;
	z->right = TNIL;
	z->color = Red;
	insert_fixup(z);
	size++;
}

void Tree::insert_fixup(TreeNode *z) {
	TreeNode *y;
	while (z->parent->color == Red) {
		if (z->parent == z->parent->parent->left) {
			y = z->parent->parent->right;
			if (y->color == Red) {
				z->parent->color = Black;
				y->color = Black;
				z->parent->parent->color = Red;
				z = z->parent->parent;
			} else {
				if (z == z->parent->right) {
					z = z->parent;
					left_rotate(z);
				}
				z->parent->color = Black;
				z->parent->parent->color = Red;
				right_rotate(z->parent->parent);
			}
		} else {
			y = z->parent->parent->left;
			if (y->color == Red) {
				z->parent->color = Black;
				y->color = Black;
				z->parent->parent->color = Red;
				z = z->parent->parent;
			} else {
				if (z == z->parent->left) {
					z = z->parent;
					right_rotate(z);
				}
				z->parent->color = Black;
				z->parent->parent->color = Red;
				left_rotate(z->parent->parent);
			}
		}
	}
	root->color = Black;
}

void Tree::transplant(TreeNode *u, TreeNode *v) {
	if (u->parent == TNIL) { root = v; }
	else if (u == u->parent->left) { u->parent->left = v; }
	else { u->parent->right = v; }
	v->parent = u->parent;
}

TreeNode *Tree::findMinimum(TreeNode *x) {
	if (x==TNIL)
		return x->parent;
	while (x->left != TNIL) {
		x = x->left;
	}
	return x;
}

void Tree::deleteNode(TreeNode *z) {
	TreeNode *y = z;
	TreeNode *x;
	Color yOriginalColor = y->color;
	if (z->left == TNIL) {
		x = z->right;
		transplant(z, z->right);
	} else if (z->right == TNIL) {
		x = z->left;
		transplant(z, z->left);
	} else {
		y = findMinimum(z->right);
		yOriginalColor = y->color;
		x = y->right;
		if (y != z->right) {
			transplant(y, y->right);
			y->right = z->right;
			y->right->parent = y;
		} else {
			x->parent = y;
		}
		transplant(z, y);
		y->left = z->left;
		y->left->parent = y;
		y->color = z->color;
	}
	if (yOriginalColor == Black) {
		deleteFixUp(x);
	}
	size--;
}

TreeNode *Tree::findNode(int value) {
	TreeNode *node = root;
	while (node != TNIL) {
		if (node->key > value) {
			node = node->left;
		} else if (node->key < value) {
			node = node->right;
		} else {
			return node;
		}
	}
	return nullptr;
}

void Tree::deleteFixUp(TreeNode *x) {
	while (x != root && x->color == Black) {
		if (x == x->parent->left) {
			TreeNode *w;
			w = x->parent->right;
			if (w->color == Red) {
				w->color = Black;
				x->parent->color = Red;
				left_rotate(x->parent);
				w = x->parent->right;
			}
			if (w->left->color == Black && w->right->color == Black) {
				w->color = Red;
				x = x->parent;
			} else {
				if (w->right->color == Black) {
					w->left->color = Black;
					w->color = Red;
					right_rotate(w);
					w = x->parent->right;
				}
				w->color = x->parent->color;
				x->parent->color = Black;
				w->right->color = Black;
				left_rotate(x->parent);
				x = root;
			}
		} else {
			TreeNode *w;
			w = x->parent->left;
			if (w->color == Red) {
				w->color = Black;
				x->parent->color = Red;
				right_rotate(x->parent);
				w = x->parent->left;
			}
			if (w->right->color == Black && w->left->color == Black) {
				w->color = Red;
				x = x->parent;
			} else {
				if (w->left->color == Black) {
					w->right->color = Black;
					w->color = Red;
					left_rotate(w);
					w = x->parent->left;
				}
				w->color = x->parent->color;
				x->parent->color = Black;
				w->left->color = Black;
				right_rotate(x->parent);
				x = root;
			}
		}
	}
	x->color = Black;
}

void Tree::loadFromFile(std::string FileName) {
	std::ifstream file(FileName);
	if (!file.is_open()) {
		std::cout << "Nie mozna otworzyc pliku" << std::endl;
		return;
	}
	int tmp_size;
	file >> tmp_size;
	int data;
	for (int i = 0; i < tmp_size; i++) {
		file >> data;
		TreeNode *node = new TreeNode();
		node->key = data;
		insert(node);
	}
	file.close();
}

void Tree::loadFromFile(std::string fileName,int cnt) {
	std::ifstream file(fileName);
	if (!file.is_open()) {
		std::cout << "Nie mozna otworzyc pliku" << std::endl;
		return;
	}
	int data;
	for (int i = 0; i < cnt; i++) {
		file >> data;
		TreeNode *node = new TreeNode();
		node->key = data;
		insert(node);
	}
	file.close();
}

Tree::Tree() {
	TNIL = new TreeNode;
	TNIL->color = Black;
	TNIL->left = nullptr;
	TNIL->right = nullptr;
	root = TNIL;
}

Tree::~Tree() {}

void Tree::display() {
	printBT("", root, false);
}

void Tree::printBT(const std::string &prefix, const TreeNode *node, bool isLeft) {
	if (node != nullptr) {

		std::cout << prefix;

		std::cout << (isLeft ? "|--" : "/--");

		// print the value of the node
		if (node == TNIL)
			std::cout << "N" << std::endl;
		else
			std::cout << node->key << (node->color ? "B" : "R") << std::endl;

		// enter the next tree level - left and right branch
		printBT(prefix + (isLeft ? "|   " : "    "), node->left, true);
		printBT(prefix + (isLeft ? "|   " : "    "), node->right, false);
	}
}

void Tree::generateTree(int cnt) {
	TreeNode *newNode;
	for (int i = 0; i < cnt; ++i) {
		int value = rand();
		newNode = new TreeNode();
		newNode->key = value;
		insert(newNode);
	}
}

void Tree::removeAll() {
	while (root != TNIL) {
		deleteNode(root);
	}
}


