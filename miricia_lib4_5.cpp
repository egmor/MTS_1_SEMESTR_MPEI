#include "library_miri4_5.h"

void correct_enter(int &value, int num) { 
    scanf("%d", &value); 
    while (value < num) { 
        printf("Input error! Enter the value >= %d: ", num); 
        scanf("%d", &value); 
    } 
    return; 
}

void create_vector(int* &vector, int row) { 
    vector = (int*)malloc(row * sizeof(int)); 
    return; 
} 

void enter_vector_file(FILE* file_read, int* &vector, int num_vector) { 
    for (int i = 0; i < num_vector; i++) { 
        fscanf(file_read, "%d", &vector[i]); 
    } 
    fclose(file_read); 
    return; 
} 

void out_vector_file(FILE* file_out, int *vector, int num_vector) { 
    for (int i = 0; i < num_vector; i++) { 
        fprintf(file_out, "%3d ", vector[i]); 
    } 
    fprintf(file_out, "\n"); 
    return; 
} 

bool not_multi_num(int *vector, int row, int num) {
    bool flag = true;
    int i = 0;
    while (flag && i < row) {
        if (vector[i] % num == 0) {
            flag = false;
        }
        i++;
    }

    return flag;
}

bool multi_num(int *vector, int row, int num) {
    bool flag = false;
    int i = 0;
    while (!flag && i < row) {
        if (vector[i] % num == 0) {
            flag = true;
        }
        i++;
    }

    return flag;
}

int min_vector(int *vector, int row) { 
    int min = vector[0]; 
    for (int i = 1; i < row; i++) { 
        if (min > vector[i]) { 
            min = vector[i]; 
        } 
    } 
    return min; 
} 

int max_vector(int *vector, int row) { 
    int max = vector[0]; 
    for (int i = 1; i < row; i++) { 
        if (max < vector[i]) { 
            max = vector[i]; 
        } 
    } 
    return max; 
}

//защита

bool have_neg(int *vector, int row) {
    bool flag = false;
    int i = 0;
    while(i < row && !flag) {
        if (vector[i < 0]) {flag = true;}
        else {i++;}
    }
    return flag;
}

int abs_neg(int *vector, int row) {
    int sum_neg = 0;
    for (int i = 0; i < row; i++) {
        if (vector[i] < 0) {
            sum_neg += fabs(vector[i]);
        }
    }
    return sum_neg;
}

