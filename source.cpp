#include"Graph.h"
#include<iostream>
using namespace std;
int main()
{
	Graph g(10);
	g.addEdge(0, 1, 15);
	g.addEdge(0, 2, 10);
	g.addEdge(0, 3, 5);
	g.addEdge(0, 4, 74);
	g.addEdge(0, 5, 44);
	g.addEdge(0, 6, 12);
	g.addEdge(0, 7, 14);
	g.addEdge(0, 8, 45);
	g.addEdge(2, 8, 78);
	g.addEdge(5, 4, 78);
	g.addEdge(6, 4, 7);
	g.isEdge(6, 4);
	g.displayEdgelist();
	g.removeEdge(0, 3);
	/* g.addEdge();
	g.addEdge();
	g.addEdge();*/
	g.displayEdgelist();
	system("pause");
}
