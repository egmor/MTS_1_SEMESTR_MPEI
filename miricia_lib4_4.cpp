#include "library_miri4_4.h"

void correct_enter(int &value, int num) { 
    scanf("%d", &value); 
    while (value < num) { 
        printf("Input error! Enter the value >= %d: ", num); 
        scanf("%d", &value); 
    } 
    return; 
}

void create_vector(float* &vector, int row) { 
    vector = (float*)malloc(row * sizeof(float)); 
    return; 
} 

float min_vector(float *vector, int row) { 
    float min = vector[0]; 
    for (int i = 1; i < row; i++) { 
        if (min > vector[i]) { 
            min = vector[i]; 
        } 
    } 
    return min; 
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

bool count_zero(float *vector, int num_vector) {
    int i = 0;
    bool flag = false;
    while(!flag && i < num_vector) {
        if (vector[i] == 0) {
            flag = true;
        }
        else {i++;}
    }
    return flag;
}

int index_last_zero(float *vector, int num_vector) {
    int index = num_vector - 1;
    bool flag = false;
    while (!flag && index > 0) {
        if (vector[index] == 0) {
            flag = true;
        }
        else{index--;}
    }
    return index;
}

float min_after(float *vector, int row, int index) {
    float min = vector[index + 1]; 
    for (int i = index + 2; i < row; i++) { 
        if (min > vector[i]) { 
            min = vector[i]; 
        } 
    } 
    return min; 
}
