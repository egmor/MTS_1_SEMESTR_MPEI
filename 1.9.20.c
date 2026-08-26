//1.9.20

#include <stdio.h>
#include <math.h>

int main()
{
    float X, HX, Z, HZ;
    int N, M;
    printf("PLease, enter starting value X:\n");
    scanf("%f", &X);
    while (X == 20) {
        printf("Input error! Please, enter value X NOT equal 20\n");
        scanf("%f", &X);
    }

    printf("Please, enter the change step of X:\n");
    scanf("%f", &HX);

    printf("Please, enter number of X values:\n");
    scanf("%i", &N);
    while (N <= 0) {
        printf("Input error! Please, enter value > 0\n");
        scanf("%i", &N);
    }

    printf("PLease, enter starting value Z:\n");
    scanf("%f", &Z);

    printf("Please, enter the change step of Z:\n");
    scanf("%f", &HZ);

    printf("Please, enter number of Z values:\n");
    scanf("%i", &M);
    while (M <= 0) {
        printf("Input error! Please, enter value > 0\n");
        scanf("%i", &M);
    }

    float y1, y2, y;
    float start_X = X;
    printf("Table:\n");
    printf("   ");
    for (int i = 1; i <= N; i++) {
        printf("|       X%i    ", i);
    }
    printf("|\n");
    for (int j = 1; j <= M; j++) {
        printf("Z%i |", j);
        X = start_X;
        for (int h = 1; h <= N; h ++) {
            y1 = sqrt(pow(X, 4.0/5.0) + exp((4 - Z) / 5.0));
            y2 = (1.0 / 3.0) * log(fabs(X - 20));
            y = y1 + y2;
            printf("   %f  |", y);
            X += HX;
        }
        Z += HZ;
        printf("\n");
    }
    return 0;
}