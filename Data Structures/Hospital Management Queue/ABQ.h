#ifndef ABQ_H
#define ABQ_H
#include "Node.h"

class ABQ {
	private:
		Node arr[10];
		int front, rear;
	public:
		ABQ();
		bool isEmpty();
		bool isFull();
		Node frontElem();
		void Enqueue(Node k);
		Node Dequeue();
		void print();
		void emptyQueue();
		int returnFront();
		int returnRear();
};

#endif
