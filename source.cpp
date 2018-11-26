#include"ant.h"
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

	c.initialisePheromone(*g);
	Ant a;
	a.initialiseAnts(*g);
	//g->displayEdgelist();
	a.antTour(*g);
	//g->displayEdgelist();
	cout << "next one" << endl;
	a.displayPath();
	system("pause");
}
