//5.1.20

#include <stdio.h>
#include <stdlib.h>

int main() {

    int d;
    int N;

    printf("Please, input value of numbers: ");
    scanf("%d", &N);
    while (N < 1) {
        printf("\nInput error. Please, input value of numbers > 0\n");
        scanf("%d", &N);
    }

    int *A = (int*)malloc(N * sizeof(int));

    printf("Input %d numbers A:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    printf("Please, enter value d: ");
    scanf("%d", &d);

    int fl = 1;
    int i = N - 1;
    int num = i;

    while (fl > 0 && i >= 0) {
        if (A[i] == d) {
            num = i;
            fl = 0;
        }
        else {i--;}
    }

    int minn = A[0];
    int num_minn = 0;
    if (fl == 0) {
        for (int j = 1; j < num; j ++) {
            if (A[j] > 0 && A[j] < minn) {
                minn = A[j];
                num_minn = j;
            }
        }
    }
    else {
        for (int j = 1; j < N; j++) {
            if (A[j] > 0 && A[j] < minn) {
                minn = A[j];
                num_minn = j;
            }
        }
    }
    
    printf("The number of the first minimum element: %d, value: %d", minn, num_minn);

    free(A);
    return 0;
}
