#include "DABL.h"

bool DABL::isEmpty() {
	if (length == -1) {
		return true;
	}
	return false;
}
bool DABL::isFull() {
	if (length == size - 1) {
		return true;
	}
	return false;
}
void DABL::insertAtposition(int value, int position) {
	if (isFull()) {
		DynamicExpansion();
	}
	for (int i = length + 1; i >= position; i--) {
		a[i] = a[i - 1];
	}
	a[position - 1] = value;
	length++;
}
void DABL::insertSorted(int value) {
	if (isEmpty()) {
		a[length + 1] = value;
		length++;
		return;
	}
	if (isFull()) {
		DynamicExpansion();
	}
	if (length == 0) {
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
void DABL::sort() {
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
void DABL::printList() {
	cout << "The Dynamic List is" << endl;
	for (int i = 0; i <= length; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
void DABL::DeleteValue(int value) {
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
void DABL::DeleteValueAtPosition(int pos) {
	if (isEmpty()) {
		return;
	}
	for (int i = pos - 1; i <= length; i++) {
		a[i] = a[i + 1];
	}
	length--;
	if (length + 1 <= (size / 2)) {
		DynamicReduction();
	}
}
void DABL::DynamicExpansion() {
	if (isFull()) {
		size = size * 2;
		int* pa = new int[size];
		for (int i = 0; i <= length; i++) {
			pa[i] = a[i];
		}
		a = pa;
	}
}
void DABL::DynamicReduction() {
	int temp = length + 1;
	if (temp < (size / 2)) {
		size = size / 2;
		int* pa = new int[size];
		for (int i = 0; i <= length; i++) {
			pa[i] = a[i];
		}
		a = pa;
	}
}
