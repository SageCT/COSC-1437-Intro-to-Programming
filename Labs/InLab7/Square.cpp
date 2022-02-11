#include "Square.h"
#include <iostream>
using namespace std;

Square::Square()
{
	base = 0;
	height = 0;
}

Square::Square(int b, int h) : base(b), height(h) {}

void Square::setBase(int b)
{
	base = b;
}

void Square::setHeight(int h)
{
	height = h;
}

void Square::calculateArea()
{
	// calculate Area correctly depending on shape type
	area = base * height;
}

int Square::getBase() const
{
	return base;
}

int Square::getHeight() const
{
	return height;
}

double Square::getArea() const
{
	return area;
}
// Overloaded << operator
std::ostream &operator<<(ostream &out, const Square s)
{
	out << "Square Object:\n"
		<< "Base: " << s.getBase() << "\n"
		<< "Height: " << s.getHeight() << "\n"
		<< "Area is: " << s.getArea();
	return out;
}
// Overloaded >> operator
std::istream &operator>>(istream &in, Square &s)
{
	in >> s.base >> s.height;
	s.calculateArea();
	return in;
}
