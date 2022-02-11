#include <iostream>
#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle(int b, int h)
{
	base = b;
	height = h;
}

void Rectangle::setBase(int b)
{
	base = b;
}

void Rectangle::setHeight(int h)
{
	height = h;
}

int Rectangle::getBase()
{
	return base;
}

int Rectangle::getHeight()
{
	return height;
}

void Rectangle::setCenter(float x, float y)
{
	setX(x);
	setY(y);
	cout << "Rectangle moved to [" << getX() << ", " << getY() << "]" << endl;
}

void Rectangle::draw()
{
	cout << "Drawing Rectangle at ]" << getX() << ", " << getY() << "]" << endl;
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < base; x++)
			cout << "*";
		cout << endl;
	}
}