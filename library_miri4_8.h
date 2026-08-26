#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void correct_enter(int &value, int num);
void create_matrix(int** &matrix, int row, int column); 
void clear_matrix(int** matrix, int row); 
void enter_matrix_file(FILE *file_read, int** &matrix, int row, int column); 
void out_matrix_file(FILE *file_out, int **matrix, int row, int column);
void check(int &i, bool &usl, int** matrix, int row, int column, int D);
//защита 
int find_max(int** matrix, int row, int column);
bool check(int** matrix, int row, int column, int max);
void change_matrix(int** &matrix, int row, int column);