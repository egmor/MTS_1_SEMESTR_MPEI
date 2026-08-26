#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define TYPE_CHOOSE(TYPE, FORMAT) \
void correct_enter_##TYPE(TYPE *value, int num); \
void enter_matrix_##TYPE(TYPE **matrix, int row, int column); \
void out_matrix_##TYPE(TYPE **matrix, int row, int column); \
void create_matrix_##TYPE(TYPE ***vector, int row, int column); \
void clear_matrix_##TYPE(TYPE **matrix, int row); \
void enter_matrix_file_##TYPE(FILE *file_read, TYPE **matrix, int row, int column); \
void out_matrix_file_##TYPE(FILE *file_out, TYPE **matrix, int row, int column); \
void enter_vector_##TYPE(TYPE *vector, int row); \
void out_vector_##TYPE(TYPE *vector, int row); \
void create_vector_##TYPE(TYPE **vector, int row); \
TYPE min_vector_##TYPE(TYPE *vector, int row); \
TYPE max_vector_##TYPE(TYPE *vector, int row); \
void enter_vector_file_##TYPE(FILE *file_read, TYPE *vector, int num_vector); \
void out_vector_file_##TYPE(FILE *file_out, TYPE *vector, int num_vector); \


bool not_multi_num(int *vector, int row, int num);
bool multi_num(int *vector, int row, int num);
bool multi_num_row(int **matrix, int row, int column, int num);
bool not_multi_num_row(int **matrix, int row, int column, int num);
bool multi_num_column(int **matrix, int row, int column, int num);
bool not_multi_num_column(int **matrix, int row, int column, int num);

TYPE_CHOOSE(int, "%d")
TYPE_CHOOSE(float, "%f")
