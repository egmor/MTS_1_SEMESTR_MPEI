#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void correct_enter(int &value, int num);
void create_matrix(float** &matrix, int row, int column); 
void clear_matrix(float** matrix, int row); 
void enter_matrix_file(FILE *file_read, float** &matrix, int row, int column); 
void out_matrix_file(FILE *file_out, float **matrix, int row, int column);
void create_vector(int* &vector, int row);
void enter_vector_file(FILE* file_read, int* &vector, int num_vector);
void out_vector_file(FILE *file_out, int *vector, int num_vector);
int check(float **matrix, int row, int column);
void result_vector(int* &vector, int row, int column, float **matrix);
//защита
bool check_second(float** matrix, int row, int column);
void first_column(float** matrix, int row, int column, int &index, bool &flag);
float sum_column(float** matrix, int row, int column);
void min_sum(float** matrix, int row, int column, float &min_sum, bool &flag);
float first_sum(float** matrix, int row, int index);