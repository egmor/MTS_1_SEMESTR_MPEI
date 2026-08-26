#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void correct_enter(int &value, int num);
void create_vector(float* &vector, int row); 
float min_vector(float *vector, int row);
void enter_vector_file(FILE *file_read, float* &vector, int num_vector); 
void out_vector_file(FILE *file_out, float *vector, int num_vector); 
bool count_zero(float *vector, int num_vector);
int index_last_zero(float *vector, int num_vector);
float min_after(float *vector, int row, int index);
