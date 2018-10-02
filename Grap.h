/*This program creates edgelist using two dimensional vectors */
//header files
#include<vector>
#include<iostream>
using namespace std;

/* This structure defines an edge and it contains from vertex, to vertex and distance between those
   two vertices
   A constructor is also defined to initialise each edge
*/
struct edge
{
	int from;
	int to;
	int distance;

	edge(int f, int t, int d)
	{
		from = f;
		to = t;
		distance = d;
	}
};

/* The graph class contains a two dimensional vector which contains the edgelist the outermost vectors 
   indices are taken as the from vector reference and inside each of this vector element there exists 
   a vector which is of type edge. There are a few methods which help in intialising and accesing the 
   data from and to edgelist.

*/
class Graph
{

private:
	vector<vector<edge>> edgeList;
	//vector initialisation

public:
	Graph(int n);
	//default constructor to intialise the size of the edgelist vector

	Graph(const Graph &g);
	//copy constructor to copy the vector 
	
	void addEdge(int from, int to, int distance);
	//addEdge method to in initialise an edge into edgeList vector 
	
	void displayEdgelist();
	//display all the edges in the edgeList vector
	
	bool isEdge(int from, int to);
	//checks wether the edge exists or not

	void removeEdge(int from, int to);
	//removes an edge

	int getWeight(int from, int to);
	//gives the distance between the given from and to vertices
	
	~Graph();
	//destructor
};
