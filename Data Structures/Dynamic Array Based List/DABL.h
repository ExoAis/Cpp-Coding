#ifndef ABL_H
#define ABL_H
#include <iostream>
using namespace std;

class DABL {
	public:
		int size; int length = -1;
		int* a = new int[size];
		bool isEmpty();
		bool isFull();
		void sort();
		void insertAtposition(int value, int position);
		void insertSorted(int value);
		void printList();
		void DeleteValue(int value);
		void DeleteValueAtPosition(int pos);
		void DynamicExpansion();
		void DynamicReduction();
};

#endif