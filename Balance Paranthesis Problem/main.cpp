#include "LLBS.h"

bool paranthesisBalanced(char a[], int size);

int main() {
	//char arr[]{ '[', '{', '[', '(', '(', ')', ']', '[', ']', '}', ']' };
	char arr[]{ '[', '[', '(', ')', '}'};
	int size = sizeof(arr) / sizeof(arr[0]);
	if (paranthesisBalanced(arr, size)) {
		cout << "In the given array, the paranthesis are balanced" << endl;
	}
	else {
		cout << "In the given array, the paranthesis are not balanced" << endl;
	}

	return 0;
}

bool paranthesisBalanced(char a[], int size) {
	LLBS stack; int index = -1;
	for (int i = 0; i < size; i++) {
		if (a[i] == '(' || a[i] == '[' || a[i] == '{') {
			index = i;
			stack.push(a[i]);
		}
		else if (a[i] == ')' || a[i] == ']' || a[i] == '}') {
			if (stack.isEmpty()) {
				return false;
			}
			else if (stack.top() == '(' && a[i] == ')') {
				stack.pop();
			}
			else if (stack.top() == '[' && a[i] == ']') {
				stack.pop();
			}
			else if (stack.top() == '{' && a[i] == '}') {
				stack.pop();
			}
			else {
				index = i;
				cout << "Error occurs at index " << index << " closing bracket not found" << endl;
				return false;
			}
		}
	}
	if (stack.isEmpty()) {
		return true;
	}
	cout << "Error occurs at index " << index << " closing bracket not found" << endl;
	return false;
}