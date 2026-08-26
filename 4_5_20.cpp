//4.5.20

#include "library_miri4_5.h"

int main() {
    int num_A, num_B, num_C;
    FILE *out = fopen("out4_5.txt", "w");
    if (!out) {printf("Error: out4_5.txt not found");}

    printf("Enter the value of numbers in array A: \n");
    correct_enter(num_A, 1);
    printf("Enter the value of numbers in array B: \n");
    correct_enter(num_B, 1);
    printf("Enter the value of numbers in array C: \n");
    correct_enter(num_C, 1);

    int *A;
    FILE *file_read_A = fopen("vector4_5A.txt", "r");
    if (!file_read_A) {printf("Error: vector4_5A.txt not found");}
    create_vector(A, num_A);
    enter_vector_file(file_read_A, A, num_A);
    fprintf(out, "Vector A: \n");
    out_vector_file(out, A, num_A);
    
    int *B;
    FILE *file_read_B = fopen("vector4_5B.txt", "r");
    if (!file_read_B) {printf("Error: vector4_5B.txt not found");}
    create_vector(B, num_B);
    enter_vector_file(file_read_B, B, num_B);
    fprintf(out, "Vector B: \n");
    out_vector_file(out, B, num_B);

    int *C;
    FILE *file_read_C = fopen("vector4_5C.txt", "r");
    if (!file_read_C) {printf("Error: vector4_5C.txt not found");}
    create_vector(C, num_C);
    enter_vector_file(file_read_C, C, num_C);
    fprintf(out, "Vector C: \n");
    out_vector_file(out, C, num_C);

    bool uslA = not_multi_num(A, num_A, 5);
    bool uslB = not_multi_num(B, num_B, 5);
    bool uslC = not_multi_num(C, num_C, 5);
    
    if (uslA && !uslB && !uslC) {
        int delta_A = max_vector(A, num_A) - min_vector(A, num_A);
        fprintf(out, "\nThe array without values multiplicity 5 - A. Max - min in array = %d\n", delta_A);
        //здесь защита
        bool fl_A = have_neg(A, num_A);
        if (fl_A) {
            int sum_negA = abs_neg(A, num_A);
            fprintf(out, "\nTRUE: %d", sum_negA);
        }
        else {
            if (delta_A > 5) {fprintf(out, "\nTRUE: delta-A > 5");}
        }
    }
    else if (uslB && !uslA && !uslC) {
        int delta_B = max_vector(B, num_B) - min_vector(B, num_B);
        fprintf(out, "The array without values multiplicity 5 - B. Max - min in array = %d\n", delta_B);
        //здесь защита
        bool fl_B = have_neg(B, num_B);
        if (fl_B) {
            int sum_negB = abs_neg(B, num_B);
            fprintf(out, "\nTRUE: %d", sum_negB);
        }
        else {
            if (delta_B > 5) {fprintf(out, "\nTRUE: delta-B > 5");}
        }
    }
    else if (uslC && !uslB && !uslA) {
        int delta_C = max_vector(C, num_C) - min_vector(C, num_C);
        fprintf(out, "The array without values multiplicity 5 - C. Max - min in array = %d\n", delta_C);
        //здесь защита
        bool fl_C = have_neg(C, num_C);
        if (fl_C) {
            int sum_negC = abs_neg(C, num_C);
            fprintf(out, "\nTRUE: %d", sum_negC);
        }
        else {
            if (delta_C > 5) {fprintf(out, "\nTRUE: delta-C > 5");}
        }
    }
    else if (uslA && uslB && !uslC) {
        int delta_A = max_vector(A, num_A) - min_vector(A, num_A);
        int delta_B = max_vector(B, num_B) - min_vector(B, num_B);
        fprintf(out, "The arrays without values multiplicity 5 - A and B. Max - min in array A = %d, in array B = %d\n", delta_A, delta_B);
        //здесь защита
        bool fl_A = have_neg(A, num_A);
        bool fl_B = have_neg(B, num_B);
        if (fl_A && fl_B) {
            int sum_negA = abs_neg(A, num_A);
            int sum_negB = abs_neg(B, num_B);
            fprintf(out, "\nTRUE: %d, %d", sum_negA, sum_negB);
        }
        else {
            if (delta_A > 5) {fprintf(out, "\nTRUE: delta-A > 5");}
            if (delta_B > 5) {fprintf(out, "\nTRUE: delta-B > 5");}
        }
    }
    else if (uslA && uslC && !uslB) {
        int delta_A = max_vector(A, num_A) - min_vector(A, num_A);
        int delta_C = max_vector(C, num_C) - min_vector(C, num_C);
        fprintf(out, "The arrays without values multiplicity 5 - A and C. Max - min in array A = %d, in array C = %d\n", delta_A, delta_C);
        //здесь защита
        bool fl_A = have_neg(A, num_A);
        bool fl_C = have_neg(C, num_C);
        if (fl_A && fl_C) {
            int sum_negA = abs_neg(A, num_A);
            int sum_negC = abs_neg(C, num_C);
            fprintf(out, "\nTRUE: %d, %d", sum_negA, sum_negC);
        }
        else {
            if (delta_A > 5) {fprintf(out, "\nTRUE: delta-A > 5");}
            if (delta_C > 5) {fprintf(out, "\nTRUE: delta-C > 5");}
        }
    }
    else if (uslB && uslC && !uslA) {
        int delta_B = max_vector(B, num_B) - min_vector(B, num_B);
        int delta_C = max_vector(C, num_C) - min_vector(C, num_C);
        fprintf(out, "The arrays without values multiplicity 5 - B and C. Max - min in array B = %d, in array C = %d\n", delta_B, delta_C);
        //здесь защита
        bool fl_B = have_neg(B, num_B);
        bool fl_C = have_neg(C, num_C);
        if (fl_B && fl_C) {
            int sum_negB = abs_neg(B, num_B);
            int sum_negC = abs_neg(C, num_C);
            fprintf(out, "\nTRUE: %d, %d", sum_negB, sum_negC);
        }
        else {
            if (delta_B > 5) {fprintf(out, "\nTRUE: delta-B > 5");}
            if (delta_C > 5) {fprintf(out, "\nTRUE: delta-C > 5");}
        }
        
    }
    else if (uslA && uslB && uslC) {
        int delta_A = max_vector(A, num_A) - min_vector(A, num_A);
        int delta_B = max_vector(B, num_B) - min_vector(B, num_B);
        int delta_C = max_vector(C, num_C) - min_vector(C, num_C);
        fprintf(out, "The arrays without values multiplicity 5 - A, B, C. Max - min in array A = %d, in array B = %d, in array C = %d\n", delta_A, delta_B, delta_C);
        //здесь защита
        bool fl_A = have_neg(A, num_A);
        bool fl_B = have_neg(B, num_B);
        bool fl_C = have_neg(C, num_C);
        if (fl_A && fl_B && fl_C) {
            int sum_negA = abs_neg(A, num_A);
            int sum_negB = abs_neg(B, num_B);
            int sum_negC = abs_neg(C, num_C);
            fprintf(out, "\nTRUE: %d, %d, %d", sum_negA, sum_negB, sum_negC);
        }
        else {
            if (delta_A > 5) {fprintf(out, "\nTRUE: delta-A > 5");}
            if (delta_B > 5) {fprintf(out, "\nTRUE: delta-B > 5");}
            if (delta_C > 5) {fprintf(out, "\nTRUE: delta-C > 5");}
        }

    }
    else {fprintf(out, "\nAll the arrays with values multiplicity 5\n");}

    fclose(out);
    free(A);
    free(B);
    free(C);
    
    return 0;
}

//если все элементы некратны 5, то посчитать модуль суммы отриц элем, если они есть, если их нет, то проверить больше ли разность max и min больше некоторго числа.