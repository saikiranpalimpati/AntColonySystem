#include "Graph.h"


Graph::Graph(int n)
{
	edgeList.resize(n);
	//initalise the vector with size n 
}


Graph::Graph(const Graph & g)
{
	vector<vector<edge>> v = g.edgeList;
	//copy the vector into another
}


void Graph::addEdge(int from, int to, int distance)
{
	//while adding check wether the edge already exists
	if (isEdge(from, to))
	{
		cout << "edge " << from << " to" << to << "  already exists" << endl;
	}

	//if the edge does not exist then add the edge 
	else
	{
		edgeList.at(from).push_back(edge(from, to, distance));
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
			cout << endl;
		}
	}
}



bool Graph::isEdge(int from, int to)
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



void Graph::removeEdge(int from, int to)
{
	int i = 0;
	//variable used for incrementation during iteration
	
	int position = -1;
	//variable to catch the position of the edge in the list
	
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

	//if the position value changed then at that partuicular position erase the edge
	if (position >= 0)
	{
		edgeList[from].erase(edgeList[from].begin() + position);

	}

	//if the position is not changed then it means it does not exist
	else
	{
		cout << "edge doesnot exist so it cannot be removed" << endl;
	}

}

int Graph::getWeight(int from, int to)
{
	int weight = 0;
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


Graph::~Graph()
{
}
