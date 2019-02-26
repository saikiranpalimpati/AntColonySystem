#include"Ant.h"
#include"Colony.h"
#include<fstream>
//header files


int main()
{
	ifstream infile;
	//input file variable

	infile.open("distanceList.txt");
	//open input file

	int from, to;
	double distance;
	//variables

	Graph * g = new Graph(100);

	//reading the input file
	while (infile >> from >> to >> distance)
	{
		g->addEdge(from, to, distance);
	}

	//initialise colony
	Colony c(*g);
	
	c.implementingAcs();

	//g->displayEdgelist();
	system("pause");
}