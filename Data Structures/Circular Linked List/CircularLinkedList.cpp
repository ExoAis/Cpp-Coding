#include "CircularLinkedList.h"

CircularLinkedList::CircularLinkedList() {
	int num, k;
	cout << "Enter total number of integers for linked list" << endl;
	cin >> num;
	cout << "Do you want unsorted list (0) or sorted list (1)" << endl;
	cin >> k;
	if (k == 0) {
		for (int i = 0; i < num; i++) {
			cout << "Do you want to insert at head (0) or at tail (1)" << endl;
			cin >> k;
			if (k == 0) {
				cout << "Enter number" << endl;
				cin >> k;
				insertAtFront(k);
			}
			else if (k == 1) {
				cout << "Enter number" << endl;
				cin >> k;
				insertAtBack(k);
			}
			printList();
		}
	}
	else if (k == 1) {
		for (int i = 0; i < num; i++) {
			cout << "Enter a number" << endl;
			cin >> k;
			insertSorted(k);
			printList();
		}
	}
	cout << "Do you want to insert another node? (0)" << endl;
	cin >> num;
	if (num == 0) {
		cout << "Enter the number" << endl;
		cin >> k;
		insertSorted(k);
		printList();
	}
	cout << "Do you want to delete a node? (0)" << endl;
	cin >> num;
	if (num == 0) {
		cout << "Which value do you want to delete?" << endl;
		cin >> num;
		Delete(num);
		printList();
	}
	cout << "Do you want to destroy the list (0) or not (1)" << endl;
	cin >> k;
	if (k == 0) {
		Destroy();
	}
	cout << "Circular Linked List is" << endl;
	printList();
}
bool CircularLinkedList::isEmpty() {
	if (last == nullptr) {
		return true;
	}
	return false;
}
void CircularLinkedList::insertAtFront(int k) {
	Node* nn = new Node;
	if (isEmpty()) {
		nn->data = k;
		last = nn;
		last->next = nn;
		return;
	}
	nn->data = k;
	nn->next = last->next;
	last->next = nn;
}
void CircularLinkedList::insertAtBack(int k) {
	if (isEmpty()) {
		insertAtFront(k);
		return;
	}
	Node* nn = new Node;
	nn->data = k;
	nn->next = last->next;
	last->next = nn;
	last = nn;
}
void CircularLinkedList::insertSorted(int k) {
	if (isEmpty() || (last->next == last && k < last->data)) {
		insertAtFront(k);
		return;
	}
	else if (last->next == last || k > last->data) {
		insertAtBack(k);
		return;
	}
	else if (last->next == last && k != last->data) {
		return;
	}
	Node* nn = new Node;
	nn->data = k;
	Node* temp = last->next;
	Node* temp1 = last;
	while (temp != last && temp->data < k) {
		temp = temp->next;
		temp1 = temp1->next;
	}
	nn->next = temp1->next;
	temp1->next = nn;
}
void CircularLinkedList::Delete(int k) {
	Node* temp = last->next;
	if (isEmpty()) {
		return;
	}
	else if (last->next == last && last->data == k) {
		delete last;
		last = nullptr;
		return;
	}
	else if (last->data == k) {
		while (temp->next != last) {
			temp = temp->next;
		}
		temp->next = last->next;
		delete last;
		last = temp;
		return;
	}
	Node* temp1 = last;
	while (temp != last && temp->data != k) {
		temp = temp->next;
		temp1 = temp1->next;
	}
	if (temp == last) {
		return;
	}
	temp1->next = temp->next;
	delete temp;
}
void CircularLinkedList::Destroy() {
	Node* temp = last->next;
	Node* temp1 = last;
	last = temp;
	while (temp != temp1) {
		last = last->next;
		delete temp;
		temp = last;
	}
	delete temp1;
	last = nullptr;
}
void CircularLinkedList::printList() {
	if (isEmpty()) {
		return;
	}
	cout << "Circular Linked List is" << endl;
	if (last->next == last) {
		cout << last->data << endl;
		return;
	}
	Node* temp = last->next;
	while (temp != last) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << temp->data;
	cout << endl;
}