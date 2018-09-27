#pragma once
#include<vector>
#include<iostream>
using namespace std;
struct node
{
	int nodeno;
	int distance;
	//node * next;
	node(int d, int n)
	{
		distance = d;
		nodeno = n;
	}
};
class Graph
{
private:
	int nonumber, distance;
	vector<vector<node>> nodes;
public:
	Graph(int n);
	void addEdge(vector<vector<node>> nodes, int nonumber, int distance);
	void displayEdgelist(vector<vector<node>> nodes);
	~Graph();
};
