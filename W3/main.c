#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "tool.h"
#include <string.h>

int main(int argc, const char* argv[])
{
	FILE* fo = fopen("C:/Users/User/Documents/Dev-c++/struct_square/test.json", "w+");
	float area = 0;
	/*	Point A = {0,0};
		Point B = {2,0};
		Point C = {0,0};
		Point D = {3,8};
		Point arrayOfPoint[2] = {C, D};

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
	*/
	Array* theArray = createArray(3);

	Point A = { 0,0 };
	Point B = { 0,1 };

	Point C = { 0,0 };
	Point D = { 0,2 };

	Point E = { 0,0 };
	Point F = { 0,3 };

	Square AB = { &A, &B };
	Square CD = { &C, &D };
	Square EF = { &E, &F };

	addElement(theArray, &AB);
	addElement(theArray, &CD);
	printArray(theArray);

	addElementByIndex(theArray, &EF, 0);
	addElementByIndex(theArray, &EF, 1);
	addElementByIndex(theArray, &EF, 2);
	printf("\n\n\n");
	printArray(theArray);

	writeArrayToJSON(fo, theArray);
	//	printf("area = %.0f\n", areaOfsquare(theArray->squares[1]));


	//	destroySquare(a);
	//	destroySquare(b);
	//	destroySquare(c);
	freeArray(theArray);

	fflush(fo);
	fclose(fo);

	return 0;
}