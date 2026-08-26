#include "library_miri5_3.h"

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

int count_first(float **matrix, int row) {
    int count = 0;
    for (int i = 0; i < row; i++) {
        if (matrix[i][0] == 0) {count++;}
    }
    return count;
}

int num_column(float **matrix, int row, int column, int count_first) {
    int min_count_zero = count_first;
    int index = 0;
    
    for (int j = 0; j < column; j++) {
        int count = 0;
        for (int i = 0; i < row; i++) {
            if (matrix[i][j] == 0) {count++;}
        }
        if (min_count_zero > count) {
            min_count_zero = count;
            index = j;
        }
    }
    
    return index;
}

void change_column(float** &matrix, int row, int col) {
    for (int i = 0; i < row; i++) {
        float f_col = matrix[i][0];
        matrix[i][0] = matrix[i][col];
        matrix[i][col] = f_col;
    }
    return;
}

void zero_down(float** &matrix, int row) {
    for (int i = 0; i < row - 1; i++) {
        if (matrix[i][0] == 0) {
            float zer_num = matrix[i][0];
            matrix[i][0] = matrix[i+1][0];
            matrix[i+1][0] = zer_num; 
        }
    }
    return;
}
    
