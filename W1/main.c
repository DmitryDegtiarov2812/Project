#include <stdio.h>
#include <stdlib.h>
#include "dk12_tool.h"

int main()
{
    int x = entersizematrixrow();
    int y = entersizematrixcol();
    int* m1 = (int*)malloc(x * y * sizeof(int));
    int* m2 = (int*)malloc(x * y * sizeof(int));
    entersizematrix1(m1, x, y);
    entersizematrix2(m2, x, y);
    matrixsum(m1, m2, x, y);
    free(m1);
    free(m2);
 }