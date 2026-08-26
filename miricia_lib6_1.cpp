#include "library_miri6_1.h"

void to_bin(FILE* file, FILE* bin) {
    Students person;
    while (fscanf(file, "%s %s %s %s %d %d %hd %hd %hd %f", 
        person.group,
        person.name,
        person.surname,
        person.lastname,
        &person.year_birth,
        &person.gender, 
        &person.grade_fiz,
        &person.grade_math,
        &person.grade_it,
        &person.scholarship) == 10) {
        fwrite(&person, sizeof(Students), 1, bin);
        fscanf(file, "%*[^\n]");
    }
    return;
}

int check(char group_name[20], FILE* bin_read, FILE* bin_out) {
    Students person;
    int count = 0;
    while (fread(&person, sizeof(Students), 1, bin_read)) {
        if (!(strcmp(person.group, group_name)) && (person.grade_fiz < 4 || person.grade_math < 4 || person.grade_it < 4)){
            person.scholarship = 0;
            fwrite(person.name, sizeof(person.name), 1, bin_out);
            fwrite(person.surname, sizeof(person.surname), 1, bin_out);
            fwrite(person.lastname, sizeof(person.lastname), 1, bin_out);
            fwrite(&person.grade_fiz, sizeof(person.grade_fiz), 1, bin_out);
            fwrite(&person.grade_math, sizeof(person.grade_math), 1, bin_out);
            fwrite(&person.grade_it, sizeof(person.grade_it), 1, bin_out);
            count++;
        }
    }
    return count;
}

void file_out(FILE* bin, FILE* out) {
    char name[20], surname[30], lastname[30];
    short int grade_fiz, grade_math, grade_it;
    while (fread(name, sizeof(name), 1, bin) == 1) {
        fread(surname, sizeof(surname), 1, bin);
        fread(lastname, sizeof(lastname), 1, bin);
        fread(&grade_fiz, sizeof(grade_fiz), 1, bin);
        fread(&grade_math, sizeof(grade_math), 1, bin);
        fread(&grade_it, sizeof(grade_it), 1, bin);
        fprintf(out, "\nFull name: %19s| %29s| %29s| grade physics: %d| grade math: %d| grade IT: %d|",
            name, surname, lastname, grade_fiz, grade_math, grade_it);
    }
    return;
}



//удалить всех троичников

void copybin(FILE* bin_read, FILE* bin_out) {
    Students stud;
    fseek(bin_read, 0, SEEK_SET);
    fseek(bin_out, 0, SEEK_SET);
    while (fread(&stud, sizeof(Students), 1, bin_read) == 1) {
        fwrite(&stud, sizeof(Students), 1, bin_out);
    }
}

int del_student(FILE* bin_read, FILE* bin_out) {
    copybin(bin_read, bin_out);
    fseek(bin_out, 0, SEEK_SET);
    Students person;
    int count_del = 0;
    long write_pos = 0;
    long read_pos;
    while (fread(&person, sizeof(Students), 1, bin_out) == 1) {
        read_pos = ftell(bin_out); 
        if (person.grade_fiz < 4 || person.grade_math < 4 || person.grade_it < 4) {count_del++;}
        else {
            if (write_pos != (read_pos - sizeof(Students))) {
                fseek(bin_out, write_pos, SEEK_SET);
                fwrite(&person, sizeof(Students), 1, bin_out);
                fseek(bin_out, read_pos, SEEK_SET);
            }
            write_pos += sizeof(Students);
        }
    }
    int fd = _fileno(bin_out);
    _chsize(fd, write_pos);

    return count_del;
}

void out_out(FILE* bin, FILE* out) {
    Students person;
    while (fread(&person, sizeof(person), 1, bin) == 1) {
        fprintf(out, "\nFull name: %19s| %29s| %29s| Year birth: %4d| Gender: %d| grade physics: %d| grade math: %d| grade IT: %d| Scholarship: %8.2f|",
            person.name, 
            person.surname, 
            person.lastname, 
            person.year_birth, 
            person.gender, 
            person.grade_fiz, 
            person.grade_math, 
            person.grade_it, 
            person.scholarship);
    }
    return;
}