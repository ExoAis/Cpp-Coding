#ifndef LLBQ_H
#define LLBQ_H
#include "Node.h"

class LLBQ {
	private:
		Node* head = nullptr;
		Node* rear = nullptr;
	public:
		void Enqueue(int k);
		void Dequeue();
		bool isEmpty();
		int frontElem();
		void print();
};

#endif
