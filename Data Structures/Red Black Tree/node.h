#ifndef NODE_H
#define NODE_H

class BLNode {
	public:
		int value;
		char color;
		BLNode* left, * right;
		BLNode* parent;
		BLNode(int value) {
			this->left = nullptr;
			this->right = nullptr;
			this->value = value;
			this->parent = nullptr;
		}
};

#endif
