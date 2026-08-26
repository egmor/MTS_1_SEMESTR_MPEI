#include "library_miri4_7.h"

void correct_enter(int &value, int num) { 
    scanf("%i", &value); 
    while (value < num) { 
        printf("Input error! Enter the value >= %d: ", num); 
        scanf("%i", &value); 
    } 
    return; 
} 

void create_matrix(float** &matrix, int row, int column) { 
    matrix = (float**)malloc(row * sizeof(float*)); 
    for (int i = 0; i < row; i++) { 
        matrix[i] = (float*)malloc(column * sizeof(float)); 
    } 
    return; 
} 

void clear_matrix(float **martix, int row) { 
    for (int i = 0; i < row; i++) { 
        free(martix[i]); 
    } 
    free(martix); 
} 

void enter_matrix_file(FILE *file_read, float** &matrix, int row, int column) { 
    for (int i = 0; i < row; i++) { 
        for (int j = 0; j < column; j ++) { 
            fscanf(file_read, "%f", &matrix[i][j]); 
        } 
        fscanf(file_read, "%*[^\n]"); 
    } 
    fclose(file_read); 
    return; 
} 

void out_matrix_file(FILE *file_out, float **matrix, int row, int column) { 
    for (int i = 0; i < row; i++) { 
        for (int  j = 0; j < column; j++) { 
            fprintf(file_out, "%7.4f ", matrix[i][j]); 
        } 
        fprintf(file_out, "\n"); 
    } 
    return; 
}

void max_index_under_diag(float **matrix, int row, int &max_index_row, int &max_index_column) {
    float max = matrix[1][0];
    max_index_row = 1;
    max_index_column = 0;
    for (int i = 2; i < row; i++) {
        for (int j = 0; j < i; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
                max_index_row = i;
                max_index_column = j;
            }
        }
    }
    return;
}

bool usl_havent_zero(float** matrix, int num) {
    bool flag = true;
    int i = 0;
    while (i < num - 1 && flag) {
        int j = 0;
        while (j < num - i && flag) {
            if (matrix[i][j] == 0) {flag = false;}
            else {j++;}
        }
        if (flag) {i++;}
    }
    return flag;
}

void change_matrix(float** &matrix, int num) {
    for (int i = 0; i < num; i++) {
        for (int j = num - i + 1; j < num; j++) {
            matrix[i][j] /= matrix[num - j - 1][num - i - 1];
        }
    }
    return;
}
//если выше побочной нет ни одного 0, то разделить все элементы ниже побоч диаг на симметрич им выше побоч диаг
