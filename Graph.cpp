#include "Graph.h"

vector<vector<edge>> Graph::returnGraph()
{

	return edgeList;
}

Graph::Graph(double n)
{
	edgeList.resize(n);
	//initalise the vector with size n 
}


Graph::Graph(const Graph & g)
{
	vector<vector<edge>> v = g.edgeList;
	//copy the vector doubleo another
}


void Graph::addEdge(double from, double to, double distance)
{
	//while adding check wether the edge already exists
	if (isEdge(from, to)||isEdge(to,from))
	{
		cout << "  already exists" << endl;
	}

	//if the edge does not exist then add the edge 
	else
	{
		//double pheromone = 0;
		edgeList.at(from).push_back(edge(from, to, distance));
		edgeList.at(to).push_back(edge(to, from, distance));

	}

}


void Graph::displayEdgelist()
{
	//traverse trough all the elements in the vector and display them 
	for (auto it : edgeList)
	{

		for (auto x : it)
		{
			cout << "from node " << x.from;
			cout << " to" << x.to;
			cout << "the distance is " << x.distance;
			cout << "pheromone is" << x.pheromone;
			cout << endl;
		}
	}
}



bool Graph::isEdge(double from, double to)
{
	bool flag = 0;

	//traverse trough the particfular form vector and check wether the edge exists
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



void Graph::removeEdge(double from, double to)
{
	double i = 0;
	double j = 0;
	//variable used for incrementation during iteration

	double positioni = -1;
	double positionj = -1;
	//variable to catch the position of the edge in the list

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

	//if the position value changed then at that partuicular position erase the edge
	if (positioni >= 0)
	{
		edgeList[from].erase(edgeList[from].begin() + positioni);

	}

	//if the position is not changed then it means it does not exist
	else
	{
		cout << "edge doesnot exist so it cannot be removed" << endl;
	}
	for (auto x : edgeList.at(to))
	{
		//traverse and check for the edge in the edgelist
		if ((from == x.to) && (to == x.from))
		{
			positionj = j;

		}
		j++;
	}
	j = 0;

	//if the position value changed then at that partuicular position erase the edge
	if (positionj >= 0)
	{
		edgeList[to].erase(edgeList[to].begin() + positionj);

	}

	//if the position is not changed then it means it does not exist
	else
	{
		cout << "edge doesnot exist so it cannot be removed" << endl;
	}

}

double Graph::getWeight(double from, double to)
{
	double weight = 0;
	//having a varible to return edge weight

	for (auto x : edgeList.at(from))
	{

		if (x.to == to)
		{

			weight = x.distance;
		}

	}

	return weight;
}


void Graph::changePheromone(double from, double to, double pheromone)
{
	int position = 0;
	int positionj = 0;
	int i = 0;
	int j = 0;
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

	for (auto x : edgeList.at(to))
	{
		//traverse and check for the edge in the edgelist
		if ((to == x.from) && (from == x.to))
		{
			positionj = j;
		}
		j++;
	}
	j = 0;
	edgeList[to][positionj].pheromone = pheromone;

}





double Graph::greedyTour()
{
	//int start=
	return 0.0;
}

Graph::~Graph()
{
}
