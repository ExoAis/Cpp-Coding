#ifndef LINKED_LIST
#define LINKED_LIST
#include "Node.h"

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
		void deleteValue(int k);
		void deleteOddPos();
		void destroyList();
		void insertNode(int k, int position);
		void printRecuList(Node* ll);
		void printRecuRevList(Node* ll);
		void printIterList();
		Node* returnHead();
};

#endif
