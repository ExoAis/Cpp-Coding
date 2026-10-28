#include "ABQ.h"

ABQ::ABQ()
	:front{ -1 }, rear{ -1 } {}
bool ABQ::isEmpty() {
	if (front == -1 && rear == -1) {
		return true;
	}
	return false;
}
bool ABQ::isFull() {
	if ((rear + 1) % 5 == front) {
		return true;
	}
	return false;
}
int ABQ::frontElem() {
	return arr[front];
}
void ABQ::Enqueue(int k) {
	if (isFull()) {
		return;
	}
	else if (isEmpty()) {
		front = 0;
		rear = 0;
	}
	else {
		rear = (rear + 1) % 5;
	}
	arr[rear] = k;
}
int ABQ::Dequeue() {
	int k;
	if (isEmpty()) {
		return -1;
	}
	else if (front == rear) {
		k = arr[front];
		front = -1;
		rear = -1;
		return k;
	}
	else {
		k = arr[front];
		front = (front + 1) % 5;
		return k;
	}
}
void ABQ::print() {
	if (isEmpty()) {
		return;
	}
	else {
		for (int i = front; i <= rear; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
}