#include "LLBS.h"

void LLBS::push(double k) {
	Node* node = new Node;
	node->data = k;
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
double LLBS::top() {
	return head->data;
}
void LLBS::print() {
	Node* temp = head;
	cout << "Linked List Based Stack is " << endl;
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}