#ifndef tool_h
#define tool_h
#include <stdio.h>

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


Square* createSquare(Point* A, Point* B);
Square* createSquareWithCoordinate(int xA, int yA, int xB, int yB);
Point* createPointWithCoordinate(int x, int y);
Point* createPoint(Point* aPoint);
Square* createSquareWithArrayOfPoint(Point* arrayOfPoint);

void destroySquare(Square* aSquare);
void printSquare(Square* aSquare);
float areaOfsquare(Square* aSquare);


#endif