#pragma once
#include"colony.h"
using namespace std;
Colony::Colony(Graph &g)
{
	Gph = &g;
}

void Colony::initialiseAnts(Graph &g)
{
	Ants.push_back(Ant(g, 11, 1, 0, 0));
}

void Colony::displayAnts()
{
	for (auto it : Ants)
	{
		cout << "Index of Ant" << it.displayIndexNumber() << endl;
		cout << "Current position Of Ant" << it.getTheCurrentPosition() << endl;
		cout << "pheromone level of Ant" << it.displayPheromone() << endl;
		cout << endl;
		for (auto it1 : it.returnPath())
		{
			cout << it1 << endl;
		}
	}
}

void Colony::AnttourUsingGreddyALgorithm()
{
	int go = 0;
	vector<bool> visited;
	int graphSize = Gph->returnNumberOfVertices();
	for (int i = 0; i <= graphSize; i++)
	{
		visited.push_back(false);
	}
	cout << "the visited vector before is" << endl;
	for (auto it : visited)
	{
		cout << it << endl;
	}
	int stop = 0;
	for (auto it : Ants)
	{
		int currentPosition = it.getTheCurrentPosition();
		cout << "intial postion" << currentPosition << endl;
		visited[currentPosition] = true;
		int previousPosition = currentPosition;
		int nextPosition = 0;
		while (stop == 0 && nextPosition >= 0)
		{
			stop = 1;
			cout << "current position" << currentPosition << endl;
			cout << "previousPosition" << previousPosition << endl;
		    nextPosition = it.nextPostionByNearestNeighbour(currentPosition, previousPosition);
			cout << "nextposition " << nextPosition << endl;
			previousPosition = currentPosition;
			currentPosition = nextPosition;
			it.updatePosition(currentPosition);
			visited[currentPosition] = true;
			for (auto itr : visited)
			{
				if (itr == 0)
				{
					stop = 0;
				}
			}
		}
	}
	cout << "the visited vector after is" << endl;
	for (auto it : visited)
	{
		cout << it << endl;
	}


}

Colony::~Colony()
{
}
