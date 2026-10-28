#ifndef LINKED_LIST
#define LINKED_LIST
#include "Node.h"
#include "LLBS.h"
#include <iostream>
using namespace std;

class LinkedList {
	private:
		Node* head = nullptr;
	public:
		LinkedList();
		void insertEnd(int k);
		void insertBegin(int k);
		void reverseRecuList(Node* ll);
		void reverseIterList();
		void deleteNode(int position);
		void insertNode(int k, int position);
		void printRecuList(Node* ll);
		void printRecuRevList(Node* ll);
		void printIterList();
		void reversalStack();
		Node* returnHead();
};

#endif

