#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h"

/*int enterA() {
    int A;
    printf("Enter A: ");
    scanf("%d", &A);
    return A;
}

int enterB() {
    int B;
    printf("Enter B: ");
    scanf("%d", &B);
    return B;
}

int enterC() {
    int C;
    printf("Enter C: ");
    scanf("%d", &C);
    return C;
}*/

int enterABC() {
    int X;
    printf("Enter A,B,C in turn: ");
    scanf("%d", &X);
    return X;
}

int factorial(int x) {
    int a = 1;

    if (x >= 0) {

        for (int i = 1; i <= x; i++) {
            a *= i;
        }
        return  a;
    }
    else return 0;

}

float sum(int C, int A) {
    float sum = 0;

    for (int D = 0; D <= C; D++) {
        sum += factorial(A + D);
    }
    return sum;
}