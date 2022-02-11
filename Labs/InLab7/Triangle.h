#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include <iostream>
using namespace std;

class Triangle
{
public:
	Triangle();
	Triangle(int b, int h);

	// Setters
	void setBase(int b);
	void setHeight(int h);

	// Getters
	int getBase() const;
	int getHeight() const;
	double getArea() const;

	void calculateArea();

	// Overloaded << operator declaration
	friend std::ostream &operator<<(std::ostream &out, const Triangle t);

	// Overloaded >> operator declaration
	friend std::istream &operator>>(std::istream &in, Triangle &t);

private:
	int base;
	int height;
	double area;
};

#endif