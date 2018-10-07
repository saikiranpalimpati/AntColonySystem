#pragma once
#include<iostream>
#include<vector>
using namespace std;

struct vertex
{
	int x;
	int y;
	vertex(int xcor,int ycor)
	{
		x = xcor;
		y = ycor;
	}
};
class coOrdinate
{ 
private:
	vector<vertex> v;

   public:
	coOrdinate(int n);
	void addcoOrdinate(int i, int x,int y);
	void displayAllVerices();
	~coOrdinate();
};

