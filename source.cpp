#include "Graph.cpp"
#include<iostream>
using namespace std;
int main()
{
	Graph g(10);
	//vector<vector<edge>> v;
	g.addEdge(0, 1, 10);
	g.displayEdgelist();

	system("pause");
}
