#include "ABS.h"

int main() {
	int size, elem;
	cout << "What is the max size of the stack?" << endl;
	cin >> size;
	ABS stack(size);
	for (int i = 0; i < size; i++) {
		cout << "Enter an integer" << endl;
		cin >> elem;
		stack.push(elem);
	}
	stack.print();
	stack.pop();
	stack.print();
	cout << "The top element of stack is " << stack.topElem() << endl;
	stack.pop();
	stack.pop();
	if (stack.isEmpty() == 1) {
		cout << "The stack is empty" << endl;
	}
	else {
		cout << "The stack is not empty" << endl;
		stack.print();
	}

	return 0;
}