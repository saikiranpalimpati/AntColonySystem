#include "Graph.h"



Graph::Graph(int n)
{
	edgeList.resize(n);
}

Graph::Graph(const Graph & g)
{
	vector<vector<edge>> v = g.edgeList;
}



void Graph::addEdge(int from, int to, int distance)
{
	
	if (isEdge(from, to))
	{
		cout << "edge "<<from<<" to"<<to<<"  already exists" << endl;	
	}
	else 
	{
	   edgeList.at(from).push_back(edge(from, to, distance));
	}

}


void Graph::displayEdgelist()
{
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

	for (auto it : edgeList)
	{
		for (auto x : it)
		{
			if ((from == x.from) && (to == x.to))
			{
				flag = 1;
				return flag;

			}
		}
	}
	return flag;
}

void Graph::removeEdge(int from, int to)
{
	int i = 0;
	if (isEdge(from, to))
	{		
		for (auto it : edgeList)
		{
			for (auto x : it)
			{
				if ((from == x.from) && (to == x.to))
				{
					int position = i;
					edgeList[from].erase(edgeList[from].begin() + position);
				}
				i++;
			}
			i = 0;
		}
	}
	else
	{
		cout << "the edge which is requested to be removed does not exist" << endl;
		
	}
}

int Graph::getWeight(int from, int to)
{
	int weight = 0;
	
	for (auto it : edgeList)
	{
		for (auto x : it)
		{
		  weight = x.distance;
		
		}

	}
	return weight;

}


Graph::~Graph()
{
}
