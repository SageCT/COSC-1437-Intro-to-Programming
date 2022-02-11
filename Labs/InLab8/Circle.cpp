// include the proper header file
#include "Circle.h"

Circle::Circle()
{
}

float Circle::getRadius()
{
	return radius;
}

void Circle::setRadius(float _r)
{
	radius = _r;
}

// provide the implementation of the other member functions of Circle below

// Constructor with three parameters
Circle::Circle(float x, float y, float radius)
{
	Shape();
	Shape::setCenter(x, y);
	this->radius = radius;
}
// compArea()
void Circle::compArea()
{
	Shape::setArea(3.14 * radius * radius);
}
// printArea()
void Circle::printArea()
{
	std::cout << "The area of the circle is " << std::fixed << std::setprecision(2) << getArea() << endl;
}