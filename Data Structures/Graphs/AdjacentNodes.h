#ifndef ADJACENTNODES_H
#define ADJACENTNODES_H
class GraphNodeL;
#include "GraphNode2.h"

class AdjacentNodes {
	public:
		GraphNodeL* head = nullptr;
		GraphNodeL* end = nullptr;
		void insert(GraphNodeL* data, int val);
		void deleteNode(GraphNodeL* data);
		void destroy();
		void printList();
};

#endif
