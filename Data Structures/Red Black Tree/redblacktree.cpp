#include "redblacktree.h"
#include <iostream>
using namespace std;

RedBlackTree::RedBlackTree() {
	int n;
	while (true) {
		cout << "Enter number to insert in Red Black Tree. Press -1 to exit" << endl;
		cin >> n;
		if (n == -1) {
			break;
		}
		insert(n);
		cout << endl << "The Post Order Traversal Is" << endl;
		postOrderTraversal(root);
		cout << endl << endl;
	}
}
BLNode* RedBlackTree::checkParentSiblingColor(BLNode* node, BLNode* cNode) {
	if (node == nullptr) {
		return node;
	}
	if (node->right == cNode) {
		return node->left;
	}
	if (node->left == cNode) {
		return node->right;
	}
	if (cNode->value > node->value) {
		return checkParentSiblingColor(node->right, cNode);
	}
	if (cNode->value < node->value) {
		return checkParentSiblingColor(node->left, cNode);
	}
}
void RedBlackTree::insert(int key) {
	if (root == nullptr) {
		insertNormal(root, key);
		return;
	}
	insertNormal(root, key);
	colorAndBalance(root);
	if (root->color == 'R') {
		root->color = 'B';
	}
}
BLNode* RedBlackTree::colorAndBalance(BLNode* node) {
	if (node == nNode || node == nullptr) {
		return node;
	}
	if (node->value < nNode->value) {
		node = colorAndBalance(node->right);
	}
	if (node->value > nNode->value) {
		node = colorAndBalance(node->left);
	}
	if (node != root) {
		if (node->color == 'R' && node->parent->color == 'R') {
			BLNode* Parent = node->parent;
			BLNode* gParent = Parent->parent;
			BLNode* sParent = checkParentSiblingColor(root, Parent);
			if (sParent == nullptr || sParent->color == 'B') {
				BLNode* rotatedNode = nullptr;
				BLNode* pParent = gParent->parent;
				if (Parent->left == node && gParent->left == Parent) {
					rotatedNode = rightRotation(gParent);
					Parent->parent = pParent;
					gParent->parent = Parent;
					if (gParent == root) {
						root = Parent;
					}
					if (Parent->color == 'R') {
						Parent->color = 'B';
					}
					else if (Parent->color == 'B') {
						Parent->color = 'R';
					}
					if (gParent->color == 'R') {
						gParent->color = 'B';
					}
					else if (gParent->color == 'B') {
						gParent->color = 'R';
					}
				}
				else if (Parent->right == node && gParent->right == Parent) {
					rotatedNode = leftRotation(gParent);
					Parent->parent = pParent;
					gParent->parent = Parent;
					if (gParent == root) {
						root = Parent;
					}
					if (Parent->color == 'R') {
						Parent->color = 'B';
					}
					else if (Parent->color == 'B') {
						Parent->color = 'R';
					}
					if (gParent->color == 'R') {
						gParent->color = 'B';
					}
					else if (gParent->color == 'B') {
						gParent->color = 'R';
					}
				}
				else if (Parent->right == node && gParent->left == Parent) {
					gParent->left = leftRotation(Parent);
					rotatedNode = rightRotation(gParent);
					node->parent = pParent;
					Parent->parent = node;
					gParent->parent = node;
					if (gParent == root) {
						root = rotatedNode;
					}
					if (node->color == 'R') {
						node->color = 'B';
					}
					else if (node->color == 'B') {
						node->color = 'R';
					}
					if (gParent->color == 'R') {
						gParent->color = 'B';
					}
					else if (gParent->color == 'B') {
						gParent->color = 'R';
					}
				}
				else if (Parent->left == node && gParent->right == Parent) {
					gParent->right = rightRotation(Parent);
					rotatedNode = leftRotation(gParent);
					node->parent = pParent;
					Parent->parent = node;
					gParent->parent = node;
					if (gParent == root) {
						root = rotatedNode;
					}
					if (node->color == 'R') {
						node->color = 'B';
					}
					else if (node->color == 'B') {
						node->color = 'R';
					}
					if (gParent->color == 'R') {
						gParent->color = 'B';
					}
					else if (gParent->color == 'B') {
						gParent->color = 'R';
					}
				}
				if (pParent != nullptr) {
					if (pParent->left == gParent) {
						pParent->left = rotatedNode;
					}
					else if (pParent->right == gParent) {
						pParent->right = rotatedNode;
					}
				}
				return rotatedNode;
			}
			else if (sParent->color == 'R') {
				Parent->color = sParent->color = 'B';
				Parent->parent->color = 'R';
			}
		}
	}
	return node->parent;
}
void RedBlackTree::insertNormal(BLNode* node, int key){
	if (root == nullptr) {
		root = new BLNode(key);
		root->color = 'B';
	}
	else if (node != nullptr) {
		if (key < node->value) {
			temp = node;
			insertNormal(node->left, key);
		}
		else if (key > node->value) {
			temp = node;
			insertNormal(node->right, key);
		}
	}
	else {
		BLNode* newNode = new BLNode(key);
		newNode->color = 'R';
		nNode = newNode;
		newNode->parent = temp;
		if (key < temp->value) {
			temp->left = newNode;
		}
		else if (key > temp->value) {
			temp->right = newNode;
		}
	}
	return;
}
BLNode* RedBlackTree::leftRotation(BLNode* node) {
	BLNode* x, * y, * z;
	x = node;
	y = x->right;
	z = y->left;
	y->left = x;
	x->right = z;
	return y;
}
BLNode* RedBlackTree::rightRotation(BLNode* node) {
	BLNode* x, * y, * z;
	x = node;
	y = x->left;
	z = y->right;
	y->right = x;
	x->left = z;;
	return y;
}
void RedBlackTree::postOrderTraversal(BLNode* node) {
	if (node == nullptr) {
		return;
	}
	postOrderTraversal(node->left);
	postOrderTraversal(node->right);
	cout << node->value << node->color << " ";
}