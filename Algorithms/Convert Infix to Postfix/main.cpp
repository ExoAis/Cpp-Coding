#include "LLBS.h"

string infixToPostfix(string arr[], int length);
bool isOperator(string c);
bool hasHigherPrecedence(string c, string s);
bool isOpenBracket(string c);
bool isClosedBracket(string c);

int main() {
	int size; string s;
	cout << "Enter the total number of operands and operators" << endl;
	cin >> size;
	string* arr = new string[size];
	for (int i = 0; i < size; i++) {
		cout << "Enter the operand/operator" << endl;
		cin >> s;
		arr[i] = s;
	}
	cout << "Postfix expression of the given infix expression is " << infixToPostfix(arr, size) << endl;

	return 0;
}

string infixToPostfix(string arr[], int length) {
	string str = "";
	LLBS stack;
	for (int i = 0; i < length; i++) {
		if (!isOperator(arr[i]) && !isOpenBracket(arr[i]) && !isClosedBracket(arr[i])) {
			str += arr[i];
		}
		else if (isOperator(arr[i])) {
			while (!stack.isEmpty() && !isOpenBracket(arr[i]) && !isClosedBracket(arr[i]) && hasHigherPrecedence(stack.top(), arr[i])) {
				str += stack.top();
				stack.pop();
			}
			stack.push(arr[i]);
		}
		else if (isOpenBracket(arr[i])) {
			stack.push(arr[i]);
		}
		else if (isClosedBracket(arr[i])) {
			while (!stack.isEmpty() && !isOpenBracket(stack.top())) {
				str += stack.top();
				stack.pop();
			}
			stack.pop();
		}
	}
	while (!stack.isEmpty()) {
		str += stack.top();
		stack.pop();
	}
	return str;
}
bool isOperator(string c) {
	if (c == "+" || c == "-" || c == "*" || c == "/" || c == "^") {
		return true;
	}
	return false;
}
bool hasHigherPrecedence(string c, string s) {
	if (c == s) {
		return true;
	}
	else {
		if (c == "^") {
			return true;
		}
		else if ((c == "/" && s == "^") || (c == "*" && s == "^")) {
			return false;
		}
		else if (c == "*" || c == "/") {
			return true;
		}
		else if ((c == "+" && s == "^") || (c == "-" && s == "^") || (c == "+" && s == "*") || (c == "-" && s == "*") || (c == "+" && s == "/") || (c == "-" && s == "/")) {
			return false;
		}
		else if (c == "+" || c == "-") {
			return true;
		}
		else {
			return false;
		}
	}
}
bool isOpenBracket(string c) {
	if (c == "(" || c == "[" || c == "{") {
		return true;
	}
	return false;
}
bool isClosedBracket(string c) {
	if (c == ")" || c == "]" || c == "}") {
		return true;
	}
	return false;
}