#include "ABS.h"

ABS::ABS(int size)
	: maxSize{ size * 2 }, top{ -1 } { }
void ABS::push(int k) {
	arr[++top] = k;
}
void ABS::pop() {
	top--;
}
void ABS::print() {
	cout << "The array based stack is " << endl;
	for (int i = 0; i <= top; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
bool ABS::isEmpty() {
	if (top == -1) {
		return true;
	}
	return false;
}
int ABS::topElem() {
	return arr[top];
}