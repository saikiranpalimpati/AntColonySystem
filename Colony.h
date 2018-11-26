/*
colony class can display the graphs in it and 
can find the cost of path with greedy algortihm
it can initialise the pheromone accordingly
*/
#pragma once
#include"Graph.h"
class Colony
{
	Graph *Gph;
	//variable to access the graph class
public:
	Colony();
	//constructor
	void displayGraph(Graph&);
	//method to display folloing graph
	double greedyPath(Graph&,double);
	//method to calculate the cost with greedy algortihm
	void initialisePheromone(Graph&);
	//method to initialise pheromone
	~Colony();
	//destructor
};

