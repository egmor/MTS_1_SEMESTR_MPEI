#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void correct_enter(int &value, int num);
void create_matrix(float** &matrix, int row, int column); 
void clear_matrix(float **martix, int row);
void enter_matrix_file(FILE *file_read, float** &matrix, int row, int column); 
void out_matrix_file(FILE *file_out, float **matrix, int row, int column);
void create_vector(float* &vector, int row);
void enter_vector_file(FILE* file_read, float* &vector, int num_vector);
void out_vector_file(FILE* file_out, float *vector, int num_vector);
bool check(float **matrix, int num, float sum_first);
float sum_first_row(float** matrix, int column);
float sum_poz_vector(float* vector, int num);
float sum_neg_vector(float* vector, int num);