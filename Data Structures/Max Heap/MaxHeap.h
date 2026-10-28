#include <iostream>
using namespace std;
#ifndef MAXHEAP_H
#define MAXHEAP_H


class MaxHeap {
	private:
		int arraySize;
		int* heap = new int[arraySize];
		int heapSize = 0;
		int sortedStart = 0;
		int sortedEnd = 0;
	public:
		MaxHeap();
		void insert(int elem);
		void deleteRoot();
		void insertHeapify();
		void deleteHeapify();
		void printHeap();
		void printSortedList();
		void destroyHeap();
};

#endif
