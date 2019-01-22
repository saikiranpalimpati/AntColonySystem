#include "Ant.h"

Ant::Ant(Graph &gp, int a, double x)
{
	Gph = &gp;
	index = a;
	pheromone = x;
	distanceTravelled = 0;
}

int Ant::displayIndexNumber()
{
	return index;
}

int Ant::getTheCurrentPosition()
{
	return position;
}

int Ant::nextPostionByNearestNeighbour(int currentPosition, int previousPosition)
{
	int nextPos = -1;
	int currenPos = currentPosition;
	int graphSize = Gph->returnNumberOfVertices();

	double minDistance = 100000;
	double distance = 0;
	for (int i = 0; i <= graphSize; i++)
	{
		int to = i;
		distance = Gph->getWeight(currenPos, to);

		if (to != previousPosition && to != currentPosition && distance < minDistance)
		{
			minDistance = distance;
			nextPos = to;
			//distanceTravelled += distance;
		}
	}
	return nextPos;
}

double Ant::displayPheromone()
{
	return pheromone;
}

vector<int> Ant::returnPath()
{
	return path;
}

void  Ant::displayPath()
{
	cout << "displaying the path travelled by the ant" << endl;
	for (auto it : path)
	{
		cout << it << endl;
	}
}

void Ant::updatePosition(int currentPosition)
{
	position = currentPosition;
	path.push_back(currentPosition);
}

void Ant::updateDistance(int frm, int tw)
{
	double dis = Gph->getWeight(frm,tw);
	distanceTravelled += dis;
}

double Ant::displayDistanceTravelled()
{
	return distanceTravelled;
}

Ant::~Ant()
{
}
