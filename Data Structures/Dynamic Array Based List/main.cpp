#include "DABL.h"

int main() {
	DABL dlist;
	int size; int k;
	cout << "Enter the size of array" << endl;
	cin >> size;
	dlist.size = size;
	for (int i = 0; i < size; i++) {
		cout << "Enter number" << endl;
		cin >> k;
		dlist.insertSorted(k);
	}
	dlist.printList();
	cout << "Do you want to delete the elements? Press 0 for Yes and 1 for No" << endl;
	cin >> size;
	if (size == 0) {
		cout << "How many elements do you want to delete?" << endl;
		cin >> size;
		for (int i = 0; i < size; i++) {
			cout << "Do you want to delete an element (0) or a particular position (1)?" << endl;
			cin >> k;
			if (k == 0) {
				cout << "Enter value" << endl;
				cin >> k;
				dlist.DeleteValue(k);
			}
			else {
				cout << "Enter position" << endl;
				cin >> k;
				dlist.DeleteValueAtPosition(k);
			}
		}
		cout << dlist.size << " " << dlist.length << endl;
		dlist.printList();
	}
	return 0;
}