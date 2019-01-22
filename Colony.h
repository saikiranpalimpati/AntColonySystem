/*colony class will take a graph and hold the individual ants.
It makes the ant to move around the graph and tour trough all the cities(or vertices)
on the graph using different algorithms.
*/
#pragma once
#include"Ant.h"
//header files

class Colony
{
	Graph *Gph;
	//graph variable
	vector<Ant> Ants;
	//vector to hold the ant objects

public:

	//initilaising the graph in a colony
	Colony(Graph&);

	//initilaising the ants
	void initialiseAnts();

	//dispalying the ant attributes
	void displayAnts();

	//make ants tour around the graph by using nearest neighbour algorithm
	void AnttourUsingNearestNeighbourAlgorithm(int);

	//destructor
	~Colony();
};
