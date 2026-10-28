#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H
#include "AdjacentNodes.h"

class AdjacencyList {
	private:
		GraphNodeL* start = nullptr;
		GraphNodeL* end = nullptr;
	public:
		AdjacencyList();
		GraphNodeL* getNewNode();
		void initializeList(int size);
		void insertVertex(int n1, int n2, int choice);
		void bfs(int start);
		void dfs();
		void dfsHelper(AdjacentNodes* adjNodes, GraphNodeL* n);
		bool cycleCheckerDirected(int node, bool vis[], bool* dfsVis);
		bool cycleDetectorDirected(int n);
		bool cycleCheckerUndirected(int node, bool vis[], int pNode);
		bool cycleDetectorUndirected(int n);
		void printList();
};

#endif
