#include "Graph.h"



Graph::Graph(int n)
{
	vector<vector<node>> nodes(n);
}

void Graph::addEdge(vector<vector<node>> nodes, int noumber, int distance)
{
	for (auto it : nodes)
	{
		for (auto x : it)
		{
			it.push_back(node(noumber, distance));
		}
	}

}


void Graph::displayEdgelist(vector<vector<node>> nodes)
{
	for (auto it : nodes)
	{
		for (auto x : it)
		{
			cout << "node number" << x.nodeno;
			cout << "distance" << x.distance;
		}
		cout << endl;
	}
}


Graph::~Graph()
{
}
