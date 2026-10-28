#include "MaxHeap.h"

MaxHeap::MaxHeap() {
	int elem, numElems;
	cout << "Enter the Size of Max Heap" << endl;
	cin >> arraySize;
	cout << "Enter the Number of Elements to insert in Max Heap" << endl;
	cin >> numElems;
	sortedEnd = numElems;
	for (int i = 0; i < numElems; i++) {
		cout << "Enter the Element" << endl;
		cin >> elem;
		insert(elem);
	}
	printHeap();
	for (int i = 0; i < numElems; i++) {
		deleteRoot();
	}
	printHeap();
	printSortedList();
	destroyHeap();
}
void MaxHeap::insert(int elem) {
	heapSize++;
	heap[heapSize] = elem;
	insertHeapify();
}
void MaxHeap::deleteRoot() {
	int temp = heap[1];
	heap[1] = heap[heapSize];
	heap[heapSize] = temp;
	sortedStart = heapSize;
	heapSize--;
	deleteHeapify();
}
void MaxHeap::insertHeapify() {
	int index = heapSize;
	int idx;
	while (index > 0 && floor(index / 2) > 0) {
		idx = floor(index / 2);
		if (heap[index] > heap[idx]) {
			swap(heap[index], heap[idx]);
			index = idx;
		}
		else {
			break;
		}
	}
}
void MaxHeap::deleteHeapify() {
	int index;
	int idx = 1;
	int maxElem;
	bool lR = false;
	while (((idx * 2) <= heapSize) || ((idx * 2) + 1 <= heapSize)) {
		if (((idx * 2) <= heapSize) && ((idx * 2) + 1 <= heapSize)) {
			if (heap[idx * 2] >= heap[(idx * 2) + 1]) {
				maxElem = heap[idx * 2];
				lR = true;
				index = idx * 2;
			}
			else {
				maxElem = heap[(idx * 2) + 1];
				lR = false;
				index = (idx * 2) + 1;
			}
			if (heap[idx] >= maxElem) {
				break;
			}
			if (lR) {
				swap(heap[idx], heap[idx * 2]);
			}
			else {
				swap(heap[idx], heap[(idx * 2) + 1]);
			}
			idx = index;
		}
		else if ((idx * 2) + 1 > heapSize && idx * 2 <= heapSize) {
			if (heap[idx] < heap[idx * 2]) {
				swap(heap[idx], heap[idx * 2]);
			}
			idx = idx * 2;
		}
	}
}
void MaxHeap::printHeap() {
	for (int i = 1; i < heapSize + 1; i++) {
		cout << heap[i] << " ";
	}
	cout << endl;
}
void MaxHeap::destroyHeap() {
	delete[] heap;
}
void MaxHeap::printSortedList() {
	for (int i = sortedStart; i <= sortedEnd; i++) {
		cout << heap[i] << " ";
	}
	cout << endl;
}