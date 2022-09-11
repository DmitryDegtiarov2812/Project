#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "dk12_tool.h"
#include <conio.h>
#define MAX_VALUE 10

int main()
{
	int array[MAX_VALUE];
	int pos, i;
	char symbol[MAX_VALUE];

	memcpy(array, random(), sizeof(array));

	FILE* lab = fopen("lab2.txt", "w");

	for (pos = 0; pos < MAX_VALUE; pos++)
	{
		symbol[pos] = array[pos];
		printf("%c", symbol[pos]);
		fprintf(lab, "%c", symbol[pos]);
	}

	fclose(lab);

	CharList* theList = SLCreateList();

	loadFile("lab2.txt", theList);

	printf("\n=>\n");
	doPrintSLList(theList);

	printf("\n<=\n");
	doPrintSLList_Conversely(theList);

	printf("\n=>\n");
	doPrintSLList(theList);

	printf("\n<=\n");
	doPrintSLList_Conversely(theList);

	SLFreeList(theList);

	return 0;
}