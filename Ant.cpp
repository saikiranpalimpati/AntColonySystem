#include "Ant.h"

Ant::Ant(Graph &gp, int a, double x, int y, int z)
{
	Gph = &gp;
	index = a;
	pheromone = x;
	position = y;
	path.push_back(z);
}

int Ant::displayIndexNumber()
{
	return index;
}

int Ant::getTheCurrentPosition()
{
	return position;
}

int Ant::nextPostionByNearestNeighbour(int currentPosition,int previousPosition)
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
			if (distance < minDistance && i!=currentPosition && to!=previousPosition)
			{
				nextPos = to;
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
	cout << "displaying the path" << endl;
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

Ant::~Ant()
{
}

