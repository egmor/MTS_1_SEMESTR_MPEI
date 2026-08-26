#include "library_miri4_8.h"

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

void create_vector(float* &vector, int row) { 
    vector = (float*)malloc(row * sizeof(float)); 
    return; 
} 

void enter_vector_file(FILE* file_read, float* &vector, int num_vector) { 
    for (int i = 0; i < num_vector; i++) { 
        fscanf(file_read, "%f", &vector[i]); 
    } 
    fclose(file_read); 
    return; 
} 

void out_vector_file(FILE* file_out, float *vector, int num_vector) { 
    for (int i = 0; i < num_vector; i++) { 
        fprintf(file_out, "%7.4f ", vector[i]); 
    } 
    fprintf(file_out, "\n"); 
    return; 
} 

bool check(float **matrix, int num, float sum_first) {
    bool flag = true;
    int i = 1;
    while (i < num && flag) {
        float sum = 0;
        for (int j = 0; j < num; j++) {sum += matrix[i][j];}
        if (sum >= sum_first) {flag = false;}
        else {i++;}
    }
    return flag;   
}

float sum_first_row(float** matrix, int column) {
    float sum = 0;
    for (int j = 0; j < column; j++) {sum += matrix[0][j];}
    return sum;
}

float sum_poz_vector(float* vector, int num) {
    float sum = 0;
    for (int i = 0; i < num; i++) {
        if (vector[i] >= 0) {sum += vector[i];}
    }
    return sum;
}

float sum_neg_vector(float* vector, int num) {
    float sum = 0;
    for (int i = 0; i < num; i++) {
        if (vector[i] < 0) {sum += vector[i];}
    }
    return sum;
}