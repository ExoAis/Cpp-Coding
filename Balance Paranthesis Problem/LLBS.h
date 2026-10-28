#ifndef LLBS_H
#define LLBS_H
#include <iostream>
#include "Node.h"
using namespace std;

class LLBS {
	private:
		Node* head = nullptr;
	public:
		void push(char k);
		void pop();
		bool isEmpty();
		char top();
		void print();
};

#endif
