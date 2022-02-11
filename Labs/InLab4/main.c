#include <stdio.h>

#include "Triangle.h"

int main() {

	Triangle triangle1 = InitTriangle();
	Triangle triangle2 = InitTriangle();

	double userBase;
	double userHeight;
	
	scanf("%lf",&userBase);
	scanf("%lf",&userHeight);

	// TODO: Read and set base and height for triangle1 (use SetBase() and SetHeight())
    triangle1 = SetBase ( triangle1, userBase );
    triangle1 = SetHeight( triangle1, userHeight);
	// TODO: Read and set base and height for triangle2 (use SetBase() and SetHeight())
	scanf("%lf",&userBase);
	scanf("%lf",&userHeight);
    triangle2 = SetBase( triangle2, userBase );
    triangle2 = SetHeight(triangle2, userHeight );

	// TODO: Determine larger triangle (use GetArea())

	printf("Triangle with larger area:\n");
	// TODO: Output larger triangle's info (use PrintInfo())
	   if ( GetArea(triangle1) >= GetArea(triangle2) ){
        PrintInfo( triangle1 );
    }
    else PrintInfo( triangle2 );
	return 0;
}