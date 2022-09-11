#define _CRT_SECURE_NO_WARNINGS
#include "tool.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>

Array* createArray(int aNumber)
{
	Array* theResult = NULL;
	if (aNumber > 0)
	{
		theResult = (Array*)malloc(sizeof(Array));

		if (NULL != theResult)
		{
			theResult->squares = (Square**)malloc(sizeof(Square*) * aNumber);

			if (NULL != theResult->squares)
			{
				theResult->number = aNumber;
				theResult->count = 0;
			}
			else
			{
				free(theResult);
				theResult = NULL;
			}
		}
	}
	memset(theResult->squares, 0, sizeof(Square*) * aNumber);
	return theResult;
}

int addElement(Array* anArray, Square* aSquare)
{
	int theResult = -1;

	if (NULL != anArray && NULL != aSquare && anArray->count < anArray->number)
	{
		anArray->squares[anArray->count] = createSquare(aSquare->A, aSquare->B);
		theResult = anArray->count;
		anArray->count++;
	}
	return theResult;
}

int addElementByIndex(Array* anArray, Square* aSquare, int index)
{
	int theResult = -1;

	if (NULL != anArray && NULL != aSquare && index >= 0 && index < anArray->number)
	{
		if (NULL == anArray->squares[index])
		{
			anArray->squares[index] = createSquare(aSquare->A, aSquare->B);
			anArray->count++;
		}
		else
		{
			replaseSquareByIndex(anArray, aSquare->A, aSquare->B, index);
		}
		theResult = index;
	}
	return theResult;
}



void replaseSquareByIndex(Array* anArray, Point* A, Point* B, int index)
{
	if (NULL != A && NULL != B)
	{
		destroySquare(anArray->squares[index]);
		anArray->squares[index] = createSquare(A, B);
	}
}



void writeArrayToJSON(FILE* fo, Array* anArray)
{
	int i = 0;
	if (NULL == anArray || NULL == fo)
	{
		return;
	}

	fprintf(fo, "{\n\"number\" : %d,\n\"count\" : %d,\n", anArray->number, anArray->count);
	fprintf(fo, "\"Squares\" : \n\t[\n");

	for (i; i < anArray->count; i++)
	{
		writeSquareToJSON(fo, anArray->squares[i]);
		if (i < anArray->count - 1)
		{
			fprintf(fo, ",");
		}
		fprintf(fo, "\n");
	}
	fprintf(fo, "\t]\n}");
}

void writeSquareToJSON(FILE* fo, Square* aSquare)
{
	if (NULL == aSquare || NULL == fo)
	{
		return;
	}

	fprintf(fo, "\t{\n\t\"A\" : ");
	writePointToJSON(fo, aSquare->A);
	fprintf(fo, ", \n\t\"B\" : ");
	writePointToJSON(fo, aSquare->B);
	fprintf(fo, "\n\t}");
}

void writePointToJSON(FILE* fo, Point* aPoint)
{
	if (NULL == aPoint || NULL == fo)
	{
		return;
	}
	fprintf(fo, "{\"x\" : %d, \"y\" : %d}", aPoint->x, aPoint->y);
}

void printArray(Array* anArray)
{
	int i = 0;
	if (NULL == anArray)
	{
		return;
	}

	printf("number(%d), squares: \n", anArray->number);

	for (i = 0; i < anArray->count; i++)
	{
		printSquare(anArray->squares[i], i);
	}
}

Square* createSquare(Point* A, Point* B)
{
	Square* theResult;

	if (NULL != A && NULL != B)
	{
		theResult = (Square*)malloc(sizeof(Square));
		if (NULL != theResult)
		{
			theResult->A = createPoint(A);
			theResult->B = createPoint(B);
		}
	}
	return theResult;
}

Square* createSquareWithArrayOfPoint(Point* arrayOfPoint)
{
	Square* theResult = (Square*)malloc(sizeof(Square));
	if (theResult != NULL)
	{
		theResult->A = createPoint(&arrayOfPoint[0]);
		theResult->B = createPoint(&arrayOfPoint[1]);
	}
	return theResult;
}

Square* createSquareWithCoordinate(int xA, int yA, int xB, int yB)
{
	Square* theResult = (Square*)malloc(sizeof(Square));

	if (theResult != NULL)
	{
		theResult->A = createPointWithCoordinate(xA, yA);
		theResult->B = createPointWithCoordinate(xB, yB);
	}

	return theResult;
}

Point* createPointWithCoordinate(int x, int y)
{
	Point* theResult = (Point*)malloc(sizeof(Point));
	if (theResult != NULL)
	{
		theResult->x = x;
		theResult->y = y;
	}
	return theResult;
}

Point* createPoint(Point* aPoint)
{
	Point* theResult = (Point*)malloc(sizeof(Point));
	if (NULL != theResult)
	{
		theResult->x = aPoint->x;
		theResult->y = aPoint->y;
	}
	return theResult;
}

void printSquare(Square* aSquare, int i)
{
	if (NULL != aSquare)
	{
		printf("[Square_%d] A(%d,%d) B(%d,%d)\n", i, aSquare->A->x, aSquare->A->y, aSquare->B->x, aSquare->B->y);
		i++;
	}
}


float areaOfsquare(Square* aSquare)
{
	float result;
	if (aSquare != NULL)
	{
		float dx = (aSquare->B->x - aSquare->A->x);
		float dy = (aSquare->B->y - aSquare->A->y);
		result = sqrt(dx * dx + dy * dy) * 2;
		result *= result;
	}
	return result;
}

void destroySquare(Square* aSquare)
{
	if (aSquare != NULL)
	{
		free(aSquare->A);
		free(aSquare->B);
		free(aSquare);
	}
}

void freeArray(Array* anArray)
{
	int i = 0;
	if (NULL != anArray)
	{
		for (i; i < anArray->count; i++)
		{
			destroySquare(anArray->squares[i]);
		}

		free(anArray->squares);
		free(anArray);
	}
}