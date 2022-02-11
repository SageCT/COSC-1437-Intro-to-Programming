#pragma once

// include the proper header file
#include "Shape.h"

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle : public Shape
{
public:
	Circle();
	Circle(float, float, float);

	float getRadius();
	void setRadius(float);

	void compArea();
	void printArea();

protected:
	float radius;
};

#endif