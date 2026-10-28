#include "ABL.h"

bool ABL::isEmpty() {
	if (length == -1) {
		return true;
	}
	return false;
}
bool ABL::isFull() {
	if (length == 9) {
		return true;
	}
	return false;
}
int ABL::returnValue(int position) {
	int* pos = &a[0];
	pos = pos + position - 1;
	return *pos;
}
void ABL::insertAtposition(int value, int position) {
	if (isFull()) {
		return;
	}
	for (int i = length + 1; i >= position; i--) {
		a[i] = a[i - 1];
	}
	a[position - 1] = value;
	length++;
}
void ABL::insertSorted(int value) {
	if (isEmpty()) {
		a[length + 1] = value;
		length++;
		return;
	}
	else if (isFull()) {
		return;
	}
	else if (length == 0) {
		if (value > a[length]) {
			length++;
			a[length] = value;
		}
		else {
			length++;
			a[length] = a[length - 1];
			a[length - 1] = value;
		}
		return;
	}
	int index = 0;
	for (int i = 0; i <= length; i++) {
		if (value > a[i] && value < a[i + 1]) {
			index = i + 1;
		}
		else if (value > a[i]) {
			index++;
		}
	}
	for (int i = length + 1; i > index; i--) {
		a[i] = a[i - 1];
	}
	a[index] = value;
	length++;
}
void ABL::sort() {
	if (isEmpty()) {
		return;
	}
	for (int i = 0; i < length; i++) {
		for (int j = i; j < length; j++) {
			if (a[i] > a[j]) {
				swap(a[i], a[j]);
			}
		}
	}
}
void ABL::printList() {
	for (int i = 0; i <= length; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
void ABL::DeleteValue(int value) {
	if (isEmpty()) {
		return;
	}
	int index;
	for (int i = 0; i <= length; i++) {
		if (a[i] == value) {
			index = i;
		}
	}
	DeleteValueAtPosition(index + 1);
}
void ABL::DeleteValueAtPosition(int pos) {
	if (isEmpty()) {
		return;
	}
	for (int i = pos - 1; i <= length; i++) {
		a[i] = a[i + 1];
	}
	length--;
}