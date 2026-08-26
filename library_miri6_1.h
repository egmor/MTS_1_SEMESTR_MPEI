#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <io.h>

typedef struct {
    char group[8];
    char name[20];
    char surname[30];
    char lastname[30];
    int year_birth;
    bool gender;
    short int grade_fiz;
    short int grade_math;
    short int grade_it;
    float scholarship;
} Students;

void to_bin(FILE* file, FILE* bin);
int check(char group_name[20], FILE* bin_read, FILE* bin_out);
void file_out(FILE* bin, FILE* out);

//удалить всех троичников
void copybin(FILE* bin_read, FILE* bin_out);
int del_student(FILE* bin_read, FILE* bin_out);
void out_out(FILE* bin, FILE* out);