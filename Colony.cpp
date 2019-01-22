#pragma once
#include"colony.h"
using namespace std;


//constructor
Colony::Colony(Graph &g)
{
	Gph = &g;
}

void Colony::initialiseAnts()
{
	/*initialise ants into the vector by passing parameters
	as graph object, index number and pheromone*/ 
	Ants.push_back(Ant(*Gph, 11, 1));
}


void Colony::displayAnts()
{
	//iterate trough all the ants 
	for (auto it : Ants)
	{
		//print all the parameters of each ant
		cout << "Index of Ant" << it.displayIndexNumber() << endl;
		cout << "Current position Of Ant" << it.getTheCurrentPosition() << endl;
		cout << "pheromone level of Ant" << it.displayPheromone() << endl;
		cout << endl;
		// print the path travelled by each ant
		for (auto it1 : it.returnPath())
		{
			cout << it1 << endl;
		}
	}
}

void Colony::AnttourUsingNearestNeighbourAlgorithm(int postn)
{
	vector<bool> visited;
	/*
	vector is used to keep track wether all the nodes are visited
	by the ant or not */

	//the size of the vector will be the size of the graph
	int graphSize = Gph->returnNumberOfVertices();

	for (int i = 0; i <= graphSize; i++)
	{
		visited.push_back(false);
		//initially put all the vertices as not visited
	}

	int stop = 0;
	//variable which lets us know to stop running the algorithm


	for (auto it : Ants)
	{
		//the initaial position will be the starting position of the ant
		int initialPOsition = postn;

		//the current positon will be the starting position of the ant
		int currentPosition = initialPOsition;

		//the ant has already been there so mark it true
		visited[currentPosition] = true;

		//initially the previous and current positions are same
		int previousPosition = currentPosition;
	
		//the next position the ant ig going to move is kept 0 st the begin
		int nextPosition = 0;

		//update the current positon with ant
		it.updatePosition(currentPosition);

		//the while loop stops when it covers all the vertices a
		while (stop == 0 )
		{
			//initially the set the stop not to be 0
			stop = 1;
			
			//next position is calculated using nearest neighbour algorithm
			nextPosition = it.nextPostionByNearestNeighbour(currentPosition, previousPosition);
			
			/*
			now set the preivous position to be as the current 
			and the current postion as the previous and then 
			update the positiona nd the distacne travelled by the ant
			*/
			previousPosition = currentPosition;
			currentPosition = nextPosition;
			it.updatePosition(currentPosition);
			it.updateDistance(previousPosition, currentPosition);

			//set the current position as visited 
			visited[currentPosition] = true;

			/* now check the visited vertex to see wether
			   the ant covered all the vertices */
			for (auto itr : visited)
			{
				if (itr == 0)
				{
					stop = 0;
				}
			}
		}

		/* the ant should now go back to the initial 
		postion so accordingly update the position and distance
		*/
		it.updateDistance(nextPosition, initialPOsition);
		it.updatePosition(postn);

		//display the overall path travelled by the ant
		it.displayPath();
		
		//print the total distance travelled by the ant during the tour
		cout << "the distance travelled by the ant is " << it.displayDistanceTravelled() << endl;;
	}

}

Colony::~Colony()
{
}
