//4.8.20

#include <stdio.h>
#include <stdlib.h>

void correct_int(int *X) {
    scanf("%d", X);
    while (*X < 1) {
        printf("Input error! Enter the value >= 1: ");
        scanf("%d", X);
    }
}

void enter_matrix(int **X, int Y, int Z) {
    printf("\nEnter the values of array: \n");
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < Z; j++) {
            scanf("%f", &X[i][j]);
        }
        printf("\n");
    }
}

void out_matrix(float **X, int Y) {
    printf("\nMatrix: \n");
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < Y; j++) {
            printf("%6.4f ", X[i][j]);
        }
        printf("\n");
    }
}

int** create_matrix(int Y, int Z) {
    int **X = (int**)malloc(Y* sizeof(int*));
    for (int i = 0; i < Y; i++) {
        X[i] = (int*)malloc(Z * sizeof(int));
    }
    enter_matrix(X, Y, Z);  
    return X;
} 

void clear_matrix(int **X, int Y) {
    for (int i = 0; i < Y; i++) {
        free(X[i]);
    }
    free(X);
}

void check_matrix(int **X, int Y, int Z, int H) {
    bool flag = false;
    int i = 0;
    while (!flag && i < Y) {
        for (int j = 0; j < Z; j++) {
            if (X[i][j] % H != 0) {
                flag = true;
            }
        }
        if (flag) {printf("The number of line with value not multiple of %d = %d \n", H, i);}
        i++;
    }
    if (!flag) {
        printf("The array hasn't number of line with value not multiple of %d \n", H);
    }
}



int main() {

    int line_A, column_A, D;

    printf("Enter the value of lines in array A: \n");
    correct_int(&line_A);
    printf("Enter the value of columns in array A: \n");
    correct_int(&column_A);

    int **A = create_matrix(line_A, column_A);

    printf("Enter the value D: \n");
    correct_int(&D);

    check_matrix(A, line_A, column_A, D);

    clear_matrix(A, line_A);

    return 0;
}
