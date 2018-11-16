#include "Colony.h"
#include<set>


Colony::Colony()
{

}

void Colony::displayGraph(Graph &g)
{
	Gph = &g;
	//iterating the vector to display the graph
	for (auto it : Gph->returnGraph())
	{

		for (auto x : it)
		{
			cout << "from node " << x.from;
			cout << " to" << x.to;
			cout << "the distance is " << x.distance;
			cout << "pheromone is" << x.pheromone;
			cout << endl;
		}
	}
}

double Colony::greedyPath(Graph &g,double initial)
{
	//temporary vector to store a graph
	vector<vector<edge>> temp = g.returnGraph();

	//varibale which store the total path length
	double totalPathlength = 0;

	//forward path
	//set to store the nodes which are still to be visited
	set<double> toBeVisited;
	
	//initialising the start node as 0
	double start = initial;
	
	//storing the rest of nodes into the set
	for (auto it : temp.at(start))
	{
		toBeVisited.insert(it.to);
	}

	//varaible to store the path length during forward traversal
	double forwarddistance = 0;
	//from and to carries the from node and to node
	double from = start;
	double to = -1;
	
	//run the loop till you reach all the edges
	while(!toBeVisited.empty())
	{ //from the starting node find the minimum length to the next node 
	  
		double min = 1000;
	 
		//cout << "from" << from;
	  for (auto it : temp.at(from))
	  {
		 //condition to check wether the node which we are trying to reach is already visited or not\


		  const bool is_in = toBeVisited.find(it.to) != toBeVisited.end();
		  if ((it.distance < min)&&(is_in==1))
		  {
			  min = it.distance;
			  to = it.to;
			  from = to;
		  }
	  }
	  //erase the node from the set tobevisted
	  toBeVisited.erase(to);
	  
	  //cout << "to" << to;
	  //cout << "min is" << min << endl;
	  forwarddistance += min;
	
	}	
	//forward path is done
	
	//set of variables for storing during the backword tour
	double backwardfrom = to;
	double backwardDistance = 0;
	double backwardTo = -1;
	//initialising a set and having all the other nodes in it
	set<double> returnFVisited;
	for (auto it : temp.at(backwardfrom))
	{
		returnFVisited.insert(it.to);
	}

	//cout << "end of forward tour" << endl;
	//run the loop till it reaches the start point
	while (backwardTo != start)
	{
		//finding the node with minimum distance
		double backmin = 1000;
		//cout << "from" << backwardfrom;
		
		for (auto it : temp.at(backwardfrom))
		{
			//check wether the node is already covered
			const bool is_in = returnFVisited.find(it.to) != returnFVisited.end();
			if ((it.distance < backmin) && (is_in == 1))
			{
				backmin = it.distance;
				backwardTo = it.to;
				backwardfrom = backwardTo;
			}
		}
		returnFVisited.erase(backwardTo);

		//cout << "to" << backwardTo;
		//cout << "min is" << backmin << endl;
		backwardDistance += backmin;

	}
	totalPathlength = forwarddistance + backwardDistance;
	//cout << "total path length is" << totalPathlength << endl;
	return totalPathlength;
}

//method to initialise the pheromone
void Colony::initialisePheromone(Graph &g)
{
	Gph = &g;
	//intialising the number of ants
	int antcount = 2;
	//traversing through the graph to initialise the pheromone
	for (auto it : Gph->returnGraph())
	{
		
		for (auto x : it)
		{
			double tour = greedyPath(g, x.from);
			double init_pheromone = (antcount/tour);
			Gph->changePheromone(x.from, x.to, init_pheromone);

		}
	}

}
Colony::~Colony()
{
}
