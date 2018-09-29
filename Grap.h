#include "Graph.h"



Graph::Graph(int n)
{
	edgeList.resize(n);
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
		//cout << "I am skipping an index";
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


Graph::~Graph()
{
}
