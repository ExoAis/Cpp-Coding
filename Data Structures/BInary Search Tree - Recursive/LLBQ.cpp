#include "LLBQ.h"

void LLBQ::Enqueue(bstNode* k) {
	Node* temp = new Node;
	temp->data = k;
	temp->next = nullptr;
	if (isEmpty()) {
		head = rear = temp;
	}
	else {
		rear->next = temp;
		rear = temp;
	}
}
void LLBQ::Dequeue() {
	Node* temp = head;
	if (isEmpty()) {
		return;
	}
	else if (head == rear) {
		head = rear = nullptr;
	}
	else {
		head = head->next;
	}
	delete temp;
	temp = nullptr;
}
bool LLBQ::isEmpty() {
	if (head == nullptr && rear == nullptr) {
		return true;
	}
	return false;
}
bstNode* LLBQ::frontElem() {
	if (isEmpty()) {
		return NULL;
	}
	return head->data;
}
void LLBQ::print() {
	if (isEmpty()) {
		return;
	}
	Node* temp = head;
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}