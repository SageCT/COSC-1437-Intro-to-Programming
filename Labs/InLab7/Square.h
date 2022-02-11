#ifndef SQUARE_H_
#define SQUARE_H_

#include <iostream>
using namespace std;

class Square
{
public:
	Square();
	Square(int b, int h);

	// Setters
	void setBase(int b);
	void setHeight(int h);

	// Getters
	int getBase() const;
	int getHeight() const;
	double getArea() const;

	void calculateArea();

	// Overloaded << operator declaration
	friend std::ostream &operator<<(ostream &out, const Square s);
	// Overloaded >> operator declaration
	friend std::istream &operator>>(istream &in, Square &s);

private:
	int base;
	int height;
	double area;
};

#endif