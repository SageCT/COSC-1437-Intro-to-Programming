// include the proper header file
#include "Cylinder.h"

Cylinder::Cylinder()
{
}

float Cylinder::getHeight()
{
	return height;
}

void Cylinder::setHeight(float _h)
{
	height = _h;
}

// Implement the other member functions

// constructor with four parameters
Cylinder::Cylinder(float x, float y, float radius, float height)
{
	setCenter(x, y);
	this->radius = radius;
	this->height = height;
}
// override compArea()
void Cylinder::compArea()
{
	Shape::setArea((float)2 * 3.14 * height * radius + (float)2 * 3.14 * radius * radius);
}

// override printArea()
void Cylinder::printArea()
{
	std::cout << "The area of the cylinder is " << std::fixed << setprecision(2) << getArea() << endl;
}