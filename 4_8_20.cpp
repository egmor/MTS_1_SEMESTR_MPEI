//4.8.20

#include "library_miri4_8.h"

int main() {
    int row, column, D;
    FILE *out = fopen("out4_8.txt", "w");
    if (!out) {printf("Error: out4_8.txt not found");}

    printf("Enter the number of rows for the matrix: \n");
    correct_enter(row, 1);
    printf("Enter the number of column for the matrix: \n");
    correct_enter(column, 1);

    int **matrix;
    FILE *file_read = fopen("matrix4_8.txt", "r");
    if (!file_read) {printf("Error: matrix4_8.txt not found");}
    create_matrix(matrix, row, column);
    enter_matrix_file(file_read, matrix, row, column);
    fprintf(out, "MATRIX: \n");
    out_matrix_file(out, matrix, row, column);

    printf("Enter the value D: \n");
    correct_enter(D, 1);

    int i;
    bool usl;
    check(i, usl, matrix, row, column, D);
    if (usl) {fprintf(out, "The row with num not multiplicity %d = %d", D, i);}
    else {fprintf(out, "The matrix hasn't row with num not multiplicity %d", D);}

//защита
    int max = find_max(matrix, row, column);
    bool usl2 = check(matrix, row, column, max);
    fprintf(out, "\n%i\n", max);
    if (usl2) {
        change_matrix(matrix, row, column);
        fprintf(out, "ZASCHITA:\n");
        out_matrix_file(out, matrix, row, column);
    }

    fclose(out);
    clear_matrix(matrix, row);

    return 0;
}
