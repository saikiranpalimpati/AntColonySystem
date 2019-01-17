
#include"Ant.h"
#include"Colony.h"
#include<fstream>

int main()
{
	ifstream infile;
	infile.open("distanceList.txt");

	int from, to;
	double distance;
	Graph * g=new Graph(100);
	
	
	while (infile >> from >> to >> distance)
	{
		g->addEdge(from, to, distance);
	}
	Colony c(*g);
	//g->displayEdgelist();
	c.initialiseAnts(*g);
	//c.displayAnts();
	//cout << g->returnNumberOfVertices() << endl;;
	c.AnttourUsingGreddyALgorithm();
	system("pause");
}
