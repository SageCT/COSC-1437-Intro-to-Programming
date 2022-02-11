#include <iostream>
#include "Shape.h"
#include "Rectangle.h"
#include "Triangle.h"
using namespace std;

// Do not edit main.cpp

void move(Shape *fig, float x, float y);

int main()
{
	Shape *figure = new Shape();
	Rectangle *rectangle = new Rectangle(6, 5);
	Triangle *triangle = new Triangle(3);

	move(figure, 6, 2);
	cout << endl;
	move(rectangle, 4, 6);
	cout << endl;
	move(triangle, 2, 9);

	return 0;
}

void move(Shape *fig, float x, float y)
{
	fig->setCenter(x, y);
	fig->draw();
}