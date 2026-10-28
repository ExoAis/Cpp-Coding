#include "LLBS.h"

int main() {
	int num, k;
	LLBS stack;
	cout << "For how many integers do you want to make a stack?" << endl;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cout << "Enter an integer" << endl;
		cin >> k;
		stack.push(k);
	}
	stack.print();
	cout << "Element at the top of stack is " << stack.top() << endl;
	cout << "Press 0 if you want to pop and 1 if not" << endl;
	cin >> num;
	if (num == 0) {
		cout << "How many times do you want to pop?" << endl;
		cin >> num;
		for (int i = 0; i < num; i++) {
			stack.pop();
		}
	}
	if (stack.isEmpty() == true) {
		cout << "The stack is currently empty" << endl;
	}
	else {
		cout << "Element at the top of stack is " << stack.top() << endl;
		stack.print();
	}

	return 0;
}