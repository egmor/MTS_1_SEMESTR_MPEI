#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void correct_enter(int &value, int num);
void create_matrix(float** &matrix, int row, int column); 
void clear_matrix(float** matrix, int row); 
void enter_matrix_file(FILE *file_read, float** &matrix, int row, int column); 
void out_matrix_file(FILE *file_out, float **matrix, int row, int column);
int count_first(float **matrix, int row);
int num_column(float **matrix, int row, int column, int count_first);
void change_column(float** &matrix, int row, int col);
void zero_down(float** &matrix, int row);
