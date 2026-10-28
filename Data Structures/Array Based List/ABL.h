#ifndef ABL_H
#define ABL_H
#include <iostream>
using namespace std;

class ABL {
	private:
		int length = -1;
		int a[10];
	public:
		bool isEmpty();
		bool isFull();
		void sort();
		int returnValue(int position);
		void insertAtposition(int value, int position);
		void insertSorted(int value);
		void printList();
		void DeleteValue(int value);
		void DeleteValueAtPosition(int pos);
};

#endif
