//2.2.20

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int N, cc = 0;
    float a, b;

    printf("Enter the beginning and end of the segment: ");
    scanf("%f", &a);

    scanf("%f", &b);
    while (b < a) {
        printf("Input error! Enter b > a: ");
        scanf("%f", &b);
    }

    printf("Input value of numbers: ");
    scanf("%d", &N);
    
    while (N < 1) {
        printf("Input error. Input value N > 0: ");
        scanf("%d", &N);
    }
    
    float *A = (float*)malloc(N * sizeof(float));

    printf("Input %d numbers:\n", N);
    for (int n = 0; n < N; n++) {
        scanf("%f", &A[n]);
    }
    printf("Initial array: ");
    for (int h = 0; h < N; h++) {
        printf("%6.4f ", A[h]);
    }
    printf("\n");

    int count = 0;
    float sr_geom = 1;

    for (int i = 0; i < N; i++) {
        if (a < A[i] && A[i] < b) {
            sr_geom *= A[i];
            cc++;
        }
    }

    for (int i = 0; i < N; i++) {
        if (A[i] >= 0) {
            A[i] /= i;
        }
    }
    for (int i = 0; i < N; i++) {
        if (A[i] < 0) {
            count++;
        }
    }
    
    
    printf("Modified array: ");
    for (int j = 0; j < N; j++) {
        printf("%6.4f ", A[j]);
    }

    printf("\nThe number of negative numbers = %i\n", count);
    
    if (cc == 0) {
        printf("There are no values A[i] belonging to (%.3f; %.3f)\n", a, b);
    }
    else {
        sr_geom = pow(sr_geom, 1.0/cc);
        printf("Geometric mean = %.3f\n", sr_geom);
    }

    
    free(A);
    return 0;
}