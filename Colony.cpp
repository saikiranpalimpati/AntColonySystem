#pragma once
#include"colony.h"
using namespace std;
#include<time.h>
Colony::Colony(Graph &g)
{
	Gph = &g;
}

void Colony::initialiseAnts()
{
	/*srand(time(NULL));
	int randmn = rand() % 4;
	//cout << "the rndm number is "<< randmn << endl;*/
	//push the ant in such a way that the  parameters are (graph variable, index, pheromone)
	Ants.push_back(Ant(*Gph, 11, 1));
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

void Colony::AnttourUsingNearestNeighbourAlgorithm(int postn)
{
	int go = 0;
	vector<bool> visited;
	int graphSize = Gph->returnNumberOfVertices();
	for (int i = 0; i <= graphSize; i++)
	{
		visited.push_back(false);
	}

	int stop = 0;
	for (auto it : Ants)
	{
		int initialPOsition = postn;
		int currentPosition = initialPOsition;
		visited[currentPosition] = true;
		int previousPosition = currentPosition;
		int nextPosition = 0;
		it.updatePosition(currentPosition);
		while (stop == 0 && nextPosition >= 0)
		{
			stop = 1;
			//cout << "current position" << currentPosition << endl;
			//cout << "previousPosition" << previousPosition << endl;
			nextPosition = it.nextPostionByNearestNeighbour(currentPosition, previousPosition);
			//cout << "nextposition " << nextPosition << endl;
			previousPosition = currentPosition;
			currentPosition = nextPosition;
			it.updatePosition(currentPosition);
			it.updateDistance(previousPosition,currentPosition);
			visited[currentPosition] = true;
			for (auto itr : visited)
			{
				if (itr == 0)
				{
					stop = 0;
				}
			}		
		}
		it.updateDistance(nextPosition,initialPOsition);
		it.updatePosition(postn);
		it.displayPath();
		cout << "the distance travelled by the ant is " << it.displayDistanceTravelled() << endl;;
	}

}

Colony::~Colony()
{
}
