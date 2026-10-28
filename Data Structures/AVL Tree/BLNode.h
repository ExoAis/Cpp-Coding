#ifndef BLNODE_H
#define BLNODE_H

class BLNode {
	public:
		int value, height;
		BLNode* left, * right;
		BLNode(int value) {
			this->left = nullptr;
			this->right = nullptr;
			this->value = value;
			this->height = 0;
		}
};

#endif
