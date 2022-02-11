#include <stdio.h>

#include "Triangle.h"

int main()
{

	Triangle triangle1 = InitTriangle();
	Triangle triangle2 = InitTriangle();

	double userBase;
	double userHeight;

	scanf("%lf", &userBase);
	scanf("%lf", &userHeight);

	// TODO: Read and set base and height for triangle1 (use SetBase() and SetHeight())
	SetBase(triangle1, userBase);
	SetHeight(triangle1, userHeight);

	// TODO: Read and set base and height for triangle2 (use SetBase() and SetHeight())
	scanf("%lf", &userBase);
	scanf("%lf", &userHeight);

	SetBase(triangle2, userBase);
	SetHeight(triangle2, userHeight);

	// TODO: Determine larger triangle (use GetArea())
	Triangle bigger = InitTriangle();

	if (GetArea(triangle1) >= GetArea(triangle2))
	{
		SetBase(bigger, triangle1.base);
	}
	else
	{
		SetBase(bigger, triangle2.base);
	}

	printf("Triangle with larger area:\n");
	// TODO: Output larger triangle's info (use PrintInfo())
	PrintInfo(triangle1);

	return 0;
}