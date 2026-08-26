//3.4.20

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int line, column;

    printf("Enter the number of rows for the array A: \n");
    scanf("%d", &line);
    while (line < 1) {
        printf("Input error! Enter value > 0: \n");
        scanf("%d", &line);
    }

    printf("Enter the number of column for the array A: \n");
    scanf("%d", &column);
    while (column < 1) {
        printf("Input error! Enter value > 0: \n");
        scanf("%d", &column);
    }

    float **A;
    A = (float**)malloc(line * sizeof(float*));
    for (int i = 0; i < line; i++) {
        A[i] = (float*)malloc(column * sizeof(float));
    } 

    printf("Enter the value: \n");
    for (int i = 0; i < line; i++) {
        for (int j = 0; j < column; j++) {
            scanf("%f", &A[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < line; i++) {
        for (int j = 0; j < column; j++) {
            printf("%.f ", A[i][j]);
        }
        printf("\n");
    }

    int j = 0;
    bool flag_1 = false;
    while (!flag_1 && j < column) {
        int i = 0;
        bool flag_1 = true;
        while (flag_1 && i < line) {
            if (A[i][j] >= 0) {
                flag_1 = false;
            }
            else {i++;}
        }
        if (!flag_1) {j++;}
    }

    if (!flag_1){printf("The number of the first column with negative numbers only = %d", j);}
    else {printf("No column with negative numbers only");}

    int j = column - 1;
    bool flag = false;
    while(!flag && j >= 0) {
        int i = 0;
        flag = true;
        while (flag && i < line - 1) {
            if (A[i][j] >= A[i+1][j]) {
                flag = false;
            }
            else {i++;}
        }
        if (!flag) {j--;}
    }

    if (!flag){printf("The last column with the elements arranged in ascending order =  %d", j);}
    else {printf("No column with the elements arranged in ascending order");}

    for (int i = 0; i < line; i++) {
        free(A[i]);
    }

    free(A);
    return 0;
}