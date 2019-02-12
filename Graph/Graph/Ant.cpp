#include "Ant.h"
#include<ctime>
#include<iomanip>

//initialise the ant
Ant::Ant(Graph &gp, int a, double x,int p)
{
	Gph = &gp;
	index = a;
	pheromone = x;
	distanceTravelled = 0;
	position = p;
	int graphSize = Gph->returnNumberOfVertices();
	visit.resize(graphSize);
}

//display the index number
int Ant::displayIndexNumber()
{
	return index;
}

//display the current position 
int Ant::getTheCurrentPosition()
{
	return position;
}


int Ant::nextPostionByNearestNeighbour(int currentPosition, int previousPosition)
{
	//let the next position initially be -1
	int nextPos = -1;

	//current position of the ant 
	int currenPos = currentPosition;

	//get the size of the graph
	int graphSize = Gph->returnNumberOfVertices();

	//initially let the minimum distance be too high
	double minDistance = 100000;

	//let the initial distance be zero
	double distance = 0;

	//traverse trough the graph
	for (int i = 0; i <= graphSize; i++)
	{

		int to = i;

		//get the distance between the vertices
		distance = Gph->getWeight(currenPos, to);

		//check that distance be the minimal and no back tracking 
		if (to != previousPosition && to != currentPosition && distance < minDistance)
		{
			minDistance = distance;
			nextPos = to;
		}
	}
	//return the next position
	return nextPos;
}

//display the pheromone
double Ant::displayPheromone()
{
	return pheromone;
}

//return the path
vector<int> Ant::returnPath()
{
	return path;
}

//dislay the path 
void  Ant::displayPath()
{
	cout << "displaying the path travelled by the ant" << endl;
	for (auto it : path)
	{
		cout << it << endl;
	}
}

//update the position of the ant
void Ant::updatePosition(int currentPosition)
{
	position = currentPosition;
	path.push_back(currentPosition);
	visit[currentPosition] = 1;
}

//update the distance
void Ant::updateDistance(int frm, int tw)
{
	double dis = Gph->getWeight(frm, tw);
	distanceTravelled += dis;
}

//display the distance travelled
double Ant::displayDistanceTravelled()
{
	return distanceTravelled;
}

void Ant::displayVisit()
{
	for (auto it : visit)
	{
		cout << it << endl;
	}
}

void Ant::antTourusingACS()
{
	cout << "current position of ant" <<position<< endl;
	updatePosition(position);
	srand(time(NULL));
	float q = ((double)rand() / (RAND_MAX));
	float q0 = ((double)rand() / (RAND_MAX));
	cout << "q" << q << "  q0  " << q0 << endl;
	int beta = 3;
	int currentpositon = position;
	vector<double> touTimesDistHeuristic;
	int graphSize = visit.size();
	touTimesDistHeuristic.resize(graphSize);
	bool flag = 0;
	cout << "flag" << flag << endl;
	while (flag == 0)
	{
		for (int i = 0; i < graphSize; i++)
		{
			double distance = Gph->getWeight(currentpositon, i);
			double pheromone = Gph->getPheomone(currentpositon, i);
			double distanceSqr = (distance * distance);
			double heuristic = (pheromone*(1 / distanceSqr));
			if (i != currentpositon)
			{
				touTimesDistHeuristic[i] = heuristic;
				cout << "heuristic" << heuristic << endl;
			}
			else { touTimesDistHeuristic[i] = 0; }
		}
		double maxValue = 0;
		int pos = currentpositon;
		for (int i = 0; i < touTimesDistHeuristic.size(); i++)
		{
			if (touTimesDistHeuristic[i] > maxValue && visit[i] == 0)
			{
				maxValue = touTimesDistHeuristic[i];
				pos = i;
			}
		}
		cout << "next position" << pos << endl;
		updatePosition(pos);
		flag = 1;
		for (int j = 0; j < visit.size(); j++)
		{
			if (visit[j] == 0)
			{
				flag = 0;
			}
		}
		currentpositon = pos;
	}
}

void Ant::resetVisit()
{
	for (auto it : visit)
	{
		it = 0;
	}
}

Ant::~Ant()
{
}