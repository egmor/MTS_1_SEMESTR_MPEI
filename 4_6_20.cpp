//4.6.20

#include "library_miri4_6.h"

int main() {
    int num_A, num_B, num_C;
    FILE *out = fopen("out4_6.txt", "w");
    if (!out) {printf("Error: out4_6.txt not found");}

    printf("Enter the value of numbers in array A: \n");
    correct_enter(num_A, 1);
    printf("Enter the value of numbers in array B: \n");
    correct_enter(num_B, 1);
    printf("Enter the value of numbers in array C: \n");
    correct_enter(num_C, 1);

    float *A;
    FILE *file_read_A = fopen("vector4_6A.txt", "r");
    if (!file_read_A) {printf("Error: vector4_6A.txt not found");}
    create_vector(A, num_A);
    enter_vector_file(file_read_A, A, num_A);
    fprintf(out, "Vector A: \n");
    out_vector_file(out, A, num_A);
    
    float *B;
    FILE *file_read_B = fopen("vector4_6B.txt", "r");
    if (!file_read_B) {printf("Error: vector4_6B.txt not found");}
    create_vector(B, num_B);
    enter_vector_file(file_read_B, B, num_B);
    fprintf(out, "Vector B: \n");
    out_vector_file(out, B, num_B);

    float *C;
    FILE *file_read_C = fopen("vector4_6C.txt", "r");
    if (!file_read_C) {printf("Error: vector4_6C.txt not found");}
    create_vector(C, num_C);
    enter_vector_file(file_read_C, C, num_C);
    fprintf(out, "Vector C: \n");
    out_vector_file(out, C, num_C);

    float half_max_A = max_vector(A, num_A) / 2.0;

    float half_max_B = max_vector(B, num_B) / 2.0;

    float half_max_C = max_vector(C, num_C) / 2.0;

    int count_A;
    float *new_A = (float*)malloc(1 * sizeof(float));
    new_array(new_A, A, num_A, half_max_A, count_A);
    fprintf(out, "\nNew vector A: \n");
    out_vector_file(out, new_A, count_A);
    //защита
    new_array(new_A, A, num_A, half_max_A, count_A);
    fprintf(out, "\nNew vector A: \n");
    out_vector_file(out, new_A, count_A);

    int count_B;
    float *new_B = (float*)malloc(1 * sizeof(float));
    float *zero_arr_B = (float*)malloc(1 * sizeof(float));
    new_array(new_B, B, num_B, half_max_B, count_B);
    fprintf(out, "New vector B: \n");
    out_vector_file(out, new_B, count_B);

    int count_C;
    float *new_C = (float*)malloc(1 * sizeof(float));
    float *zero_arr_B = (float*)malloc(1 * sizeof(float));
    new_array(new_C, C, num_C, half_max_C, count_C);
    fprintf(out, "New vector C: \n");
    out_vector_file(out, new_C, count_C);
    //защита
    new_array(new_A, A, num_A, half_max_A, count_A);
    fprintf(out, "\nNew vector A: \n");
    out_vector_file(out, new_A, count_A);
    //защита
    bool zeroA = have_zero(A, num_A);
    if (zeroA) {
        int firstA = index_first_zero(A, num_A);
        int lastA = index_last_zero(A, num_A);
        if (lastA == firstA) {fprintf(out, "Only on zero in array A");}
        else {
            int count;
            float *zero_arr_A = (float*)malloc(1 * sizeof(float));
            array_zero(zero_arr_A, A, firstA, lastA, count);
            fprintf(out, "\nZero vector A: \n");
            out_vector_file(out, new_A, count_A);
            free(zero_arr_A);
        }
    }
    bool zeroB = have_zero(B, num_B);
    if (zeroB) {
        int firstB = index_first_zero(B, num_B);
        int lastB = index_last_zero(B, num_B);
        if (lastB == firstB) {fprintf(out, "Only on zero in array B");}
        else {
            int count;
            float *zero_arr_B = (float*)malloc(1 * sizeof(float));
            array_zero(zero_arr_B, A, firstB, lastB, count);
            fprintf(out, "\nZero vector C: \n");
            out_vector_file(out, new_B, count_B);
            free(zero_arr_B);
        }
    }
    bool zeroC = have_zero(C, num_C);
    if (zeroC) {
        int firstC = index_first_zero(C, num_C);
        int lastC = index_last_zero(C, num_C);
        if (lastC == firstC) {fprintf(out, "Only on zero in array C");}
        else {
            int count;
            float *zero_arr_C = (float*)malloc(1 * sizeof(float));
            array_zero(zero_arr_C, A, firstC, lastC, count);
            fprintf(out, "\nZero vector C: \n");
            out_vector_file(out, new_C, count_C);
            free(zero_arr_C);
        }
    }

    
    
    fclose(out);
    free(A);
    free(B);
    free(C);
    free(new_A);
    free(new_B);
    free(new_C);

    return 0;
}
