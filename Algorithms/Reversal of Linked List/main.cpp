#include "Linked_List.h"

int main() {
	LinkedList* list = new LinkedList;
	list->reversalStack();
	Node* head = list->returnHead();
	list->printIterList();
	cout << endl;
	cout << "Recursive Print is " << endl;
	list->printRecuList(head);
	list->printRecuRevList(head);

	return 0;
}