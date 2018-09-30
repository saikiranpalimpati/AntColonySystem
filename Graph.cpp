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
	edgeList.at(from).push_back(edge(from, to, distance));
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
	bool flag = false;

	for (auto it : edgeList)
	{
	  for (auto x : it)
		{
		  if ((from == x.from) && (to == x.to))
			{
				flag = true;
				return flag;
			}
		}
	}
	return flag;
}

void Graph::removeEdge(int from, int to)
{
	int i = 0;
	for (auto it : edgeList)
	{
		for (auto x : it)
		{
			if ((from == x.from) && (to == x.to))
			{
				int position = i;
				edgeList[from].erase(edgeList[from].begin()+position);
			}
			i++;
		}
		i = 0;
	}	
}

Graph::~Graph()
{
}
