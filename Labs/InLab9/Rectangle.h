#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"
using namespace std;

class Rectangle : public Shape
{
public:
	Rectangle(int base, int height);
	void setBase(int b);
	void setHeight(int h);
	void setCenter(float x, float y);
	int getBase();
	int getHeight();
	void setCenter(float x, float y);
	void draw();

private:
	int base, height;
};

#endif