#include "AdjacentNodes.h"

void AdjacentNodes::insert(GraphNodeL* data, int val) {
	GraphNodeL* nn = new GraphNodeL;
	nn->color = "white";
	nn->predecessor = nullptr;
	nn->data = data;
	nn->val = val;
	if (head == nullptr && end == nullptr) {
		head = nn;
		end = head;
		return;
	}
	end->next = nn;
	end = nn;
}
void AdjacentNodes::deleteNode(GraphNodeL* data) {
	GraphNodeL* t = head;
	while (t != nullptr && t->next != data) {
		t = t->next;
	}
	if (t == nullptr) {
		return;
	}
	t->next = t->next->next;
	t->next->next = nullptr;
	t->next->data = nullptr;
	delete t->next;
}
void AdjacentNodes::destroy() {
	GraphNodeL* t = head;
	while (t != nullptr) {
		t->data = nullptr;
		head = t->next;
		t->next = nullptr;
		delete t;
	}
	head = end = nullptr;
}
void AdjacentNodes::printList() {
	GraphNodeL* t = head;
	while (t != nullptr) {
		cout << t->val << " ";
		t = t->next;
	}
}