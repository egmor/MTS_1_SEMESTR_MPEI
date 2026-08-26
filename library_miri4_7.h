#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void correct_enter(int &value, int num);
void create_matrix(float** &matrix, int row, int column); 
void clear_matrix(float** matrix, int row); 
void enter_matrix_file(FILE *file_read, float** &matrix, int row, int column); 
void out_matrix_file(FILE *file_out, float **matrix, int row, int column);
void max_index_under_diag(float **matrix, int row, int &max_index_row, int &max_index_column);
//защита
bool usl_havent_zero(float** matrix, int num);
void change_matrix(float** &matrix, int num);