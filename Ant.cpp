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
	}

}

void Ant::updateAnt(double index, double value)
{
	ant[index].nodeMemory.push_back(value);
}

//method to return the number of ants
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
	double index = 0;
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
		updateAnt(index, source);
		while (source != end || cntr == 0)
		{

			double mosProVertex = getProbability(g, source, previousPos);
			updatePheromone(g,source, mosProVertex);
			previousPos = source;
			source = mosProVertex;

			cntr++;
			cout << " nxt position  " << mosProVertex;
			updateAnt(index,mosProVertex);
			
		}
		index++;
		cout << endl;
	}
	evouparatePheromone(g);
}

//method to find the next vertex trough random probability rule
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

//method to evouporate the pheromone on edges
void Ant::evouparatePheromone(Graph &g)
{
	
	gp = &g;
	vector<vector<edge>> temp = gp->returnGraph();
	double newPheromone;
	//traverse trought all the edges
	for (auto it : temp)
	{
		for (auto x : it)
		{
			//newPheromone would be less than 40% the older one
			newPheromone = (x.pheromone*(.6));
			//changing the pheromone at that particular edge
			gp->changePheromone(x.from,x.to,newPheromone);
		}
	}
}

//method to update the pheromone trough the edges
void Ant::updatePheromone(Graph &g,double from,double to)
{
	gp = &g;
	double newPheromone=gp->getPheomone(from,to);
	double updatePheromone = newPheromone + (newPheromone*(.7));
	gp->changePheromone(from, to, updatePheromone);
	
}

//method to display the ant path
void Ant::displayPath()
{
	for (auto it : ant)
	{
		for (auto it2 : it.nodeMemory)
		{
		
			cout << it2 << endl;
		}
		cout << endl << endl;
	}
}

//destructor
Ant::~Ant()
{
}
