//header files
#include "Ant.h"
#include<time.h>
#include<set>

//constructor
Ant::Ant()
{
}

//method to initalise the ants
void Ant::initialiseAnts(Graph &g)
{
	gp = &g;
	//randomn number generator
	srand(time(NULL));
	//get number of vertices
	int numOfVertices = gp->returnNumberOfVertices();
	//initialise the size of ants
	ant.resize(2);

	//initialise a random postion to ants
	for (int i = 0; i < ant.size(); i++)
	{
		int randPosition = rand() % 4;
		ant[i].currentPosition = randPosition;
		//at the begining ants will have the current and
		//previous position to be the same
		ant[i].previousPosition = randPosition;
		//initialise the ants pheromone to be 1
		ant[i].pheromone = 1.0;
		//resize the ants node memory as 100
		ant[i].nodeMemory.reserve(100);
	}

}

//method to return the ant number
int  Ant::returnNumberOfAnts()
{
	return ant.size();
}

//method to display all the ants
void Ant::displayAnts()
{
	for (auto it : ant)
	{
		cout << "position" << it.currentPosition;
		cout << "pheromone" << it.pheromone;
		cout << endl;
	}
}

//method to tour around the graph
void Ant::antTour(Graph&g)
{
	gp = &g;
	int numOfVertices = gp->returnNumberOfVertices();
	
	//method to hold all the nodes in a graph
	vector<double> node;

	//initialise all the nodes
	for (int i = 0; i < numOfVertices; i++)
	{
		node.push_back(i);
	}

	//iterate to all the ants
	for (auto it : ant)
	{
		//let source be the initial position of an ant
		double source = it.currentPosition;

		//let end be the variable to keep track of the source
		double end = source;
		
		//pushback the source into finish nodes  vector
		it.nodeMemory.push_back(source);

		//initially the previous will be the source
		double previousPos = source;
		int cntr = 0;
		cout << "source" << source << endl;
		while (source != end || cntr == 0)
		{

			double mosProVertex = getProbability(g, source, previousPos);
			previousPos = source;
			source = mosProVertex;

			cntr++;
			cout << " nxt position  " << mosProVertex;
			it.nodeMemory.push_back(mosProVertex);
		}
		cout << endl;
	}
}

double Ant::getProbability(Graph&g, double from, double back)
{
	gp = &g;
	vector<vector<edge>> temp = g.returnGraph();
	int numberOfVertices = gp->returnNumberOfVertices();
	vector<double> probability(numberOfVertices);
	double distanceSqr;
	double n;
	double sum = 0;
	for (auto it : temp.at(from))
	{
		distanceSqr = ((it.distance)*(it.distance));
		n = (1 / distanceSqr);
		sum += (n*it.pheromone);
	}
	double numerator;
	distanceSqr = 0;
	n = 0;
	probability[from] = 0;

	for (auto it : temp.at(from))
	{
		distanceSqr = ((it.distance)*(it.distance));
		n = (1 / distanceSqr);
		numerator = ((n*it.pheromone) / sum);
		probability[it.to] = numerator;
	}
	probability[back] = 0;
	double max = 0;
	double counter = -1;
	double position = -1;
	for (auto it : probability)
	{
		counter++;
		if (it > max)
		{
			max = it;
			position = counter;
		}
	}
	return position;
}


void Ant::display()
{
	for (auto it : ant)
	{
		for (auto it2 : it.nodeMemory)
		{
			cout << "here" << endl;
			cout << it2 << endl;
		}
		cout << endl << endl;
	}
}

Ant::~Ant()
{
}