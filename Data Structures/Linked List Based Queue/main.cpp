#include "LLBQ.h"

int main() {
	LLBQ* queue = new LLBQ;
	int num, k;
	cout << "How many numbers do you want to insert?" << endl;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cout << "Enter an integer" << endl;
		cin >> k;
		queue->Enqueue(k);
	}
	queue->print();
	queue->frontElem();
	cout << "How many numbers do you want to delete?" << endl;
	cin >> num;
	for (int i = 0; i < num; i++) {
		queue->Dequeue();
	}
	queue->print();
	cout << queue->frontElem() << endl;
	delete queue;
	queue = nullptr;

	return 0;
}