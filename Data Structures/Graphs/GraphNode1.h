#ifndef GRAPHNODE1_H
#define GRAPHNODE1_H
#include <iostream>
using namespace std;

class GraphNode {
	public:
		int vertexContained;
		string color = "white";
		GraphNode** predecessor = nullptr;
		int iniTime = 0;
		int finTime = 0;
};

#endif
