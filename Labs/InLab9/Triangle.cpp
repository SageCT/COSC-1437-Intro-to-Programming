#include <iostream>
#include "Triangle.h"
using namespace std;

Triangle::Triangle(int s)
{
	this->side = s;
}

void Triangle::setSide(int s)
{
	this->side = s;
}

int Triangle::getSide()
{
	return this->side;
}

void Triangle::setCenter(float x, float y)
{
	setX(x);
	setY(y);
	cout << "Triangle moved to [" << this->getX() << ", " << this->getY() << endl;
}

void Triangle::draw()
{
	string oof;
	cout << "Drawing Triangle at [" << this->getX() << ", " << this->getY() << "]" << endl;
	for (int i = 0; i < side; i++)
	{
		for (int x = 0; x <= i; x++)
			cout << "*";
	}
	cout << endl;
}