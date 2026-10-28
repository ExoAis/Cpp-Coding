#ifndef ABS_H
#define ABS_H
#include <iostream>
using namespace std;

class ABS {
	public:
		ABS(int size);
		void push(int k);
		void pop();
		void print();
		bool isEmpty();
		int topElem();
	private:
		const int maxSize;
		int* arr = new int[maxSize];
		int top;
};

#endif
