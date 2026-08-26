#include "library_miri4_8.h"

void correct_enter(int &value, int num) { 
    scanf("%i", &value); 
    while (value < num) { 
        printf("Input error! Enter the value >= %d: ", num); 
        scanf("%i", &value); 
    } 
    return; 
} 

void create_matrix(int** &matrix, int row, int column) { 
    matrix = (int**)malloc(row * sizeof(int*)); 
    for (int i = 0; i < row; i++) { 
        matrix[i] = (int*)malloc(column * sizeof(int)); 
    } 
    return; 
} 

void clear_matrix(int **martix, int row) { 
    for (int i = 0; i < row; i++) { 
        free(martix[i]); 
    } 
    free(martix); 
} 

void enter_matrix_file(FILE *file_read, int** &matrix, int row, int column) { 
    for (int i = 0; i < row; i++) { 
        for (int j = 0; j < column; j ++) { 
            fscanf(file_read, "%d", &matrix[i][j]); 
        } 
        fscanf(file_read, "%*[^\n]"); 
    } 
    fclose(file_read); 
    return; 
} 

void out_matrix_file(FILE *file_out, int **matrix, int row, int column) { 
    for (int i = 0; i < row; i++) { 
        for (int  j = 0; j < column; j++) { 
            fprintf(file_out, "%3d ", matrix[i][j]); 
        } 
        fprintf(file_out, "\n"); 
    } 
    return; 
}

void check(int &i, bool &usl, int** matrix, int row, int column, int D) {
    usl = false;
    while (i < row && !usl) {
        int j = 0;
        while (j < column && !usl) {
            if (matrix[i][j] % D != 0) {usl = true;}
            else {j++;}
        }
        if (!usl) {i++;}
    }
    return;
}


//если макс матрицы расположен в левом нижнем четырёхугол то поменять левый нижний с правым верхним не зеркальным

int find_max(int** matrix, int row, int column) {
    int max = matrix[0][0];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (max < matrix[i][j]) {max = matrix[i][j];}
        }
    }
    return max;
}
bool check(int** matrix, int row, int column, int max) {
    bool flag = false;
    int i = row / 2;
    while (i < row && !flag) {
        int j = 0;
        while (j < (column / 2) && !flag) {
            if (matrix[i][j] == max) {flag = true;}
            else {j++;}
        }
        if (!flag) {i++;}
    }
    return flag;
}

void change_matrix(int** &matrix, int row, int column) {
    int half_row = row / 2;
    int half_col = column / 2;
    
    for (int i = half_row; i < row; i++) {
        for (int j = 0; j < half_col; j++) {
            int buff = matrix[i][j];
            matrix[i][j] = matrix[i - half_row][j + half_col + 1];
            matrix[i - half_row][j + half_col + 1] = buff;
        }
    }
    return;
}