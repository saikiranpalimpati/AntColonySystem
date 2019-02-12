/* The ant class has some data for each ant such as pheromone
 its positon. the path it has travelled previously and the distance
  travelled by it */
#pragma once
#include "Graph.h"
  //structure to bind all the members of an ant

class Ant
{
	Graph *Gph;

	//unique index for each ant
	int index;
	//poheromone level of the ant
	double pheromone;
	//position of the ant on a graph
	int position;
	//vector to track the path of the ant
	vector<int> path;
	//distance travelled by the ant
	double distanceTravelled;
	vector<int> visit;

public:
	//ant constructor
	Ant(Graph&, int, double, int);

	//method to display the ant index number
	int displayIndexNumber();

	//method to display the current position 
	int getTheCurrentPosition();

	//method to find the next positon of the ant
	int nextPostionByNearestNeighbour(int, int);

	//method to display the pheromone level of the ant
	double displayPheromone();

	//method to return the path
	vector<int> returnPath();

	//method to display the ant path
	void displayPath();

	//method to update the position of the ant 
	void updatePosition(int);

	//method to update the distance  travelled by the ant
	void updateDistance(int, int);

	//method to display the distance travelled by the ant
	double displayDistanceTravelled();

	void displayVisit();

	void antTourusingACS();

	void resetVisit();
	~Ant();
};