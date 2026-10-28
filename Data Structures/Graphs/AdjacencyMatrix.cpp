#include "AdjacencyMatrix.h"
#include <queue>

int tim;
AdjacencyMatrix::AdjacencyMatrix() {
	int choice;
	cout << "Press 0 for Directed Graph and 1 for Undirected Graph" << endl;
	cin >> choice;
	cout << "Enter number of vertices in the graph" << endl;
	cin >> size;
	graph = new GraphNode**[size];
	initializeMatrix();
	int n1, n2;
	cout << "Enter Edges in numbers with space in between/-1, -1 to Exit" << endl;
	cin >> n1 >> n2;
	while (n1 != -1 && n2 != -1) {
		insertEdge(n1 - 1, n2 - 1, choice);
		printGraph();
		cout << "Enter Edges in numbers with space in between/-1, -1 to Exit" << endl;
		cin >> n1 >> n2;
	}

	int start;
	cout << "Enter Vertex to start Breadth First Search From" << endl;
	cin >> start;
	cout << "Breadth First Traversal of the Graph is " << endl;
	bfs(start - 1);
	cout << endl << endl;
	cout << "Depth First Traversal of the Graph is " << endl;
	dfs();
}
void AdjacencyMatrix::initializeMatrix() {
	for (int i = 0; i < size; i++) {
		graph[i] = new GraphNode*[size];
		for (int j = 0; j < size; j++) {
			graph[i][j] = nullptr;
		}
	}
}
void AdjacencyMatrix::insertEdge(int n1, int n2, int choice) {
	graph[n1][n2] = new GraphNode;
	graph[n1][n2]->vertexContained = n1;
	if (choice == 1) {
		graph[n2][n1] = new GraphNode;
		graph[n2][n1]->vertexContained = n2;
	}
}
void AdjacencyMatrix::bfs(int start) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (graph[i][j] != nullptr) {
				graph[i][j]->color = "white";
				graph[i][j]->predecessor = nullptr;
			}
		}
	}
	queue<GraphNode**> queue;
	queue.push(graph[start]);
	GraphNode** u;
	GraphNode* v;
	int val;
	cout << start + 1 << " ";
	v = graph[start][start];
	if (v != nullptr) {
		v->color = "black";
	}
	while (!queue.empty()) {
		u = queue.front();
		queue.pop();
		for (int i = 0; i < size; i++) {
			v = u[i];
			if (v != nullptr) {
				if (v->color == "white") {
					val = v->vertexContained;
					v->color = "black";
					v->predecessor = u;
					cout << i + 1 << " ";
					queue.push(graph[i]);
					if (graph[i][val] != nullptr) {
						graph[i][val]->color = "black";
					}
					for (int j = 0; j < size; j++) {
						if (graph[j][i] != nullptr) {
							graph[j][i]->color = "black";
						}
					}
				}
			}
		}
	}
	cout << endl;
}
void AdjacencyMatrix::dfs() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (graph[i][j] != nullptr) {
				graph[i][j]->color = "white";
				graph[i][j]->predecessor = nullptr;
			}
		}
	}
	GraphNode** u;
	tim = 0;
	for (int i = 0; i < size; i++) {
		u = graph[i];
		if (u[i] != nullptr) {
			u[i]->color = "black";
		}
		if (i == 0) {
			cout << "1 : 0" << endl;
			for (int j = 0; j < size; j++) {
				if (graph[j][i] != nullptr) {
					graph[j][i]->color = "black";
				}
			}
		}
		dfsHelper(u);
	}
	cout << "1 : " << tim << endl;
}
void AdjacencyMatrix::dfsHelper(GraphNode** u) {
	GraphNode* v;
	tim++;
	int val;
	for (int i = 0; i < size; i++) {
		if (u[i] != nullptr) {
			v = u[i];
			if (v->color == "white") {
				val = v->vertexContained;
				v->color = "black";
				v->predecessor = u;
				v->vertexContained = i;
				v->iniTime = tim;
				cout << i + 1 << " : " << v->iniTime << endl;
				if (graph[i][val] != nullptr) {
					graph[i][val]->color = "black";
				}
				for (int j = 0; j < size; j++) {
					if (graph[j][i] != nullptr) {
						graph[j][i]->color = "black";
					}
				}
				dfsHelper(graph[i]);
				v->finTime = tim;
				cout << i + 1 << " : " << v->finTime << endl;
				tim++;
			}
		}
	}
}
void AdjacencyMatrix::deleteEdge(int n1, int n2, int choice) {
	delete graph[n1][n2];
	graph[n1][n2] = nullptr;
	if (choice == 1) {
		delete graph[n2][n1];
		graph[n2][n1] = nullptr;
	}
}
void AdjacencyMatrix::printGraph() {
	cout << "Normal Print of Graph is" << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (graph[i][j] != nullptr) {
				cout << "1" << " ";
			}
			else {
				cout << "0" << " ";
			}
		}
		cout << endl;
	}
}