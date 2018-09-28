#pragma once
#include<vector>
#include<iostream>
using namespace std;
struct edge
{
	int to;
	int distance;
	
	edge(int t, int d)
	{
		to = t;
		distance = d;
	}
};
class Graph
{
private:
	vector<vector<edge>> edgeList;

public:
	Graph(int numnodes);
	void addEdge(int from,int to,int distance);
	void displayEdgelist();
	bool isEdge(int from,int to);
	void removeEdge();
	~Graph();
};
