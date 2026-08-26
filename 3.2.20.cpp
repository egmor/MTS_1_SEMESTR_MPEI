//3.2.20

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int line = 10;
    int column = 2;

    float **A;
    A = (float**)malloc(line * sizeof(float*));
    for (int i = 0; i < line; i++) {
        A[i] = (float*)malloc(column * sizeof(float));
    }

    for (int i = 0; i < line; i++) {
        printf("Enter the value of the radius and height of the cylinder №%d: \n", i+1);
        for (int j = 0; j < column; j++) {
            scanf("%f", &A[i][j]);
            while (A[i][j] <= 0) {
                printf("The values cannot be non-positive. Input value > 0: \n");
                scanf("%f", &A[i][j]);
            }
            
        }
    }

    float T;
    printf("Enter the value of T: \n");
    scanf("%f", &T);
    while (T <= 0) {
        printf("Input error! Enter the value of T > 0: \n");
        scanf("%f", &T);
    }

    bool flag = true;
    float volume, square;
    int i = 0;
    float sum_volume = 0;
    float sum_square = 0;

    while (flag && i <= line - 1) {
        volume = pow(A[i][0], 2.0) * A[i][1] * M_PI;
        square = 2.0 * M_PI * A[i][0] * (A[i][1] + A[i][0]);
        i++;
        if (volume <= T) {
            printf("Volume of the cylinder №%d = %7.4f\n", i, volume);
            printf("Square of the cylinder №%d = %7.4f\n\n", i, square);
            sum_volume += volume;
            sum_square += square;
        }
        if (volume > T) {
            flag = false;
        }
    }

    printf("Sum volume of the all cylinder less than T = %7.4f\n", sum_volume);
    printf("Sum square of the all cylinder less than T = %7.4f", sum_square);


    for (int i = 0; i < line; i++) {
        free(A[i]);
    }

    free(A);
    return 0;
}