#ifndef LLBQ_H
#define LLBQ_H
#include "Node.h"

class LLBQ {
	private:
		Node* head = nullptr;
		Node* rear = nullptr;
	public:
		void Enqueue(bstNode* k);
		void Dequeue();
		bool isEmpty();
		bstNode* frontElem();
		void print();
};

#endif
