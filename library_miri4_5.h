#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void correct_enter(int &value, int num);
void create_vector(int* &vector, int row);
void enter_vector_file(FILE *file_read, int* &vector, int num_vector); 
void out_vector_file(FILE *file_out, int *vector, int num_vector);
bool not_multi_num(int *vector, int row, int num);
bool multi_num(int *vector, int row, int num);
int min_vector(int *vector, int row); 
int max_vector(int *vector, int row);
//защита
bool have_neg(int *vector, int row);
int abs_neg(int *vector, int row);
