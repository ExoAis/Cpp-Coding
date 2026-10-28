#include "LLBS.h"
#include <string>
#include <vector>

double evaluatePostfix(vector <string> s, int length);
double evaluatePrefix(vector <string> s, int length);
double operation(int n1, int n2, string c);

int main() {
	vector <string> vec; int size; string s; int choice;
	cout << "Postfix or Prefix Expression?" << endl;
	cin >> choice;
	cout << "Enter the number of operators and operands" << endl;
	cin >> size;
	for (int i = 0; i < size; i++) {
		cout << "Enter the operator/operand" << endl;
		cin >> s;
		vec.push_back(s);
	}
	if (choice == 0) {
		cout << "Evaluated expression is " << evaluatePostfix(vec, vec.size()) << endl;
	}
	else {
		cout << "Evaluated expression is " << evaluatePrefix(vec, vec.size()) << endl;
	}

	return 0;
}

double operation(int n1, int n2, string c) {
	if (c == "+") {
		return n1 + n2;
	}
	else if (c == "-") {
		return n1 - n2;
	}
	else if (c == "*") {
		return n1 * n2;
	}
	else {
		return n1 / n2;
	}
}
double evaluatePostfix(vector <string> s, int length) {
	LLBS stack; double op1, op2;
	for (int i = 0; i < length; i++) {
		if (s[i] != "+" && s[i] != "-" && s[i] != "*" && s[i] != "/") {
			stack.push(stoi(s[i]));
		}
		else {
			op2 = stack.top();
			stack.pop();
			op1 = stack.top();
			stack.pop();
			stack.push(operation(op1, op2, s[i]));
		}
	}
	return stack.top();
}
double evaluatePrefix(vector <string> s, int length) {
	LLBS stack; double op1, op2;
	for (int i = length - 1; i > -1; i--) {
		if (s[i] != "+" && s[i] != "-" && s[i] != "*" && s[i] != "/") {
			stack.push(stoi(s[i]));
		}
		else {
			op1 = stack.top();
			stack.pop();
			op2 = stack.top();
			stack.pop();
			stack.push(operation(op1, op2, s[i]));
		}
	}
	return stack.top();
}