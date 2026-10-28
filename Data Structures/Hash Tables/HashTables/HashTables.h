#ifndef HASHTABLES_H
#define HASHTABLES_H
#include <iostream>
#include "Node.h"
using namespace std;

class HashTable {
	private:
		int arraySize;
		int size = 0;
		Node* arr;
	public:
		int hashFunction(int x);
		void initializeTable();
		void Insert(int k);
		void Delete(int k);
		void printTable();
};

#endif
