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
	int from = path[0];
	int size = path.size();
	double distance = 0;
	for (int i = 1; i < size; i++)
	{
		int to = path[i];
		distance+=Gph->getWeight(from, to);
		from = to;
	}
	return distance;
}

//display the visit vector
void Ant::displayVisit()
{
	for (auto it : visit)
	{
		cout << it << endl;
	}
}

void Ant::localPheromoneUpdate(int from, int to)
{

	double e = 0.1;
	double pheromone = Gph->getPheomone(from, to);
	double temppheromone = ((1 - 0.1)*pheromone) + (e*1);
	Gph->changePheromone(to,from,temppheromone);
}

//ant tour using acs
void Ant::antTourusingACS()
{
	//update the initial position
	updatePosition(position);

	srand(time(NULL));

	//initial position as current position
	int currentpositon = position;

	//vector to hold the heuristic values 
	vector<double> touTimesDistHeuristic;

	//get the size of a graph
	int graphSize = visit.size();
	touTimesDistHeuristic.resize(graphSize);

	//initially let the flag be 0
	bool flag = 0;
	int pos = currentpositon;

	//run till the flag is on (till it reaches all the vertices)
	while (flag == 0)
	{
		//generate two random numbers between 0 and 1
		float q = ((double)rand() / (RAND_MAX));
		float q0 = ((double)rand() / (RAND_MAX));

		//now calculate the heuristic
		for (int i = 0; i < graphSize; i++)
		{
			double distance = Gph->getWeight(currentpositon, i);
			double pheromone = Gph->getPheomone(currentpositon, i);
			double distanceSqr = (distance * distance);
			double heuristic = (pheromone*((1 / distanceSqr)*(1/distanceSqr)));
			if (i != currentpositon)
			{
				touTimesDistHeuristic[i] = heuristic;
			}
			//if from and to are same then let heuristic be 0
			else { touTimesDistHeuristic[i] = 0; }
		}
		//if the first randomn number is less than the second
		if (q < q0)
		{
			//extract the maximum heuristic value
			double maxValue = 0;
		    pos = currentpositon;
			for (int i = 0; i < touTimesDistHeuristic.size(); i++)
			{
				
				//check wether this is maximum and the it has not visited the vertex before
				if (touTimesDistHeuristic[i] > maxValue && visit[i] == 0)
				{
					maxValue = touTimesDistHeuristic[i];
					pos = i;
				}
			}	
			//update the position
			updatePosition(pos);

			localPheromoneUpdate(currentpositon,pos);
		}
		else
		{
			//let probablility vector have the values from random proportional rule
			vector<double> probability;
			probability.resize(graphSize);

			//let the denominator term be initialised as zero
			double denominator = 0;

			//now calculate the denominator
			for (auto it : touTimesDistHeuristic)
			{
				denominator += it;
			}
			//update the probability vector
			for (int i = 0; i < graphSize; i++)
			{
				probability[i] = (touTimesDistHeuristic[i]/denominator);
			}

			//extract the vertex with maximum probability
			double maxValue = 0;
			pos = currentpositon;
			for (int i = 0; i < probability.size(); i++)
			{
				
				if (probability[i] > maxValue && visit[i] == 0)
				{
					maxValue = probability[i];
					pos = i;
				}
			}
			//update the position
			updatePosition(pos);
			localPheromoneUpdate(currentpositon, pos);
		}
		//check for flag if any of the vertex is not visited then keep thr flag off
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
	updatePosition(position);
	localPheromoneUpdate(currentpositon,position);
}

void Ant::globalPheromoneUpdate()
{
	int size = path.size();
	int from = path[0];
	double distancetravlled = displayDistanceTravelled();
	double tou = (1 / distanceTravelled);
	double row = 0.05;

	for (int i = 1; i<5; i++)
	{
	    int to = path[i];
		double pheromone = Gph->getPheomone(from, to);
		double temppheromone = ((1 - row)*pheromone) + (0.05*tou);
		Gph->changePheromone(from, to, temppheromone);
		from = to;
	}
}

//this method resets all the visited verices of ant
void Ant::resetVisit()
{
	for (auto it : visit)
	{
		it = 0;
	}
	path.clear();
}

//destructor
Ant::~Ant()
{
}