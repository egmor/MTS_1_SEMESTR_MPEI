//4.4.20

#include "library_miri4_4.h"

int main() {
    int num_A, num_B, num_C;
    FILE *out = fopen("out4_4.txt", "w");
    if (!out) {printf("Error: out4_4.txt not found");}

    printf("Enter the value of numbers in array A: \n");
    correct_enter(num_A, 1);
    printf("Enter the value of numbers in array B: \n");
    correct_enter(num_B, 1);
    printf("Enter the value of numbers in array C: \n");
    correct_enter(num_C, 1);

    float *A;
    FILE *file_read_A = fopen("vector4_4A.txt", "r");
    if (!file_read_A) {printf("Error: vector4_4A.txt not found");}
    create_vector(A, num_A);
    enter_vector_file(file_read_A, A, num_A);
    fprintf(out, "Vector A: \n");
    out_vector_file(out, A, num_A);
    
    float *B;
    FILE *file_read_B = fopen("vector4_4B.txt", "r");
    if (!file_read_B) {printf("Error: vector4_4B.txt not found");}
    create_vector(B, num_B);
    enter_vector_file(file_read_B, B, num_B);
    fprintf(out, "Vector B: \n");
    out_vector_file(out, B, num_B);

    float *C;
    FILE *file_read_C = fopen("vector4_4C.txt", "r");
    if (!file_read_C) {printf("Error: vector4_4C.txt not found");}
    create_vector(C, num_C);
    enter_vector_file(file_read_C, C, num_C);
    fprintf(out, "Vector C: \n");
    out_vector_file(out, C, num_C);

    float min_A = min_vector(A, num_A);
    float min_B = min_vector(B, num_B);
    float min_C = min_vector(C, num_C);

    if (min_A > min_B && min_A > min_C) {fprintf(out, "\nArray A [%7.4f]\n", min_A);}
    else if (min_B > min_A && min_B > min_C) {fprintf(out, "\nArray B [%7.4f]\n", min_B);}
    else if (min_C > min_A && min_C > min_B) {fprintf(out, "\nArray C [%7.4f]\n", min_C);}
    else if (min_A == min_B && min_A > min_C) {fprintf(out, "\nMinimun in array A and B equal [%7.4f]\n", min_A);}
    else if (min_A == min_C && min_A > min_B) {fprintf(out, "\nMinimun in array A and C equal [%7.4f]\n", min_A);}
    else if (min_B == min_C && min_B > min_C) {fprintf(out, "\nMinimun in array B and C equal [%7.4f]\n", min_B);}
    else {fprintf(out, "\nAll minimum in arrays equal [%7.4f]\n", min_A);}

    if (count_zero(A, num_A) && count_zero(B, num_B) && count_zero(C, num_C)) {
        int index_A = index_last_zero(A, num_A);
        int index_B = index_last_zero(B, num_B);
        int index_C = index_last_zero(C, num_C);

        float min_after_A = min_after(A, num_A, index_A);
        float min_after_B = min_after(B, num_B, index_B);
        float min_after_C = min_after(C, num_C, index_C);

        if (min_after_A < min_after_B && min_after_A < min_after_C) {fprintf(out, "\nArray A [%7.4f]\n", min_after_A);}
        else if (min_after_B < min_after_A && min_after_B < min_after_C) {fprintf(out, "\nArray B [%7.4f]\n", min_after_B);}
        else if (min_after_C < min_after_A && min_after_C < min_after_B) {fprintf(out, "\nArray C [%7.4f]\n", min_after_C);}
        else if (min_after_A == min_after_B && min_after_A < min_after_C) {fprintf(out, "\nMinimun in array A and B equal [%7.4f]\n", min_after_A);}
        else if (min_after_A == min_after_C && min_after_A < min_after_B) {fprintf(out, "\nMinimun in array A and C equal [%7.4f]\n", min_after_A);}
        else if (min_after_B == min_after_C && min_after_B < min_after_C) {fprintf(out, "\nMinimun in array B and C equal [%7.4f]\n", min_after_B);}
        else {fprintf(out, "\nAll minimum in arrays equal [%7.4f]\n", min_after_A);}
    }
    else if (count_zero(A, num_A) && count_zero(B, num_B) && !count_zero(C, num_C)) {
        int index_A = index_last_zero(A, num_A);
        int index_B = index_last_zero(B, num_B);

        float min_after_A = min_after(A, num_A, index_A);
        float min_after_B = min_after(B, num_B, index_B);

        if (min_after_A < min_after_B) {fprintf(out, "\nArray A [%7.4f]\n", min_after_A);}
        else if (min_after_B < min_after_A) {fprintf(out, "\nArray B [%7.4f]\n", min_after_B);}
        else if (min_after_A == min_after_B) {fprintf(out, "\nMinimun in array A and B equal [%7.4f]\n", min_after_A);}
    }
    else if (count_zero(A, num_A) && !count_zero(B, num_B) && count_zero(C, num_C)) {
        int index_A = index_last_zero(A, num_A);
        int index_C = index_last_zero(C, num_C);

        float min_after_A = min_after(A, num_A, index_A);
        float min_after_C = min_after(C, num_C, index_C);

        if (min_after_A < min_after_C) {fprintf(out, "\nArray A [%7.4f]\n", min_after_A);}
        else if (min_after_C < min_after_A) {fprintf(out, "\nArray B [%7.4f]\n", min_after_C);}
        else if (min_after_A == min_after_C) {fprintf(out, "\nMinimun in array A and C equal [%7.4f]\n", min_after_A);}
    }
    else if (!count_zero(A, num_A) && count_zero(B, num_B) && count_zero(C, num_C)) {
        int index_B = index_last_zero(B, num_B);
        int index_C = index_last_zero(C, num_C);

        float min_after_B = min_after(B, num_B, index_B);
        float min_after_C = min_after(C, num_C, index_C);

        if (min_after_B < min_after_C) {fprintf(out, "\nArray A [%7.4f]\n", min_after_B);}
        else if (min_after_C < min_after_B) {fprintf(out, "\nArray B [%7.4f]\n", min_after_C);}
        else if (min_after_B == min_after_C) {fprintf(out, "\nMinimun in array B and C equal [%7.4f]\n", min_after_B);}
    }
    else {fprintf(out, "\nAll array hasn't 0 values");}
    

    fclose(out);
    free(A);
    free(B);
    free(C);

    return 0;
}