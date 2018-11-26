/*
Ant class will create ants and initialise
pheomone its current positon its previous position
and the list of covered nodes in a vector 
*/
#pragma once
#include "Colony.h"
//structure to bind all the members of an ant
struct ant
{
	double pheromone;
	double currentPosition;
	double previousPosition;
	vector<double> nodeMemory;
};

class Ant
{
	//vector to hold the ants
	vector<ant> ant;
	Graph *gp;
public:
	//constructor
	Ant();
	
	//method to initialise the properties of ants
	void initialiseAnts(Graph&);
	
	//method to return the number of ants
	void updateAnt(double,double);
	
	//method to return the number of ants
	int returnNumberOfAnts();
	
	//method to display all the ants
	void displayAnts();
	
	//method to make a tour trough the graph
	void antTour(Graph&);
	
	//method to get thr next vertex of an ant
	double getProbability(Graph&,double,double);
	
	//method that evouporates the pheromone on edges
	void evouparatePheromone(Graph&);
	
	//method to update the pherone after the ant tour
	void updatePheromone(Graph&,double,double);
	
	//method to display the ant tour
	void displayPath();
	
	//destructor
	~Ant();
};

