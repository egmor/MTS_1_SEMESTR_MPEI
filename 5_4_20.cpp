//5.4.20

#include "library_miri5_4.h"

int main() {
    int all;

    printf("Enter the value of lines and columns in array A and value of num in array P: \n");
    correct_enter(all, 1);
    FILE* read_matrix = fopen("matrix5_4.txt", "r");
    FILE* read_vector = fopen("vector5_4.txt", "r");
    FILE* out = fopen("out5_4.txt", "w");


    float **matrix;
    create_matrix(matrix, all, all);
    float *vector = (float*)malloc(all * sizeof(float));
    enter_matrix_file(read_matrix, matrix, all, all);
    enter_vector_file(read_vector, vector, all);

    fprintf(out, "MATRIX:\n");
    out_matrix_file(out, matrix, all, all);

    fprintf(out, "\nVECTOR:\n");
    out_vector_file(out, vector, all);

    float first_row = sum_first_row(matrix, all);
    bool usl = check(matrix, all, first_row);
    if (usl) {
        float sum_poz = sum_poz_vector(vector, all);
        fprintf(out, "\nSumma elements of first row > summ of any other row in matrix.\nSumma pozitive elements in vector: %7.4f", sum_poz);
    }
    else {
        float sum_neg = sum_neg_vector(vector, all);
        fprintf(out, "\nSumma elements of first row <= summ of any other row in matrix.\nSumma negative elements in vector: %7.4f", sum_neg);
    }


    clear_matrix(matrix, all);
    free(vector);
    return 0;
}