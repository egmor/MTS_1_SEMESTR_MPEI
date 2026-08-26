//4.2.20

#include "library_miri4_2.h"

int main() {
    int row, column;
    FILE *out = fopen("out4_2.txt", "w");
    if (!out) {printf("Error: out4_2.txt not found");}

    printf("Enter the number of rows for the matrix: \n");
    correct_enter(row, 1);
    printf("Enter the number of column for the matrix: \n");
    correct_enter(column, 1);

    float **matrix;
    FILE *file_read = fopen("matrix4_2.txt", "r");
    if (!file_read) {printf("Error: matrix4_2.txt not found");}
    create_matrix(matrix, row, column);
    enter_matrix_file(file_read, matrix, row, column);
    fprintf(out, "MATRIX: \n");
    out_matrix_file(out, matrix, row, column);

    int *vector;
    create_vector(vector, row);
    result_vector(vector, row, column, matrix);
    
    fprintf(out, "\nRESULT VECTOR: \n");
    out_vector_file(out, vector, row);


//защита
    float min_poz;
    bool flag;
    min_sum(matrix, row, column, min_poz, flag);
    if (flag) {fprintf(out, "\nMINIMUM SUM OF POZITIVE ELEMENT = %7.4f", min_poz);}
    else {fprintf(out, "\nIN MATRIX NO COLUMN WITH POZITIVE ELEMENT");}
    

    clear_matrix(matrix, row);

    fclose(out);
    free(vector);
    return 0;
}