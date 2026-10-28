#include "ABL.h"

int main() {
	ABL list;
	list.insertSorted(1);
	list.DeleteValue(1);
	list.printList();
	for (int i = 0; i < 6; i++) {
		list.insertSorted(i + 1);
	}
	list.printList();
	//list.insertSorted(8);
	//list.printList();
	//list.insertSorted(0);
	//list.printList();
	//list.insertAtposition(10, 3);
	//list.printList();
	cout << list.returnValue(5) << endl;

	return 0;
}