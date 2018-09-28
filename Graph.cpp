#include "Graph.h"



Graph::Graph(int numnodes)
{
	vector<vector<edge>> edgeList(numnodes);
}

void Graph::addEdge(int from, int to, int distance)
{

	edgeList[from].push_back(edge(to, distance));
	
}


void Graph::displayEdgelist()
{
	for (auto it : edgeList)
	{
		for (auto x : it)
		{
			cout << "node number" << x.to;
			cout << "distance" << x.distance;
			cout << "     ";
		}
		cout << endl;
	}
}


Graph::~Graph()
{
}
