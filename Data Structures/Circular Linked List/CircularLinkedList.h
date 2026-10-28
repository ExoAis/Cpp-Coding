#ifndef CIRCULAR_LINKED_LIST
#define CIRCULAR_LINKED_LIST
#include "Node.h"

class CircularLinkedList {
	private:
		Node* last;
	public:
		CircularLinkedList();
		bool isEmpty();
		void insertAtFront(int k);
		void insertAtBack(int k);
		void insertSorted(int k);
		void Delete(int k);
		void Destroy();
		void printList();
};

#endif
