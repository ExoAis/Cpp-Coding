#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H
#include <iostream>
#include "Node.h"
using namespace std;

class DoublyLinkedList {
	private:
		Node* head = nullptr;
	public:
		DoublyLinkedList();
		Node* getNewNode(int k);
		void insertHead(int k);
		void insertTail(int k);
		void insertNth(int pos, int k);
		void printForward();
		void printBackward();
		void oddEven();
		void search2Vals(int k, int n);
		void insertSorted(int k);
		void deleteNode(int pos);
		void destroyList();
		int deleteFront();
		int deleteBack();
};

#endif
