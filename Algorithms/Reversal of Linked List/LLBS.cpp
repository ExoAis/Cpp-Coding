#include "LLBS.h"

void LLBS::push(Node* newNode) {
	Node* node = new Node;
	node->num = newNode->num;
	node->next = newNode->next;
	node->next = head;
	head = node;
}
void LLBS::pop() {
	if (head == nullptr) {
		return;
	}
	Node* temp = head;
	head = head->next;
	temp = nullptr;
}
bool LLBS::isEmpty() {
	if (head == nullptr) {
		return true;
	}
	return false;
}
Node* LLBS::top() {
	return head;
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