#ifndef LLBS_H
#define LLBS_H
#include <iostream>
#include "Node.h"
using namespace std;

class LLBS {
	private:
		Node* head = nullptr;
	public:
		void push(string k);
		void pop();
		bool isEmpty();
		string top();
		void print();
};

#endif
