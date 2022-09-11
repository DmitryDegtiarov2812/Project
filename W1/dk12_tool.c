#include <stdio.h>
#include <stdlib.h>

int entersizematrixrow() {
    int x;
    printf("Enter the number of rows for matrix: ");
    scanf_s("%d", &x);
    return x;
}

int entersizematrixcol() {
    int y;
    printf("Enter the number of columns for matrix: ");
    scanf_s("%d", &y);
    printf("\n");
    return y;
}

void entersizematrix1(int* m1, int x, int y) {
    printf("Enter the elements of the first matrix\n\n");
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            printf("[%d][%d] = ", i + 1, j + 1);
            scanf_s("%d", (m1 + i * y + j));
        }
    }
    printf("\n");
    printf("---------------\n");
    printf("\n");
}

void entersizematrix2(int* m2, int x, int y) {

    printf("Enter the elements of the second matrix\n\n");
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            printf("[%d][%d] = ", i + 1, j + 1);
            scanf_s("%d", (m2 + i * y + j));
        }
    }

    printf("\n");
    printf("---------------\n");
    printf("\n");
}

void matrixsum(int* m1, int* m2, int x, int y) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            *(m1 + i * y + j) = *(m1 + i * y + j) + *(m2 + i * y + j);
        }
    }
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            printf("%d ", *(m1 + i * y + j));
        }
        printf("\n");
    }
}