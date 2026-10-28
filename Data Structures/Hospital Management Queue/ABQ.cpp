#include "ABQ.h"
#include <vector>

ABQ::ABQ()
	:front{ -1 }, rear{ -1 } {}
bool ABQ::isEmpty() {
	if (front == -1 && rear == -1) {
		return true;
	}
	return false;
}
bool ABQ::isFull() {
	if ((rear + 1) % 10 == front) {
		return true;
	}
	return false;
}
Node ABQ::frontElem() {
	return arr[front];
}
void ABQ::Enqueue(Node k) {
	if (isFull()) {
		return;
	}
	else if (isEmpty()) {
		front = 0;
		rear = 0;
	}
	else {
		rear = (rear + 1) % 10;
	}
	arr[rear] = k;
}
Node ABQ::Dequeue() {
	Node k;
	if (isEmpty()) {
		return k;
	}
	else if (front == rear) {
		k = arr[front];
		front = -1;
		rear = -1;
		return k;
	}
	else {
		k = arr[front];
		front = (front + 1) % 10;
		return k;
	}
}
void ABQ::print() {
	if (isEmpty()) {
		return;
	}
	else {
		cout << "The waiting list is" << endl;
		Node p;
		vector<Node> v;
		for (int i = front; i <= rear; i++) {
			v.push_back(arr[i]);
		}
		for (int i = 0; i < v.size(); i++) {
			for (int j = i; j < v.size(); j++) {
				if (v[i].Name > v[j].Name) {
					swap(v[i], v[j]);
				}
			}
		}
		for (int i = 0; i < v.size(); i++) {
			cout << v[i].Name << " " << v[i].ID << endl;
		}
		cout << endl;
	}
}
void ABQ::emptyQueue() {
	if (isEmpty()) {
		return;
	}
	else {
		Node elem;
		for (int i = front; i <= rear; i++) {
			elem = Dequeue();
		}
	}
}
int ABQ::returnFront() {
	return front;
}
int ABQ::returnRear() {
	return rear;
}