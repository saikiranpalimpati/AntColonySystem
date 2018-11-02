//#include"Graph.h"
#include"colony.h"
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ifstream infile;
	infile.open("distanceList.txt");

	double from, to, distance;
	Graph * g=new Graph(100);
	
	Colony c;
	while (infile >> from >> to >> distance)
	{
		g->addEdge(from, to, distance);
	}
	
	//c.displayGraph(* g);
	
	c.greedyPath(*g,1);
	//g->displayEdgelist();

	//g->removeEdge(0, 2);
	
	/*
	//checking wether the defined edge exists or not
	g.isEdge(6, 4);

	//displaying the edgelist
	g.displayEdgelist();

	g.changePheromone(0, 1, 5);

	cout << endl;

	g.displayEdgelist();

	//removing few edges from edgelist
	//g.removeEdge(0, 2);
	//g.removeEdge(0, 4);

	//displaying the edgelist after removing few edges
	//g.displayEdgelist();

	//get weight of on of the edge
	cout << g.getWeight(0, 2) << endl;
	*/


	system("pause");
}
