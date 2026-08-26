#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void correct_enter(int &value, int num);
void create_vector(float* &vector, int row);
void enter_vector_file(FILE *file_read, float* &vector, int num_vector); 
void out_vector_file(FILE *file_out, float *vector, int num_vector);
float min_vector(float *vector, int row); 
float max_vector(float *vector, int row);
void new_array(float* &new_vector, float *vector, int row, float half_max, int &count);
//защита
bool have_zero(float* vector, int row);
int index_first_zero(float* vector, int row);
int index_last_zero(float* vector, int row);
void array_zero(float* &new_vector, float *vector, int start, int end, int &h);