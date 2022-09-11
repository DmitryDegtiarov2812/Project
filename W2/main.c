#include <stdio.h>
#include "tool.h"

int main(int argc, const char* argv[])
{
	float area = 0;
	Point A = { 0,0 };
	Point B = { 2,0 };
	Point C = { 0,0 };
	Point D = { 3,8 };
	Point arrayOfPoint[2] = { C, D };

	Square* a = createSquare(&A, &B);
	printSquare(a);
	area = areaOfsquare(a);
	printf("area = %.0f\n", area);

	Square* b = createSquareWithCoordinate(3, 7, 0, 5);
	printSquare(b);
	area = areaOfsquare(b);
	printf("area = %.0f\n", area);

	Square* c = createSquareWithArrayOfPoint(arrayOfPoint);
	printSquare(c);
	area = areaOfsquare(c);
	printf("area = %.0f\n", area);

	destroySquare(a);
	destroySquare(b);
	destroySquare(c);
	return 0;
}