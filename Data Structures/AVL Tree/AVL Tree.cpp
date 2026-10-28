#include "AVL Tree.h"

AVLTree::AVLTree() {
	int count, key;
	cout << "How many values do you want to insert?" << endl;
	cin >> count;
	for (int i = 0; i < count; i++) {
		cout << "Enter the Value" << endl;
		cin >> key;
		root = insert(root, key);
		cout << "The Post Order Traversal is: " << endl;
		postOrderTraversal(root);
		cout << endl << endl;
	}
}
int AVLTree::height(BLNode* node) {
	if (node == nullptr) {
		return -1;
	}
	return node->height;
}
int AVLTree::max(int h1, int h2) {
	if (h1 > h2) {
		return h1;
	}
	return h2;
}
BLNode* AVLTree::insert(BLNode* node, int key) {
	if (node == nullptr) {
		return new BLNode(key);
	}
	if (key < node->value) {
		node->left = insert(node->left, key);
	}
	else if (key > node->value) {
		node->right = insert(node->right, key);
	}
	else {
		return node;
	}
	int lH = height(node->left);
	int rH = height(node->right);
	node->height = 1 + max(lH, rH);
	int balance = balanceFactor(node);
	if (balance > 1 && key < node->left->value) {
		return rightRotation(node);
	}
	else if (balance < -1 && key > node->right->value) {
		return leftRotation(node);
	}
	else if (balance > 1 && key > node->left->value) {
		node->left = leftRotation(node->left);
		return rightRotation(node);
	}
	else if (balance < -1 && key < node->right->value) {
		node->right = rightRotation(node->right);
		return leftRotation(node);
	}
	return node;
}
int AVLTree::balanceFactor(BLNode* node) {
	if (node == nullptr) {
		return 0;
	}
	return height(node->left) - height(node->right);
}
BLNode* AVLTree::leftRotation(BLNode* node) {
	BLNode* x, * y, * z;
	x = node;
	y = x->right;
	z = y->left;
	y->left = x;
	x->right = z;
	x->height = 1 + max(height(x->left), height(x->right));
	y->height = 1 + max(height(y->left), height(y->right));
	return y;
}
BLNode* AVLTree::rightRotation(BLNode* node) {
	BLNode* x, * y, * z;
	x = node;
	y = x->left;
	z = y->right;
	y->right = x;
	x->left = z;
	x->height = 1 + max(height(x->left), height(x->right));
	y->height = 1 + max(height(y->left), height(y->right));
	return y;
}
void AVLTree::postOrderTraversal(BLNode* node) {
	if (node == nullptr) {
		return;
	}
	postOrderTraversal(node->left);
	postOrderTraversal(node->right);
	cout << node->value << " ";
}