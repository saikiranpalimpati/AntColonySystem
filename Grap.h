#include<vector>
#include<iostream>
using namespace std;
struct edge
{
	int from;
	int to;
	int distance;

	edge(int f,int t, int d)
	{
		from = f;
		to = t;
		distance = d;
	}
};
class Graph
{
private:
	vector<vector<edge>> edgeList;

public:
	Graph(int n);
	Graph(const Graph &g);
	void addEdge(int from, int to, int distance);
	void displayEdgelist();
	bool isEdge(int from, int to);
	void removeEdge(int from,int to);
	~Graph();
};
