#ifndef TRIANGLE_H_
#define TRIANGLE_H_

typedef struct Triangle_struct {
	double base;
	double height;
} Triangle;

Triangle InitTriangle();
Triangle SetBase(Triangle triangle, double userBase);
Triangle SetHeight(Triangle triangle, double userHeight);
double GetArea(Triangle triangle);
void PrintInfo(Triangle triangle);

#endif