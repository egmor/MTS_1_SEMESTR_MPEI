#include "library_miri6_2.h"

int main() {
    char *or_text = NULL, *result_text = NULL;
    int size = 0, new_size = 0;
    char** all_word = NULL;
    int word_count = 0;

    FILE *file_read = fopen("read6_2.txt", "r");
    if (!file_read) {
        printf("Error: read6_2.txt not found\n");
    }

    FILE *out = fopen("out6_2.txt", "w");
    if (!out) {
        printf("Error: out6_2.txt not found\n");
    }

    to_text(file_read, or_text, size);
    fprintf(out, "The original text:\n%s\n\n", or_text);

    changed_text(or_text, size, result_text, new_size, all_word, word_count);

    sort_word(all_word, word_count);
    fprintf(out, "Sorted word: \n");
    out_sorted(all_word, word_count, out);

    fprintf(out, "\n\nThe result text:\n%s\n\n", result_text);

    free(or_text);
    free(result_text);
    
    fclose(file_read);
    fclose(out);
    
    return 0;
}