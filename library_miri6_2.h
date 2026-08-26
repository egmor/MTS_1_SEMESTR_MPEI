#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

void to_text(FILE* read, char* &text, int &size);
void get_word(const char* text, int size, int &start, char* &word);
bool in_list(const char* word, char** list, int count);
void add_word_to_list(char* word, char** &list, int &count, int &capacity);
void lower(char* &word);
void increased_capacity(char* &text, int len, int size, int &capacity);
void changed_text(const char* text, int size, char* &new_text, int &new_size, char** &used_word, int &word_count);
//защита
int count_glas(const char* word);
void sort_word(char** &list, int count);
void out_sorted(char** list, int count, FILE* out);