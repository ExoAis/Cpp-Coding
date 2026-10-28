#ifndef ABQ_H
#define ABQ_H
#include <iostream>
using namespace std;

class ABQ {
	private:
		int arr[5];
		int front, rear;
	public:
		ABQ();
		bool isEmpty();
		bool isFull();
		int frontElem();
		void Enqueue(int k);
		int Dequeue();
		void print();
};

#endif
