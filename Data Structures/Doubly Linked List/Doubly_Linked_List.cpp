#include "Doubly_Linked__List.h"
#include <vector>

DoublyLinkedList::DoublyLinkedList() {
	int num, k;
	cout << "Enter total number of integers for linked list" << endl;
	cin >> num;
	cout << "Do you want unsorted list (0) or sorted list (1)" << endl;
	cin >> k;
	if (k == 0) {
		for (int i = 0; i < num; i++) {
			cout << "Do you want to insert at head (0) or at tail (1)" << endl;
			cin >> k;
			if (k == 0) {
				cout << "Enter number" << endl;
				cin >> k;
				insertHead(k);
			}
			else if (k == 1) {
				cout << "Enter number" << endl;
				cin >> k;
				insertTail(k);
			}
			printForward();
			printBackward();
		}
	}
	else if (k == 1) {
		for (int i = 0; i < num; i++) {
			cout << "Enter a number" << endl;
			cin >> k;
			insertSorted(k);
			printForward();
			printBackward();
		}
	}
	cout << "Do you want to insert a node at nth position? (0)" << endl;
	cin >> num;
	if (num == 0) {
		cout << "At which position?" << endl;
		cin >> num;
		cout << "Enter the number" << endl;
		cin >> k;
		insertNth(num, k);
		printForward();
		printBackward();
	}
	cout << "Do you want to delete a node? (0)" << endl;
	cin >> num;
	if (num == 0) {
		cout << "At which position?" << endl;
		cin >> num;
		deleteNode(num);
		printForward();
		printBackward();
	}
	cout << "Do you want to find and swap two nodes (0) or not (1)" << endl;
	cin >> k;
	if (k == 0) {
		int n;
		cout << "Enter first value" << endl;
		cin >> k;
		cout << "Enter second value" << endl;
		cin >> n;
		search2Vals(k, n);
		printForward();
		printBackward();
	}
	cout << "Do you want to group evens and odds (0) or not (1)" << endl;
	cin >> k;
	if (k == 0) {
		oddEven();
		printForward();
		printBackward();
	}
	cout << "Do you want to destroy the list (0) or not (1)" << endl;
	cin >> k;
	if (k == 0) {
		destroyList();
	}
	cout << "Forward Print is" << endl;
	printForward();
	cout << "Backward Print is" << endl;
	printBackward();
}
Node* DoublyLinkedList::getNewNode(int k) {
	Node* node = new Node;
	node->num = k;
	node->next = nullptr;
	node->prev = nullptr;
	return node;
}
void DoublyLinkedList::insertHead(int k) {
	Node* node = getNewNode(k);
	if (head == nullptr) {
		head = node;
		return;
	}
	node->next = head;
	head->prev = node;
	head = node;
}
void DoublyLinkedList::insertTail(int k) {
	Node* node = getNewNode(k);
	if (head == nullptr) {
		head = node;
		return;
	}
	Node* temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	node->prev = temp;
	temp->next = node;
}
void DoublyLinkedList::insertNth(int pos, int k) {
	Node* temp = new Node; Node* temp1 = new Node;
	temp = head;
	for (int i = 0; i < pos - 2; i++) {
		temp = temp->next;
		temp1 = temp->next;
	}
	Node* node = getNewNode(k);
	temp->next = node;
	temp1->prev = node;
	node->prev = temp;
	node->next = temp1;
	temp = nullptr;
	temp1 = nullptr;
}
void DoublyLinkedList::printForward() {
	Node* temp = head;
	if (temp == nullptr) {
		return;
	}
	cout << "Forward Print is " << endl;
	while (temp != nullptr) {
		cout << temp->num << " ";
		temp = temp->next;
	}
	cout << endl;
}
void DoublyLinkedList::printBackward() {
	Node* temp = head;
	if (temp == nullptr) {
		return;
	}
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	cout << "Reverse Print is " << endl;
	while (temp != nullptr) {
		cout << temp->num << " ";
		temp = temp->prev;
	}
	cout << endl;
}
void DoublyLinkedList::oddEven() {
	if (head == nullptr || (head->next == nullptr && head->prev == nullptr)) {
		return;
	}
	vector<Node*> evens; vector<Node*> odd;
	Node* temp = head;
	while (temp != nullptr) {
		if (temp->num % 2 == 0) {
			evens.push_back(temp);
		}
		else if (temp->num % 2 != 0) {
			odd.push_back(temp);
		}
		temp = temp->next;
	}
	if (evens.empty() || odd.empty()) {
		return;
	}
	Node* temp1 = nullptr; temp = evens[0];
	for (int i = 0; i < evens.size() - 1; i++) {
		temp->next = evens[i + 1];
		temp->prev = temp1;
		if (i == 0) {
			head = temp;
		}
		temp = evens[i + 1];
		temp1 = evens[i];
	}
	temp->next = odd[0];
	temp->prev = temp1;
	temp1 = temp;
	temp = odd[0];
	for (int i = 0; i < odd.size() - 1; i++) {
		temp->next = odd[i + 1];
		temp->prev = temp1;
		temp = odd[i + 1];
		temp1 = odd[i];
	}
	temp->next = nullptr;
	temp->prev = temp1;
}
void DoublyLinkedList::search2Vals(int k, int n) {
	if (head == nullptr || (head->next == nullptr && head->prev == nullptr)) {
		return;
	}
	Node* temp = head; Node* temp1 = head; int count = 0; int count1 = 0;
	while ((temp != nullptr && temp1 != nullptr) && (k != temp->num || n != temp1->num)) {
		if (k == temp->num) {
			if (n != temp1->num) {
				temp1 = temp1->next;
			}
			count += 1;
		}
		else if (n == temp1->num) {
			temp = temp->next;
			count1 += 1;
		}
		else {
			temp = temp->next;
			temp1 = temp1->next;
		}
	}
	if (temp == nullptr && temp1 == nullptr) {
		cout << "Both values not found. Swap not possible" << endl;
		return;
	}
	else if (temp == nullptr) {
		cout << "First value not found. Swap not possible" << endl;
		return;
	}
	else if (temp1 == nullptr) {
		cout << "Second value not found. Swap not possible" << endl;
		return;
	}
	if (count < count1) {
		Node* t = temp;
		temp = temp1;
		temp1 = t;
	}
	if (temp->next == temp1 && temp1->prev == temp && temp->next->next == nullptr && temp1->prev->prev == nullptr) {
		head = temp1;
		head->next = temp;
		head->prev = nullptr;
		temp->prev = head;
		temp->next = nullptr;
		return;
	}
	else if (temp->next == temp1) {
		Node* temp2 = temp->prev; Node* temp3 = temp1->next;
		if (temp->prev == nullptr) {
			head = temp1;
			temp->next = temp1->next;
			temp1->next = temp;
			temp1->prev = nullptr;
			temp->prev = temp1;
			temp->next->prev = temp;
			return;
		}
		else if (temp1->next == nullptr) {
			temp->next = nullptr;
			temp1->next = temp;
			temp1->prev = temp->prev;
			temp->prev = temp1;
			temp1->prev->next = temp1;
			return;
		}
		temp2->next = temp1;
		temp3->prev = temp;
		temp1->prev = temp2;
		temp1->next = temp;
		temp->next = temp3;
		temp->prev = temp1;
		return;
	}
	else if (temp == head) {
		Node* temp2 = temp1->prev; Node* temp3 = temp1->next;
		head = temp1;
		if (temp1->next == nullptr) {
			temp1->prev = nullptr;
			temp1->next = temp->next;
			temp->next->prev = temp1;
			temp2->next = temp;
			temp->next = temp3;
			temp->prev = temp2;
			return;
		}
		temp1->prev = nullptr;
		temp1->next = temp->next;
		temp->next->prev = temp1;
		temp2->next = temp;
		temp3->prev = temp;
		temp->prev = temp2;
		temp->next = temp3;
		return;
	}
	else if (temp1->next == nullptr) {
		Node* temp2 = temp1->prev; Node* temp3 = temp->prev;
		temp1->prev = temp3;
		temp1->next = temp3->next->next;
		temp3->next = temp1;
		temp1->next->prev = temp1;
		temp->next = nullptr;
		temp->prev = temp2;
		temp2->next = temp;
		return;
	}
	Node* temp2 = temp->prev; Node* temp3 = temp1->next;
	temp2->next = temp1;
	temp3->prev = temp;
	temp1->prev = temp2;
	temp1->next = temp->next;
	temp->next = temp3;
	temp3 = temp1->next;
	temp3->prev = temp1;
	while (temp3->next != temp1) {
		temp3 = temp3->next;
	}
	temp3->next = temp;
	temp->prev = temp3;
}
void DoublyLinkedList::deleteNode(int pos) {
	Node* temp = new Node; Node* temp1 = new Node; Node* temp2 = new Node;
	temp = head;
	for (int i = 0; i < pos - 1; i++) {
		temp = temp->next;
	}
	if (temp->next == nullptr) {
		temp1->next = nullptr;
		delete temp;
		temp = nullptr;
		return;
	}
	temp1 = temp->next;
	temp2 = temp->prev;
	temp2->next = temp->next;
	temp1->prev = temp->prev;
	delete temp;
	temp = nullptr;
	temp1 = nullptr;
	temp2 = nullptr;
	return;
}
void DoublyLinkedList::destroyList() {
	Node* temp;
	while (head != nullptr) {
		temp = head;
		head = head->next;
		delete temp;
	}
}
int DoublyLinkedList::deleteFront() {
	Node* temp = head;
	int k = head->num;
	head = head->next;
	head->prev = nullptr;
	delete temp;
	return k;
}
int DoublyLinkedList::deleteBack() {
	Node* temp = head;
	while (temp->next->next != nullptr) {
		temp = temp->next;
	}
	Node* temp1 = temp->next;
	int k = temp1->num;
	temp->next = nullptr;
	delete temp1;
	return k;
}
void DoublyLinkedList::insertSorted(int k) {
	if (head == nullptr) {
		insertHead(k);
		return;
	}
	Node* temp1; Node* temp2;
	temp1 = nullptr; temp2 = head;
	while (temp2 != nullptr && temp2->num <= k) {
		temp1 = temp2;
		temp2 = temp2->next;
	}
	if (temp2 == nullptr) {
		Node* nn = new Node;
		nn->next = temp2;
		nn->prev = temp1;
		nn->num = k;
		temp1->next = nn;
		return;
	}
	Node* nn = new Node;
	nn->next = temp1->next;
	nn->prev = temp1;
	temp1->next = nn;
	temp2->prev = nn;
	nn->num = k;
}