#include <stdio.h>

#include "Triangle.h"

Triangle InitTriangle() {
	Triangle triangle;
	triangle.base = 0.0;
	triangle.height = 0.0;
	return triangle;
}

Triangle SetBase(Triangle triangle, double userBase) {
	triangle.base = userBase;
	return triangle;
}

Triangle SetHeight(Triangle triangle, double userHeight) {
	triangle.height = userHeight;
	return triangle;
}

double GetArea(Triangle triangle) {
	double area = 0.5 * triangle.base * triangle.height;
	return area;
}

void PrintInfo(Triangle triangle) {
	printf("Base: %.2lf\n", triangle.base);
	printf("Height: %.2lf\n", triangle.height);
	printf("Area: %.2lf\n", GetArea(triangle));
}