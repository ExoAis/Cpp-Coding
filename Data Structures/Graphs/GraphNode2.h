#ifndef GRAPHNODE2_H
#define GRAPHNODE2_H
class AdjacentNodes;
#include "AdjacentNodes.h"
#include <iostream>
using namespace std;

class GraphNodeL {
	public:
		int val = 0;
		GraphNodeL* data = nullptr;
		GraphNodeL* bottom = nullptr;
		GraphNodeL* next = nullptr;
		AdjacentNodes* adjNodes = nullptr;
		string color = "white";
		GraphNodeL* predecessor = nullptr;
		int iniTime = 0;
		int finTime = 0;
};

#endif
