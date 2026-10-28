#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "BSTNode.h"
#include "LLBQ.h"

class BST {
	private:
		bstNode* root = nullptr;
		bstNode* temp = nullptr;
	public:
		BST();
		bstNode* getNode(int k);
		int minElement(bstNode* node);
		int maxElement(bstNode* node);
		int height(bstNode* node);
		int depth(bstNode* node);
		void insertNode(bstNode* node, int k);
		void preOrderTraversal(bstNode* node);
		void inOrderTraversal(bstNode* node);
		void postOrderTraversal(bstNode* node);
		void levelOrderTraversal(bstNode* node);
		void printLeafNodes(bstNode* node);
		void totalLeafNodes(bstNode* node);
		void totalInternalNodes(bstNode* node);
		bool searchTree(bstNode* node, int k);
};

#endif
