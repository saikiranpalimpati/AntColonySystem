#pragma once
#include "Graph.h"
//structure to bind all the members of an ant

class Ant
{
	Graph *Gph;
	int index;
	double pheromone;
	int position;
	vector<int> path;
public:
	Ant(Graph&,int,double,int,int);
	int displayIndexNumber();
	int getTheCurrentPosition();
	int nextPostionByNearestNeighbour(int,int);
	double displayPheromone();
	vector<int> returnPath();
	void displayPath();
	void updatePosition(int);
	//int findNextVertex(Graph &g);
	~Ant();
};
