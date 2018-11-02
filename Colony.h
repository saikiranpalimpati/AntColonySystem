#pragma once
#include"Graph.h"
class Colony
{
	Graph *Gph;
public:
	Colony();
	void displayGraph(Graph&);
	double greedyPath(Graph&,double);
	~Colony();
};

