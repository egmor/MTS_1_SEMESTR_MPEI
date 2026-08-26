//5.3.20

#include "library_miri5_3.h"

int main() {
    int row, column, D;
    FILE *out = fopen("out5_3.txt", "w");
    if (!out) {printf("Error: out5_3.txt not found");}

    printf("Enter the number of rows for the matrix: \n");
    correct_enter(row, 1);
    printf("Enter the number of column for the matrix: \n");
    correct_enter(column, 1);

    float **matrix;
    FILE *file_read = fopen("matrix5_3.txt", "r");
    if (!file_read) {printf("Error: matrix5_3.txt not found");}
    create_matrix(matrix, row, column);
    enter_matrix_file(file_read, matrix, row, column);
    fprintf(out, "MATRIX: \n");
    out_matrix_file(out, matrix, row, column);

    int count_f = count_first(matrix, row);
    if (count_f != 0) {
        int number_col = num_column(matrix, row , column, count_f);
        change_column(matrix, row, number_col);
        zero_down(matrix, row);
        fprintf(out, "\nMODIFIED MATRIX: \n");
        out_matrix_file(out, matrix, row, column);
    }
    else {fprintf(out, "\nMatrix not modified because firat row hasn't zero num");}
    

    fclose(out);
    clear_matrix(matrix, row);
    return 0;
}