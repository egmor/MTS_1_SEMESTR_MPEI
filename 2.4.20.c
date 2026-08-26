//2.4.20

#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, count = 0;
    float X;
    printf("Please, input value of numbers: ");
    scanf("%d", &N);
    while (N < 1) {
        printf("\nInput error. Please, input value of numbers > 0\n");
        scanf("%d", &N);
    }

    float *A = (float*)malloc(N * sizeof(float));

    printf("Input %d numbers A:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%f", &A[i]);
    }

    printf("Please, enter value X: ");
    scanf("%f", &X);

    int i = 0;
    int fl, flag = 1;
    while ((fl > 0) && (i < N)) {
        if (A[i] < X) {fl = 0;}
        else {i++;}
    }
    if (fl == 0) {
        printf("There are values in the array less than %6.4f = %6.4f", X, A[i]);
    }
    else {printf("There are no values in the array less than %6.4f", X);}

    int i = N - 1;
    while ((flag > 0) && (i > 0)) {
        if (A[i] < X) {fl = 0;}
        else {i--;}
    }

    if (flag == 0) {printf("The last value in the array less than %6.4f = %6.4f", X, A[i]);}
    else {printf("There are no values in the array less than %6.4f", X);}
    


    free(A);
    return 0;
}
