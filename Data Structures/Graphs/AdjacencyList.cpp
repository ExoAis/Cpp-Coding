#include "AdjacencyList.h"
#include <queue>

int ti;
AdjacencyList::AdjacencyList() {
	int n1, n2, size, choice;
	cout << "Press 0 for Directed Graph and 1 for Undirected Graph" << endl;
	cin >> choice;
	cout << "Enter number of Vertices" << endl;
	cin >> size;
	initializeList(size);
	cout << "Enter Edge With Space in Between" << endl;
	cin >> n1 >> n2;
	while (n1 != -1 && n2 != -1) {
		insertVertex(n1, n2, choice);
		cout << "Enter Edge With Space in Between" << endl;
		cin >> n1 >> n2;
	}
	printList();
	cout << endl << endl;
	int start;
	cout << "Enter Vertex to start BFS" << endl;
	cin >> start;
	cout << "Breadth First Search of Graph is" << endl;
	bfs(start);
	cout << endl << endl;
	cout << "Depth First Search of Graph is" << endl;
	dfs();
	if (choice == 0) {
		if (cycleDetectorDirected(size)) {
			cout << "Cycle has been detected in the Directed Graph" << endl;
		}
		else {
			cout << "No cycle has been detected in the Directed Graph" << endl;
		}
	}
	else if (choice == 1) {
		if (cycleDetectorUndirected(size)) {
			cout << "Cycle has been detected in the Undirected Graph" << endl;
		}
		else {
			cout << "No cycle has been detected in the Undirected Graph" << endl;
		}
	}
}
void AdjacencyList::initializeList(int size) {
	GraphNodeL* newNode;
	for (int i = 0; i < size; i++) {
		newNode = getNewNode();
		if (start == nullptr && end == nullptr) {
			start = newNode;
			end = start;
			continue;
		}
		end->bottom = newNode;
		end = newNode;
	}
}
GraphNodeL* AdjacencyList::getNewNode() {
	GraphNodeL* nn = new GraphNodeL;
	nn->next = nullptr;
	nn->data = nullptr;
	nn->adjNodes = new AdjacentNodes;
	return nn;
}
void AdjacencyList::insertVertex(int n1, int n2, int choice) {
	GraphNodeL* t, * s;
	t = nullptr;
	s = nullptr;
	for (int i = 0; i < n1; i++) {
		if (i == 0) {
			t = start;
		}
		else {
			t = t->bottom;
		}
	}
	for (int j = 0; j < n2; j++) {
		if (j == 0) {
			s = start;
		}
		else {
			s = s->bottom;
		}
	}
	t->adjNodes->insert(s, n2);
	if (choice == 1 && n1 != n2) {
		s->adjNodes->insert(t, n1);
	}
}
void AdjacencyList::bfs(int start) {
	GraphNodeL* t = this->start;
	while (t != nullptr) {
		t->color = "white";
		t->predecessor = nullptr;
		t = t->bottom;
	}
	for (int i = 0; i < start; i++) {
		if (i == 0) {
			t = this->start;
		}
		else {
			t = t->bottom;
		}
	}
	AdjacentNodes* u = nullptr;
	GraphNodeL* v = nullptr;
	GraphNodeL* s = nullptr;
	queue<AdjacentNodes*> queue;
	cout << start << " ";
	int counter = 0;
	queue.push(t->adjNodes);
	while (!queue.empty()) {
		u = queue.front();
		queue.pop();
		v = u->head;
		counter = 0;
		while (v != nullptr) {
			if (v->data->color == "white") {
				v->color = "black";
				v->data->color = "black";
				v->predecessor = t;
				cout << v->val << " ";
				for (int i = 0; i < v->val; i++) {
					if (counter == 0) {
						if (i == 0) {
							t->color = "black";
							t = this->start;
						}
						else {
							t = t->bottom;
						}
					}
					else {
						if (i == 0) {
							s = this->start;
						}
						else {
							s = s->bottom;
						}
					}
				}
				if (counter == 0) {
					queue.push(t->adjNodes);
				}
				else {
					queue.push(s->adjNodes);
				}
				counter++;
			}
			v = v->next;
		}
	}
}
void AdjacencyList::dfs() {
	GraphNodeL* t = start;
	ti = 0;
	while (t != nullptr) {
		t->color = "white";
		t->predecessor = nullptr;
		t = t->bottom;
	}
	t = start;
	while (t != nullptr) {
		dfsHelper(t->adjNodes, t);
		t = t->bottom;
	}
}
void AdjacencyList::dfsHelper(AdjacentNodes* adjNodes, GraphNodeL* n) {
	GraphNodeL* node = adjNodes->head;
	GraphNodeL* t = nullptr;
	while (node != nullptr) {
		if (node->data->color == "white") {
			node->color = "black";
			node->data->color = "black";
			node->iniTime = ti;
			node->predecessor = n;
			cout << node->val << " : " << node->iniTime << endl;
			ti++;
			for (int i = 0; i < node->val; i++) {
				if (i == 0) {
					t = start;
				}
				else {
					t = t->bottom;
				}
			}
			dfsHelper(t->adjNodes, t);
			ti++;
			node->finTime = ti;
			cout << node->val << " : " << node->finTime << endl;
		}
		node = node->next;
	}
}
bool AdjacencyList::cycleCheckerDirected(int node, bool vis[], bool* dfsVis) {
	GraphNodeL* Node = nullptr;
	for (int i = 0; i < node; i++) {
		if (i == 0) {
			Node = start;
		}
		else {
			Node = Node->bottom;
		}
	}
	AdjacentNodes* adjNodes = Node->adjNodes;
	Node = adjNodes->head;
	vis[node] = true;
	dfsVis[node] = true;
	while (Node != nullptr) {
		if (!vis[Node->val]) {
			if (cycleCheckerDirected(Node->val, vis, dfsVis)) {
				return true;
			}
		}
		else if (dfsVis[Node->val]) {
			return true;
		}
		Node = Node->next;
	}
	dfsVis[node] = false;
	return false;
}
bool AdjacencyList::cycleDetectorDirected(int n) {
	bool* vis = new bool[n + 1];
	bool* dfsVis = new bool[n + 1];
	for (int i = 1; i <= n; i++) {
		vis[i] = 0;
		dfsVis[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		if (cycleCheckerDirected(i, vis, dfsVis)) {
			return true;
		}
	}
	return false;
}
bool AdjacencyList::cycleCheckerUndirected(int node, bool vis[], int pNode) {
	GraphNodeL* Node = nullptr;
	for (int i = 0; i < node; i++) {
		if (i == 0) {
			Node = start;
		}
		else {
			Node = Node->bottom;
		}
	}
	AdjacentNodes* adjNodes = Node->adjNodes;
	Node = adjNodes->head;
	vis[node] = true;
	while (Node != nullptr) {
		if (vis[Node->val]) {
			if (Node->val != pNode) {
				return true;
			}
			return false;
		}
		if (cycleCheckerUndirected(Node->val, vis, node)) {
			return true;
		}
		Node = Node->next;
	}
	return false;
}
bool AdjacencyList::cycleDetectorUndirected(int n) {
	bool* vis = new bool[n + 1];
	for (int i = 1; i <= n; i++) {
		vis[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			if (cycleCheckerUndirected(i, vis, -1)) {
				return true;
			}
		}
	}
	return false;
}
void AdjacencyList::printList() {
	cout << endl << endl;
	GraphNodeL* t = start;
	int i = 1;
	while (t != nullptr) {
		cout << i << " : ";
		t->adjNodes->printList();
		t = t->bottom;
		i++;
		cout << endl;
	}
}