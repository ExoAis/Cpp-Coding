#include "BinarySearchTree.h"

int nodes = 0;
BST::BST() {
	int num, k;
	cout << "How many nodes do you want to insert?" << endl;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cout << "Enter an integer" << endl;
		cin >> k;
		insertNode(root, k);
	}
	cout << "The Pre-Order Traversal of Binary Search Tree is " << endl;
	preOrderTraversal(root);
	cout << endl;
	cout << "The In-Order Traversal of Binary Search Tree is " << endl;
	inOrderTraversal(root);
	cout << endl;
	cout << "The Post-Order Traversal of Binary Search Tree is " << endl;
	postOrderTraversal(root);
	cout << endl;
	cout << "The Level Order Traversal of Binary Search Tree is " << endl;
	levelOrderTraversal(root);
	cout << endl;
	cout << "Do you want to seach for an integer? Press 0 for Yes and 1 for No" << endl;
	cin >> num;
	if (num == 0) {
		cout << "How many integers do you want to search for?" << endl;
		cin >> num;
		for (int i = 0; i < num; i++) {
			cout << "Enter integer to search for" << endl;
			cin >> k;
			if (searchTree(root, k)) {
				cout << "Integer is found" << endl;
			}
			else {
				cout << "Integer not found" << endl;
			}
		}
	}
	cout << "The maximum and minimum elements in the Binary Search Tree are respectively " << maxElement(root) << " and " << minElement(root) << endl;
	cout << "The height of the Binary Search Tree is " << height(root) << endl;
	cout << "The depth of the Binary Search Tree is " << depth(root) << endl;
	cout << "Leaf Nodes are" << endl;
	printLeafNodes(root);
	totalLeafNodes(root);
	cout << endl;
	cout << "Total Leaf Nodes are " << nodes << endl;
	nodes = 0;
	totalInternalNodes(root);
	cout << "Total Internal Nodes are " << nodes << endl;
}
bstNode* BST::getNode(int k) {
	bstNode* node = new bstNode;
	node->data = k;
	node->left = node->right = nullptr;
	return node;
}
int BST::minElement(bstNode* node) {
	if (node->left == nullptr) {
		return node->data;
	}
	minElement(node->left);
}
int BST::maxElement(bstNode* node) {
	if (node->right == nullptr) {
		return node->data;
	}
	maxElement(node->right);
}
int BST::height(bstNode* node) {
	if (node == nullptr) {
		return -1;
	}
	return max(height(node->left), height(node->right)) + 1;
}
int BST::depth(bstNode* node) {
	if (node == nullptr) {
		return -1;
	}
	return max(depth(node->left), depth(node->right)) + 1;
}
void BST::insertNode(bstNode* node, int k) {
	if (root == nullptr) {
		bstNode* n = getNode(k);
		root = n;
	}
	else if (node != nullptr) {
		if (k <= node->data) {
			temp = node;
			insertNode(node->left, k);
		}
		else if (k > node->data) {
			temp = node;
			insertNode(node->right, k);
		}
	}
	else {
		bstNode* n = getNode(k);
		if (k <= temp->data) {
			temp->left = n;
		}
		else {
			temp->right = n;
		}
	}
	return;
}
void BST::preOrderTraversal(bstNode* node) {
	if (root == nullptr) {
		return;
	}
	else {
		cout << node->data << " ";
		if (node->left != nullptr) {
			preOrderTraversal(node->left);
		}
		if (node->right != nullptr) {
			preOrderTraversal(node->right);
		}
	}
}
void BST::inOrderTraversal(bstNode* node) {
	if (root == nullptr) {
		return;
	}
	else {
		if (node->left != nullptr) {
			inOrderTraversal(node->left);
		}
		cout << node->data << " ";
		if (node->right != nullptr) {
			inOrderTraversal(node->right);
		}
	}
}
void BST::postOrderTraversal(bstNode* node) {
	if (root == nullptr) {
		return;
	}
	else {
		if (node->left != nullptr) {
			inOrderTraversal(node->left);
		}
		if (node->right != nullptr) {
			inOrderTraversal(node->right);
		}
		cout << node->data << " ";
	}
}
void BST::levelOrderTraversal(bstNode* node) {
	LLBQ queue;
	queue.Enqueue(root);
	bstNode* temp;
	while (!queue.isEmpty()) {
		temp = queue.frontElem();
		cout << temp->data << " ";
		if (temp->left != nullptr) {
			queue.Enqueue(temp->left);
		}
		if (temp->right != nullptr) {
			queue.Enqueue(temp->right);
		}
		queue.Dequeue();
	}
}
bool BST::searchTree(bstNode* node, int k) {
	if (node == nullptr) {
		return false;
	}
	if (k == node->data) {
		return true;
	}
	else if (k <= node->data) {
		searchTree(node->left, k);
	}
	else {
		searchTree(node->right, k);
	}
}
void BST::printLeafNodes(bstNode* node) {
	if (node->right == nullptr && node->left == nullptr) {
		cout << node->data << " ";
		return;
	}
	if (node->left != nullptr) {
		printLeafNodes(node->left);
	}
	if (node->right != nullptr) {
		printLeafNodes(node->right);
	}
}
void BST::totalLeafNodes(bstNode* node) {
	if (node->right == nullptr && node->left == nullptr) {
		nodes++;
		return;
	}
	if (node->left != nullptr) {
		totalLeafNodes(node->left);
	}
	if (node->right != nullptr) {
		totalLeafNodes(node->right);
	}
}
void BST::totalInternalNodes(bstNode* node) {
	if (node->left == nullptr && node->right == nullptr) {
		return;
	}
	if (node->left != nullptr) {
		totalInternalNodes(node->left);
	}
	nodes++;
	if (node->right != nullptr) {
		totalInternalNodes(node->right);
	}
}
