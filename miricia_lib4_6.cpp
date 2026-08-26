#include "library_miri4_6.h"

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

float min_vector(float *vector, int row) { 
    float min = vector[0]; 
    for (int i = 1; i < row; i++) { 
        if (min > vector[i]) { 
            min = vector[i]; 
        } 
    } 
    return min; 
} 

float max_vector(float *vector, int row) { 
    float max = vector[0]; 
    for (int i = 1; i < row; i++) { 
        if (max < vector[i]) { 
            max = vector[i]; 
        } 
    } 
    return max; 
}

void new_array(float* &new_vector, float *vector, int row, float half_max, int &h) {
    h = 0;
    for (int i = 0; i < row; i++) {
        if (vector[i] <= half_max) {
            h++;
            new_vector = (float*)realloc(new_vector, h * sizeof(float));
            new_vector[h - 1] = vector[i];
        }
    }
    return;
}

//массив между первым и последним нулём

bool have_zero(float* vector, int row) {
    bool flag = false;
    int i = 0;
    while (i < row - 1 && !flag) {
        if (vector[i] == 0) {flag = true;}
        else {i++;}
    }
    return flag;
}

int index_first_zero(float* vector, int row) {
    bool flag = false;
    int index = 0;
    while (index < row - 1 && !flag) {
        if (vector[index] == 0) {flag = true;}
        else {index++;}
    }
    return index;
}

int index_last_zero(float* vector, int row) {
    bool flag = false;
    int index = row - 1;
    while (index > 0 && !flag) {
        if (vector[index] == 0) {flag = true;}
        else {index--;}
    }
    return index;
}

void array_zero(float* &new_vector, float *vector, int start, int end, int &h) {
    h = 0;
    for (int i = start + 1; i < end; i++) {
            h++;
            new_vector = (float*)realloc(new_vector, h * sizeof(float));
            new_vector[h - 1] = vector[i];
    }
    return;
}
