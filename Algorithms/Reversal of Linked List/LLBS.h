#ifndef LLBS_H
#define LLBS_H
#include <iostream>
#include "Node.h"
using namespace std;

class LLBS {
	private:
		Node* head = nullptr;
	public:
		void push(Node* newNode);
		void pop();
		bool isEmpty();
		Node* top();
		void print();
};

#endif

