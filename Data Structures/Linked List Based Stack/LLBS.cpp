#include "LLBS.h"

void LLBS::push(int k) {
	Node* node = new Node;
	node->num = k;
	node->next = head;
	head = node;
}
void LLBS::pop() {
	if (head == nullptr) {
		return;
	}
	Node* temp = head;
	head = head->next;
	delete temp;
	temp = nullptr;
}
bool LLBS::isEmpty() {
	if (head == nullptr) {
		return true;
	}
	return false;
}
int LLBS::top() {
	return head->num;
}
void LLBS::print() {
	Node* temp = head;
	cout << "Linked List Based Stack is " << endl;
	while (temp != nullptr) {
		cout << temp->num << " ";
		temp = temp->next;
	}
	cout << endl;
}