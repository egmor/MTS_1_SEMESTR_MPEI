//2.3.20

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int N;
    printf("Please, input value of numbers: ");
    scanf("%d", &N);
    while (N < 1) {
        printf("\nInput error. Please, input value of numbers > 0\n");
        scanf("%d", &N);
    }
    
    float *A = (float*)malloc(N * sizeof(float));
    float *C = (float*)malloc(N * sizeof(float));

    printf("Input %d numbers A:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%f", &A[i]);
    }

    printf("Input %d numbers C:\n", N);
    for (int j = 0; j < N; j++) {
        scanf("%f", &C[j]);
    }
    float minn = fabs(A[2] * C[N - 1]);
    float summ;
    for (int h = 3; h < N; h++) {
        summ = fabs(A[h] + C[N - h + 1]);
        if (summ < minn) {
            minn = summ;
        }
    }
    printf("Min summa = %6.4f", minn);

    float maxx = pow(A[0], C[0]);
    float d;

    for (int i = 1; i < N; i++) {
        d = pow(A[i], C[i]);
        if (d > maxx) {
            maxx = d;
        }

    }
    printf("Max A[i]^C[i] = %.3f", maxx);
    

    free(A);
    free(C);
    return 0;
}