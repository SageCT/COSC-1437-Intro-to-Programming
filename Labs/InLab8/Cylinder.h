#pragma once

// include the proper header file
#include "Circle.h"

#ifndef CYLINDER_H
#define CYLINDER_H

// Declare the derived class Cylinder below
class Cylinder : public Circle
{
public:
	Cylinder();
	Cylinder(float x, float y, float radius, float height);
	float getHeight();
	void setHeight(float height);

	void compArea();
	void printArea();

private:
	float height;
};

#endif