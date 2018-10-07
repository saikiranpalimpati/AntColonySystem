#include "coOrdinate.h"



coOrdinate::coOrdinate(int n)
{
	v.resize(n);
}

void coOrdinate::addcoOrdinate(int i, int x, int y)
{
	v.push_back(vertex(x, y));
	
}

void coOrdinate::displayAllVerices()
{
	for (auto it : v)
	{
		cout << "x " << it.x << "y " << it.y << endl;
	}
}


coOrdinate::~coOrdinate()
{
}
