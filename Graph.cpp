#include "Graph.h"

Graph::Graph(int n)
{
	edgeList.resize(n);
	//initalise the vector with size n 
}

//copy constructor
Graph::Graph(const Graph & g)
{
	vector<vector<edge>> v = g.edgeList;
}


void Graph::addEdge(int from, int to, double distance)
{
	//while adding check wether the edge already exists
	if (isEdge(from, to) || isEdge(to, from))
	{
		cout << "  already exists" << endl;
	}
	//if the edge does not exist then add the edge 
	else
	{
		if (from < to)
		{
			edgeList.at(from).push_back(edge(from, to, distance));
		}
		else if (to < from)
		{
			edgeList.at(to).push_back(edge(to, from, distance));
		}
	}
}


void Graph::displayEdgelist()
{
	//traverse trough all the elements in the vector and
	//display them 
	for (auto it : edgeList)
	{

		for (auto x : it)
		{
			cout << "from node " << x.from;
			cout << " to " << x.to;
			cout << " the distance is " << x.distance;
			cout << " and the pheromone on that edge is" << x.pheromone;
			cout << endl;
		}
	}
}



bool Graph::isEdge(int from, int to)
{
	bool flag = 0;
	//swap if from gretaer than to
	if (from > to)
	{
		int temp = 0;
		temp = from;
		from = to;
		to = temp;
	}
	//traverse trough the particfular form vector and check 
	//wether the edge exists
	for (auto x : edgeList.at(from))
	{
		if ((from == x.from) && (to == x.to))
		{
			flag = 1;
			return flag;
		}
	}
	//return a boolean variable 
	return flag;
}



void Graph::removeEdge(int from, int to)
{
	int i = 0;
	//int j = 0;
	//variable used for incrementation during iteration

	int positioni = -1;
	//int positionj = -1;
	//variable to catch the position of the edge in the list
	
	//swap if from gretaer than to
	if (from > to)
	{
		int temp = 0;
		temp = from;
		from = to;
		to = temp;
	}

	for (auto x : edgeList.at(from))
	{
		//traverse and check for the edge in the edgelist
		if ((from == x.from) && (to == x.to))
		{
			positioni = i;

		}
		i++;
	}
	i = 0;

	//if the position value changed then at that partuicular
	//position erase the edge
	if (positioni >= 0)
	{
		edgeList[from].erase(edgeList[from].begin() + positioni);

	}
	//if the position is not changed then it means it does
	//not exist
	else
	{
		cout << "edge doesnot exist so it cannot be removed" << endl;
	}
}

double Graph::getWeight(int from, int to)
{
	double weight = 0;
	//having a varible to return edge weight
	//swap if from greter than to
	if (from > to)
	{
		int temp = 0;
		temp = from;
		from = to;
		to = temp;
	}
	for (auto x : edgeList.at(from))
	{
		if (x.to == to)
		{
			weight = x.distance;
		}
	}
	return weight;
}


double Graph::getPheomone(int from, int to)
{

	double prmne = 0;
	//having a varible to return edge pheromone
	if (from > to)
	{
		int temp = 0;
		temp = from;
		from = to;
		to = temp;
	}
	for (auto x : edgeList.at(from))
	{
		if (x.to == to)
		{
			prmne = x.pheromone;
		}
	}
	return prmne;
}

void Graph::changePheromone(int from, int to, double pheromone)
{
	int position = 0;
	int i = 0;
	//if from is greater than to than swap 
	if (from > to)
	{
		int temp = 0;
		temp = from;
		from = to;
		to = temp;
	}

	for (auto x : edgeList.at(from))
	{
		//traverse and check for the edge in the edgelist
		if ((from == x.from) && (to == x.to))
		{
			position = i;
		}
		i++;
	}
	i = 0;
	edgeList[from][position].pheromone = pheromone;
}

//method to return the edgelist
vector<vector<edge>> Graph::returnGraph()
{

	return edgeList;
}

//method to return the number of vertices in the graph
int Graph::returnNumberOfVertices()
{
	int i = 0;
	for (auto it : edgeList.at(0))
	{
		i++;
	}
	return i;
}

//destructor
Graph::~Graph()
{
}
