#include "Graph.cpp"
#include<iostream>
using namespace std;
int main()
{
	Graph g(10);
	vector<vector<node>> v;
	g.addEdge(v, 1, 10);
	g.displayEdgelist(v);
	
	system("pause");
}
