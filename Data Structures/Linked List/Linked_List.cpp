#include "Linked_List.h"

LinkedList::LinkedList() {
	int num, k, choice;
	cout << "Enter limit of Linked List" << endl;
	cin >> num;
	cout << "Do you want to enter elements at start of list (0) or at end of list (1)" << endl;
	cin >> choice;
	if (choice == 0) {
		for (int i = 0; i < num; i++) {
			cout << "Enter the number" << endl;
			cin >> k;
			insertBegin(k);
		}
	}
	else if (choice == 1) {
		for (int i = 0; i < num; i++) {
			cout << "Enter the number" << endl;
			cin >> k;
			insertEnd(k);
		}
	}
	printIterList();
	cout << endl;
	cout << "Recursive print is " << endl;
	printRecuList(head);
	printRecuRevList(head);
	cout << endl;
	cout << "Do you want to insert/delete the nodes (0) or not (1)?" << endl;
	cin >> num;
	if (num == 0) {
		cout << "Do you want to insert the nodes (0)?" << endl;
		cin >> num;
		if (num == 0) {
			cout << "How many nodes do you want to insert?" << endl;
			cin >> num;
			for (int i = 0; i < num; i++) {
				cout << "At which position do you want to enter the Node?" << endl;
				cin >> choice;
				cout << "Enter the number" << endl;
				cin >> k;
				insertNode(k, choice);
			}
		}
		cout << "Do you want to delete the nodes (0)?" << endl;
		cin >> num;
		if (num == 0) {
			cout << "How many nodes do you want to delete?" << endl;
			cin >> num;
			for (int i = 0; i < num; i++) {
				cout << "At which position do you want to delete the Node?" << endl;
				cin >> choice;
				deleteNode(choice);
			}
		}
	}
	cout << "Do you want to delete a specific value? Press 0 for Yes and 1 for No" << endl;
	cin >> num;
	if (num == 0) {
		cout << "How many values do you want to delete?" << endl;
		cin >> num;
		for (int i = 0; i < num; i++) {
			cout << "Which value do you want to delete?" << endl;
			cin >> choice;
			deleteValue(choice);
		}
	}
	printIterList();
	cout << endl;
	cout << "Recursive print is " << endl;
	printRecuList(head);
	printRecuRevList(head);
	cout << endl;
	cout << "Do you want to reverse the linked list (0)?" << endl;
	cin >> num;
	if (num == 0) {
		//reverseIterList();
		reverseRecuList(head);
	}
	printIterList();
	cout << endl;
	cout << "Recursive print is " << endl;
	printRecuList(head);
	printRecuRevList(head);
	cout << endl;
	cout << "Do you want to delete Odd Positions of List (0) or not (1)?" << endl;
	cin >> k;
	if (k == 0) {
		deleteOddPos();
		printIterList();
		cout << endl;
		cout << "Recursive print is " << endl;
		printRecuList(head);
		printRecuRevList(head);
		cout << endl;
	}
	cout << "Do you want to destroy the list? Press 0 for Yes and 1 for No" << endl;
	cin >> num;
	if (num == 0) {
		destroyList();
	}
	printIterList();
	cout << endl;
	cout << "Recursive print is " << endl;
	printRecuList(head);
	printRecuRevList(head);
	cout << endl;
}
void LinkedList::insertEnd(int k) {
	Node* temp;
	if (head == nullptr) {
		insertBegin(k);
		return;
	}
	temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	Node* node = new Node;
	node->num = k;
	node->next = nullptr;
	temp->next = node;
}
void LinkedList::insertBegin(int k) {
	Node* node;
	node = new Node;
	node->num = k;
	node->next = head;
	head = node;
}
void LinkedList::reverseRecuList(Node* ll) {
	Node* current; Node* next;
	if (ll->next == nullptr) {
		head = ll;
		return;
	}
	reverseRecuList(ll->next);
	next = ll->next;
	current = ll;
	next->next = current;
	current->next = nullptr;
}
void LinkedList::reverseIterList() {
	cout << endl << endl;
	Node* prev; Node* current; Node* next;
	current = head;
	prev = nullptr;
	while (current->next != nullptr) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	current->next = prev;
	head = current;
	prev = nullptr;
	next = nullptr;
}
void LinkedList::deleteNode(int position) {
	Node* temp = new Node;
	Node* temp1 = new Node;
	temp = head;
	for (int i = 0; i < position - 1; i++) {
		temp1 = temp;
		temp = temp->next;
	}
	temp1->next = temp->next;
	delete temp;
	temp = nullptr;
	temp1 = nullptr;
}
void LinkedList::deleteOddPos() {
	Node* temp = head;
	if (head == nullptr) {
		return;
	}
	else if (head->next == nullptr) {
		delete head;
		head = nullptr;
		return;
	}
	else if (head->next->next == nullptr) {
		temp = head;
		head = head->next;
		delete temp;
		return;
	}
	else {
		int count = 0; temp = head; Node* temp2 = head;
		while (temp->next != nullptr) {
			if (count == 0) {
				temp = head;
				head = temp->next;
				delete temp;
				temp = head;
			}
			else {
				temp2 = temp;
				temp = temp2->next;
				temp2->next = temp->next;
				delete temp;
				temp = temp2->next;
				if (temp == nullptr) {
					break;
				}
			}
			count += 1;
		}
	}
}
void LinkedList::deleteValue(int k) {
	if (head == nullptr) {
		return;
	}
	else if (head->num == k) {
		Node* temp = head;
		head = head->next;
		delete temp;
		return;
	}
	Node* temp = head->next; Node* temp1 = head;
	while (temp != nullptr && temp->num != k) {
		temp = temp->next;
		temp1 = temp1->next;
	}
	if (temp->num == k) {
		temp1->next = temp->next;
		delete temp;
	}
}
void LinkedList::destroyList() {
	if (head == nullptr) {
		return;
	}
	Node* temp;
	while (head != nullptr) {
		temp = head;
		head = temp->next;
		delete temp;
	}
}
void LinkedList::insertNode(int k, int position) {
	if (position == 0) {
		return;
	}
	else if (position == 1) {
		insertBegin(k);
		return;
	}
	Node* temp = new Node;
	temp = head;
	for (int i = 0; i < position - 2; i++) {
		temp = temp->next;
	}
	Node* node = new Node;
	node->num = k;
	node->next = temp->next;
	temp->next = node;
	temp = nullptr;
}
void LinkedList::printRecuList(Node* ll) {
	if (ll == nullptr) {
		return;
	}
	cout << ll->num << " ";
	printRecuList(ll->next);
}
void LinkedList::printRecuRevList(Node* ll) {
	if (ll == nullptr) {
		cout << endl;
		cout << "Recursive Reverse Print is " << endl;
		return;
	}
	printRecuRevList(ll->next);
	cout << ll->num << " ";
}
void LinkedList::printIterList() {
	Node* temp = head;
	cout << endl;
	cout << "Normal print is " << endl;
	while (temp != nullptr) {
		cout << temp->num << " ";
		temp = temp->next;
	}
	temp = nullptr;
}
Node* LinkedList::returnHead() {
	return head;
}