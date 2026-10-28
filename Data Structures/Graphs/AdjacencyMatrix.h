#ifndef ADJACENCYMATRIX_H
#define ADJACENCYMATRIX_H
#include "GraphNode1.h"

class AdjacencyMatrix {
	private:
		int size;
		GraphNode*** graph;
	public:
		AdjacencyMatrix();
		void initializeMatrix();
		void insertEdge(int n1, int n2, int choice);
		void bfs(int start);
		void dfs();
		void dfsHelper(GraphNode** u);
		void deleteEdge(int n1, int n2, int choice);
		void printGraph();
};

#endif
