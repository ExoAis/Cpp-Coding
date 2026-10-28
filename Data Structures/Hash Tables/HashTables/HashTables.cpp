#include "HashTables.h"

int HashTable::hashFunction(int x) {
	return x % arraySize;
}
void HashTable::initializeTable() {
	cout << "Enter the Table Size" << endl;
	cin >> arraySize;
	arr = new Node[arraySize];
	Node node;
	for (int i = 0; i < arraySize; i++) {
		node.k = -1;
		node.collisions = 0;
		arr[i] = node;
	}
}
void HashTable::Insert(int k) {
	if (size == arraySize) {
		cout << "Table is Full" << endl;
		return;
	}
	int index = hashFunction(k);
	int idx = index;
	int i = 1;
	int counter = 0;
	while (arr[idx].k != -1) {
		idx = (hashFunction(k) + i * i) % arraySize;
		i++;
		arr[index].collisions++;
		for (int j = 0; j < arraySize; j++) {
			if (arr[j].k != -1) {
				counter++;
			}
		}
		if (counter == arraySize) {
			return;
		}
		counter = 0;
	}
	arr[idx].k = k;
	size++;
}
void HashTable::Delete(int k) {
	if (size == -1) {
		cout << "Table is Empty" << endl;
		return;
	}
	int index = hashFunction(k);
	int i = 1;
	int idx = index;
	int coll = 0;
	while (arr[idx].k != k && arr[index].collisions != coll) {
		idx = (hashFunction(k) + i * i) % arraySize;
		i++;
		coll++;
	}
	if (arr[index].collisions < coll) {
		cout << "Value not found" << endl;
		return;
	}
	arr[idx].k = -1;
	size--;
}
void HashTable::printTable() {
	for (int i = 0; i < arraySize; i++) {
		cout << arr[i].k << " ";
	}
	cout << endl;
}