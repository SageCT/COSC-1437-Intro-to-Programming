#include "Triangle.h"
#include <iostream>
using namespace std;

Triangle::Triangle()
{
	base = 0;
	height = 0;
}

Triangle::Triangle(int b, int h) : base(b), height(h) {}

void Triangle::setBase(int b)
{
	base = b;
}

void Triangle::setHeight(int h)
{
	height = h;
}

void Triangle::calculateArea()
{
	// calculate Area correctly depending on shape type
	area = ((0.5) * base) * height;
	// area = base * height/2.0;
}

int Triangle::getBase() const
{
	return base;
}

int Triangle::getHeight() const
{
	return height;
}

double Triangle::getArea() const
{
	return area;
}

// Overloaded << operator declaration
std::ostream &operator<<(std::ostream &out, const Triangle t)
{
	out << "Triangle Object:\n"
		<< "Base: " << t.getBase() << "\n"
		<< "Height: " << t.getHeight() << "\n"
		<< "Area is: " << t.getArea();
	return out;
}
// Overloaded >> operator declaration
std::istream &operator>>(std::istream &in, Triangle &t)
{
	in >> t.base >> t.height;
	t.calculateArea();
	return in;
}