#include "library_miri4_2.h"

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

void create_vector(int* &vector, int row) { 
    vector = (int*)malloc(row * sizeof(int)); 
    return; 
} 

void enter_vector_file(FILE* file_read, int* &vector, int num_vector) { 
    for (int i = 0; i < num_vector; i++) { 
        fscanf(file_read, "%i", &vector[i]); 
    } 
    fclose(file_read); 
    return; 
} 

void out_vector_file(FILE* file_out, int *vector, int num_vector) { 
    for (int i = 0; i < num_vector; i++) { 
        fprintf(file_out, "%3i", vector[i]); 
    } 
    fprintf(file_out, "\n"); 
    return; 
} 

int check(float **matrix, int row, int column) {
    bool flag = true;
    int j = 0;
    while (flag && j < column - 1) {
        if (matrix[row][j] < matrix[row][j + 1]) {
            j++;
        }
        else {flag = false;}
    }
    return flag;
}

void result_vector(int* &vector, int row, int column, float **matrix) {
    for (int i = 0; i < row; i++) {
        vector[i] = check(matrix, i, column);
    }
    return;
}
//защита начинается здесь
bool check_second(float** matrix, int row, int column) {
    int i = 0;
    bool flag = false;
    while (i < row - 1 && !flag) {
        if (matrix[i][column] > 0) {flag = true;}
        else {i++;}
    }
    return flag;
}

void first_column(float** matrix, int row, int column, int &index, bool &flag) {
    index = 0;
    flag = false;
    while (index < column && !flag) {
        if (check_second(matrix, row, index)) {flag = true;}
        else {index++;}
    }
}

float first_sum(float** matrix, int row, int index) {
    float first = 0;
    for (int i = 0; i < row; i++) {
        if (matrix[i][index] > 0) {
            first += matrix[i][index];
        }
    }
    return first;
}

float sum_column(float** matrix, int row, int column) {
    float sum = 0;
    for (int i = 0; i < row; i++) {
        if (matrix[i][column] > 0) {sum += matrix[i][column];}
    }
    return sum;
}

void min_sum(float** matrix, int row, int column, float &min_sum, bool &flag) {
    int index;
    first_column(matrix, row, column, index, flag);
    min_sum = first_sum(matrix, row, index);
    for (int j = index + 1; j < column; j++) {
        float sum = sum_column(matrix, row, j);
        if (sum < min_sum && sum != 0) {min_sum = sum;}
    }
    return;
}
//найти столбец с мин суммой полож элем при этом их отсутствие для меня не минимально