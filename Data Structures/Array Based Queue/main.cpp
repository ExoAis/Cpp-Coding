#include "ABQ.h"

int main() {
	ABQ queue;
	cout << boolalpha;
	cout << queue.isEmpty() << endl;
	cout << queue.isFull() << endl;
	queue.Enqueue(1);
	queue.Enqueue(2);
	queue.Enqueue(3);
	queue.Enqueue(4);
	queue.Enqueue(5);
	queue.print();
	cout << boolalpha;
	cout << queue.isEmpty() << endl;
	cout << queue.isFull() << endl;
	cout << queue.Dequeue() << endl;
	cout << queue.Dequeue() << endl;
	cout << queue.Dequeue() << endl;
	queue.print();
	cout << queue.frontElem() << endl;
	cout << queue.Dequeue() << endl;
	cout << queue.Dequeue() << endl;
	cout << boolalpha;
	cout << queue.isEmpty() << endl;
	queue.Enqueue(6);
	queue.print();

	return 0;
}