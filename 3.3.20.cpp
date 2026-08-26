//3.3.20

#include <stdio.h>
#include <stdlib.h>

int main() {

    int n;
    printf("Enter the number of rows and columns for the arrays: \n");
    scanf("%d", &n);
    while (n < 1) {
        printf("Input error! Enter value > 0: \n");
        scanf("%d", &n);
    }

    float **A;
    A = (float**)malloc(n * sizeof(float*));
    
    for (int i = 0; i < n; i++) {
        A[i] = (float*)malloc(n * sizeof(float));
    }

    printf("Enter value of the martix: \n");
    for (int i = 0; i < n; i++) {   
        for (int j = 0; j < n; j++) {
            scanf("%f", &A[i][j]);
        }
        printf("\n");
    }

    float *C;
    C = (float*)malloc(n * sizeof(float));
    printf("Enter the value: \n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &C[i]);
    }
    int *index;
    index = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int flag = 1;
        int j = 0;
        while (flag > 0 && j < n) {
            if (C[i] < A[i][j]) {
                flag = 0;
            }
            j++;
        }
        if (flag > 0) {
            index[i] = 1;
        }
        else {index[i] = 0;}
    }

    for (int i = 0; i < n; i++) {
        if (index[i] == 1) {printf("%7.4f ", C[i]);}
    }

    float summ = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            summ += A[i][j];
        }
    }
    printf("\nThe sum of the elements of array A = %7.4f", summ);

    float max_negative;
    bool found_negative = false;
    int i = 0;
    int index_max_neg;

    while (i < n && !found_negative) {
        int j = 0;
        while (j < n && !found_negative) {
            if (A[i][j] < 0) {
                max_negative = A[i][j];
                index_max_neg = i;
                found_negative = true;
            }
        }
    }

    if (found_negative) {
        for (int i = index_max_neg; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i][j] < 0 && A[i][j] > max_negative) {
                    max_negative = A[i][j];
                }
            }
        }
        printf("\nMax negative value in matrix A = %7.4f", max_negative);
    } 
    else {
        printf("\nNo negative values found in matrix A");
    }

    for (int i = 0; i < n; i++) {
        free(A[i]);
    }

    free(A);
    free(C);
    free(index);
    return 0;
}