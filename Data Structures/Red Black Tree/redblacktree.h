#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H
#include "node.h"

class RedBlackTree {
	private:
		BLNode* root = nullptr;
		BLNode* nNode = nullptr;
		BLNode* temp = nullptr;
	public:
		RedBlackTree();
		BLNode* checkParentSiblingColor(BLNode* node, BLNode* cNode);
		BLNode* leftRotation(BLNode* node);
		BLNode* rightRotation(BLNode* node);
		void insert(int key);
		void insertNormal(BLNode* node, int key);
		BLNode* colorAndBalance(BLNode* node);
		void postOrderTraversal(BLNode* node);
};

#endif
