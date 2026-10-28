#ifndef AVLTREE_H
#define AVLTREE_H
#include "BLNode.h"
#include <iostream>
using namespace std;

class AVLTree {
	private:
		BLNode* root;
	public:
		AVLTree();
		int height(BLNode* node);
		int max(int h1, int h2);
		int balanceFactor(BLNode* node);
		BLNode* leftRotation(BLNode* node);
		BLNode* rightRotation(BLNode* node);
		BLNode* insert(BLNode* node, int key);
		void postOrderTraversal(BLNode* node);
};

#endif
