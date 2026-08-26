#include "library_miri6_2.h"

void to_text(FILE* read, char* &text, int &size) {
    size = 0;
    int capacity = 0;
    text = NULL;
    int sym;

    while ((sym = fgetc(read)) != EOF) {
        if (size + 1 >= capacity) {
            if (capacity) {capacity *= 2;}
            else {capacity = 16;}
            text = (char*)realloc(text, capacity * sizeof(char));
        }
        text[size++] = (char)sym;
    }

    if (size + 1 >= capacity) {
        capacity = size + 1;
        text = (char*)realloc(text, capacity * sizeof(char));
    }
    text[size] = '\0';
    return;
}

void get_word(const char* text, int size, int &start, char* &word) {
    while (start < size && !isalpha(text[start])) {start++;}
    int word_start = start;
    
    while (start < size && isalpha(text[start])) {start++;}
    
    int word_length = start - word_start;
    
    word = (char*)realloc(word, (word_length + 1) * sizeof(char));
    
    for (int i = 0; i < word_length; i++) {
        word[i] = text[word_start + i];
    }
    word[word_length] = '\0';
    
    return;
}

bool in_list(const char* word, char** list, int count) {
    bool flag = false;
    int i = 0;
    while (i < count && !flag) {
        if (!strcmp(list[i], word)) {flag = true;}
        else {i++;}
    }
    return flag;
}

void add_word_to_list(char* word, char** &list, int &count, int &capacity) {
    if (count >= capacity) {
        if (capacity) {capacity *= 2;}
        else {capacity = 10;}
        list = (char**)realloc(list, capacity * sizeof(char*));
    }
    list[count] = word;
    count++;
    
    return;
}

void lower(char* &word) {
    for (int i = 0; word[i] != '\0'; i++) {word[i] = tolower(word[i]);}
    return;
}

void increased_capacity(char* &text, int len, int size, int &capacity) {
    if (size + len + 1 >= capacity) {
        while (size > capacity) {
            if (capacity) {capacity *= 2;}
            else {capacity = 1;}
        }
        text = (char*)realloc(text, capacity * sizeof(char));
    }
    return;
}

void changed_text(const char* text, int size, char* &new_text, int &new_size, char** &used_word, int &word_count) {
    new_size = 0;
    int text_capacity = 1;
    new_text = (char*)malloc(text_capacity * sizeof(char));
    new_text[0] = '\0';
    
    int word_capacity = 0;
    
    int i = 0;
    bool first_word = true;
    
    while (i < size) {
        char* word = NULL;
        get_word(text, size, i, word);
        char* buffer = (char*)malloc((strlen(word) + 1) * sizeof(char));
        strcpy(buffer, word);
        lower(buffer);
        
        if (!in_list(buffer, used_word, word_count)) {
            add_word_to_list(buffer, used_word, word_count, word_capacity);
            
            int word_len = strlen(buffer);

            increased_capacity(new_text, word_len, new_size + word_len + 2, text_capacity);
            
            memcpy(new_text + new_size, word, word_len);
            new_size += word_len;
            new_text[new_size++] = ' ';
            new_text[new_size] = '\0';
            
        }
        else {
            free(word);
            free(buffer);
        }
        
    }
    return;
}

//отсортировать слова в порядке убывания кол-ва гласных

int count_glas(const char* word) {
    char* buffer = (char*)malloc((strlen(word) + 1) * sizeof(char));
    strcpy(buffer, word);
    lower(buffer);
    int word_len = strlen(word);
    int count = 0;
    for (int i = 0; i < word_len; i++) {
        if (buffer[i] == 'a' || buffer[i] == 'e' || buffer[i] == 'y' || buffer[i] == 'u' || buffer[i] == 'i' || buffer[i] == 'o') {count++;}
    }
    free(buffer);
    return count;
} 

void sort_word(char** &list, int count) {
    bool swapped = true;
    int i = 0;

    while (i < count && swapped) {
        swapped = false;
        for (int j = 0; j < count - i - 1; j++) {
            if (count_glas(list[j]) < count_glas(list[j + 1])) {
                char* buffer = list[j];
                list[j] = list[j + 1];
                list[j + 1] = buffer;
                swapped = true;
            }
        }
        if (swapped) {i++;}
    }
    return;
}

void out_sorted(char** list, int count, FILE* out) {
    for (int i = 0; i < count; i++) {fprintf(out, "%s ", list[i]);}
    for (int i = 0; i < count; i++) {free(list[i]);}
    free(list);
    return;
}