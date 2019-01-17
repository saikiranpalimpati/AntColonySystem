#pragma once
#include"Ant.h"


class Colony
{
	Graph *Gph;
	vector<Ant> Ants;
public:
	Colony(Graph&);
	void initialiseAnts(Graph&);
	void displayAnts();
	void AnttourUsingGreddyALgorithm();
	~Colony();
};
