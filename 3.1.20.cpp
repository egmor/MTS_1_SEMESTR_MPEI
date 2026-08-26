//3.1.20

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int line = 6;
    int column = 3;
    int P, count = 0;
    float usl;
    float max_area = 0;
    int max_index = 1;
    
    int **A;
    A = (int**)malloc(line * sizeof(int*));
    for (int i = 0; i < line; i++) {
        A[i] = (int*)malloc(column * sizeof(int));
    }

    for (int i = 0; i < line; i++) {
        for (int j = 0; j < column; j ++) {
            printf("Please, enter the length %d of the side of the triangle №%d: ", j+1, i+1);
            scanf("%d", &A[i][j]);
            while (A[i][j] < 1) {
                printf("Input error! The length cannot be negative: \n");
                scanf("%d", &A[i][j]);
            }
        }
        printf("\n");
    }


    for (int i = 0; i < line; i++) {
        P = A[i][0] + A[i][1] + A[i][2];
        usl = ((P/2.0 - A[i][0]))*((P/2.0 - A[i][1]))*((P/2.0 - A[i][2]));
        if (usl > 0) {
            printf("The perimeter of the triangle №%d = %d\n", i+1, P);
            count++;
        }
        else {
            printf("The triangle №%d cannot be constructed\n", i+1);
        }

    }
    printf("\nNumber of triangles = %d \n", count);
    

    max_area = 0;
    int area = 0;
    for (int i = 0; i < line; i++) {
        P = A[i][0] + A[i][1] + A[i][2];
        float p = P/2.0;
        area = sqrt(p * (p - A[i][0]) * (p - A[i][1]) * (p - A[i][2]));
        if (max_area < area) {
            max_index = i+1;
            max_area = area;
        }
    }

    printf("The triangle with the maximum area - №%d. Area = %.2f", max_index, max_area);

    for (int i = 0; i < line; i++) {
        free(A[i]);
    }

    free(A);
    return 0;
}