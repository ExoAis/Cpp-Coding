#include "HashTables.h"

int main() {
	HashTable table;
	table.initializeTable();
	table.Insert(5);
	table.Insert(7);
	table.Insert(3);
	table.Insert(2);
	table.Insert(9);
	table.printTable();
	table.Delete(9);
	table.printTable();

	return 0;
}