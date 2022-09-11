#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h"

int main()
{
    /*int A = enterA();
    int B = enterB();
    int C = enterC();*/
    int A = enterABC();
    int B = enterABC();
    int C = enterABC();
    float Q;
    if (B == 0) {
        printf("ERROR: 'B' Cannot be zero");
    }
    else if (C < 0) {
        printf("ERROR: Enter non-negative 'C'");
    }
    else if (B + C < 0) {
        printf("ERROR: Enter non-negative 'B + C'");
    }
    else {
        Q = A * sqrt(B + C) / B + sum(C, A);
        printf("Q = %.2f\n ", Q);
    }
    return 0;
}