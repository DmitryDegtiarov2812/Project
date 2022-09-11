#ifndef tool_h
#define tool_h
#include <stdio.h>
#include <string.h>

typedef struct tagPoint
	{
	int x;
	int y;
	}Point;

typedef struct tagSquare
	{
	Point* A;
	Point* B;
	}Square;
	
typedef struct tagArray
	{
		int number;
		int count;
		
		Square** squares;
	}Array;

Square *createSquare(Point *A, Point *B);
Square *createSquareWithCoordinate(int xA, int yA, int xB, int yB);
Point *createPointWithCoordinate(int x, int y);
Point *createPoint(Point *aPoint);
Square *createSquareWithArrayOfPoint(Point *arrayOfPoint);
Array *createArray(int aNumber);

int addElement(Array *anSquare, Square *aSquare);
int addElementByIndex(Array *anSquare, Square *aSquare, int index);
float areaOfsquare(Square *aSquare);

void destroySquare(Square *aSquare);
void printSquare(Square *aSquare, int i);
void printArray(Array *anArray);
void freeArray(Array *anArray);
void writeArrayToJSON(FILE *fo, Array *anArray);
void writeSquareToJSON(FILE *fo, Square *aSquare);
void writePointToJSON(FILE *fo, Point *aPoint);
void replaseSquareByIndex(Array *anArray, Point *A, Point *B, int index);

#endif