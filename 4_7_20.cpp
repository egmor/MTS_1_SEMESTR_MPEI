//4.7.20

#include "library_miri4_7.h"

int main() {
    int num_A, num_B, num_C;
    FILE *out = fopen("out4_7.txt", "w");
    if (!out) {printf("Error: out4_7.txt not found");}

    printf("Enter the value of lines and columns in matrix A: \n");
    correct_enter(num_A, 1);
    printf("Enter the value of lines and columns in matrix B: \n");
    correct_enter(num_B, 1);
    printf("Enter the value of lines and columns in matrix C: \n");
    correct_enter(num_C, 1);

    float **A;
    FILE *file_read_A = fopen("matrix4_7A.txt", "r");
    if (!file_read_A) {printf("Error: matrix4_7A.txt not found");}
    create_matrix(A, num_A, num_A);
    enter_matrix_file(file_read_A, A, num_A, num_A);
    fprintf(out, "\nMatrix A: \n");
    out_matrix_file(out, A, num_A, num_A);
    
    float **B;
    FILE *file_read_B = fopen("matrix4_7B.txt", "r");
    if (!file_read_B) {printf("Error: matrix4_7B.txt not found");}
    create_matrix(B, num_B, num_B);
    enter_matrix_file(file_read_B, B, num_B, num_B);
    fprintf(out, "\nMatrix B: \n");
    out_matrix_file(out, B, num_B, num_B);

    float **C;
    FILE *file_read_C = fopen("matrix4_7C.txt", "r");
    if (!file_read_C) {printf("Error: matrix4_7C.txt not found");}
    create_matrix(C, num_C, num_C);
    enter_matrix_file(file_read_C, C, num_C, num_C);
    fprintf(out, "\nMatrix C: \n");
    out_matrix_file(out, C, num_C, num_C);
    

    int max_index_row_A, max_index_column_A;
    float max_A;
    max_index_under_diag(A, num_A, max_index_row_A, max_index_column_A);
    fprintf(out, "\nIndexes of the max value below the main diagonal A: row = %3d, column = %3d", max_index_row_A, max_index_column_A);

    int max_index_row_B, max_index_column_B;
    float max_B;
    max_index_under_diag(B, num_B, max_index_row_B, max_index_column_B);
    fprintf(out, "\nIndexes of the max value below the main diagonal B: row = %3d, column = %3d", max_index_row_B, max_index_column_B);

    int max_index_row_C, max_index_column_C;
    float max_C;
    max_index_under_diag(C, num_C, max_index_row_C, max_index_column_C);
    fprintf(out, "\nIndexes of the max value below the main diagonal C: row = %3d, column = %3d\n", max_index_row_C, max_index_column_C);
//защита
    bool uslA = usl_havent_zero(A, num_A);
    if (uslA) {
        change_matrix(A, num_A);
        fprintf(out, "\nCHANGED MATRIX A: \n");
        out_matrix_file(out, A, num_A, num_A);
    }

    bool uslB = usl_havent_zero(B, num_B);
    if (uslB) {
        change_matrix(B, num_B);
        fprintf(out, "\nCHANGED MATRIX B: \n");
        out_matrix_file(out, B, num_B, num_B);
    }

    bool uslC = usl_havent_zero(C, num_C);
    if (uslC) {
        change_matrix(C, num_C);
        fprintf(out, "\nCHANGED MATRIX C: \n");
        out_matrix_file(out, C, num_C, num_C);
    }

    fclose(out);
    clear_matrix(A, num_A);
    clear_matrix(B, num_B);
    clear_matrix(C, num_C);

    return 0;
}