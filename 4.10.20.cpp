//4.10.20

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void correct_int(int *X) {
    scanf("%d", X);
    while (*X < 1) {
        printf("Input error! Enter the value >= 1: ");
        scanf("%d", X);
    }
}

void enter_vector(float *X, int Y) {
    for (int i = 0; i < Y; i++) {
        scanf("%f", &X[i]);
    }
}

void out_vector(int *X, int Y) {
    for (int i = 0; i < Y; i++) {
        printf("%d ", X[i]);
    }
}

void enter_matrix(float **X, int Y, int Z) {
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < Z; j++) {
            scanf("%f", &X[i][j]);
        }
    }
}

void out_matrix(float **X, int Y, int Z) {
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < Z; j++) {
            printf("%6.4f ", X[i][j]);
        }
    }
}

float** create_matrix(int Y, int Z) {
    float **X = (float**)malloc(Y * sizeof(float*));
    for (int i = 0; i < Y; i++) {
        X[i] = (float*)malloc(Z * sizeof(float));
    }
    enter_matrix(X, Y, Z);  
    return X;
} 

void clear_matrix(float **X, int Y) {
    for (int i = 0; i < Y; i++) {
        free(X[i]);
    }
    free(X);
}

float f1(float X) {
    return pow(X, 3.0);
}

float f2(float X) {
    return exp(X);
}

void new_vector_B(float *X, int Y) {
    int y = 0;
    for (int i = 0; i < Y; i++) {
        if(f1(X[i]) > f2(X[i])) {y++;}
    }
    int *new_X = (int*)malloc(y * sizeof(int));
    int i = 0;
    int h = 0;
    if (y == 0) {printf("No values f1(B[i]) > f2(B[i])");}
    else {
        while (i < y && h < Y) {
        if  (f1(X[h]) > f2(X[h])) {
            new_X[i] = h;
            i++;
        }
        h++;
        }

        out_vector(new_X, y);
        free(new_X);
    }
}

void sum_matrix_A(float **X, int Y, int Z) {
    for (int i = 0; i < Y; i++) {
        float sum1 = 0;
        float sum2 = 0;
        for (int j = 0; j < Z; j++) {
            if (f1(X[i][j]) > f2(X[i][j])) {sum1 += X[i][j];}
            else if (f1(X[i][j]) < f2(X[i][j])) {sum2 += X[i][j];}
        }
        printf("Sum line %d with the condition: f1(A[i][j]) > f2(A[i][j]) = %6.4f\n", i, sum1);
        printf("Sum line %d with the condition: f1(A[i][j]) < f2(A[i][j]) = %6.4f\n\n", i, sum2);
    }
    
}


int main() {

    int line_A, column_A, num_B;

    printf("Enter the value of numbers in array B: \n");
    correct_int(&num_B);
    printf("Enter the value of lines in array A: \n");
    correct_int(&line_A);
    printf("Enter the value of columns in array A: \n");
    correct_int(&column_A);

    float *B = (float*)malloc(num_B * sizeof(float));
    float **A = create_matrix(line_A, column_A);

    enter_vector(B, num_B);

    new_vector_B(B, num_B);
    sum_matrix_A(A, line_A, column_A);
    
    clear_matrix(A, line_A);
    free(B);

    return 0;
}