#include"Graph.h"
#include<iostream>
using namespace std;
int main()
{
	//initialising the number of vertices to be 10
	Graph g(10);

	//adding a few edges
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
	g.addEdge(0, 1, 15);
	g.addEdge(0, 2, 10);
	
	
	//checking wether the defined edge exists or not
	g.isEdge(6, 4);

	//displaying the edgelist
	g.displayEdgelist();

	//removing few edges from edgelist
	g.removeEdge(7, 2);
	g.removeEdge(6, 4);

	//displaying the edgelist after removing few edges
	g.displayEdgelist();

	//get weight of on of the edge
	cout << g.getWeight(0, 7) << endl;

	system("pause");
}
