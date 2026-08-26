#include "library_miri6_3.h"

int main() {
    FILE *file_read, *out, *bin;
    float value;
    printf("Input the value of population per millions people: \n");
    correct_enter(value, 0);

    file_read = fopen("read6_3.txt", "r");
    if (!file_read) {printf("Error! File read6_3.txt not found\n"); return 1;}
    
    bin = fopen("read_bin_6_3.bin", "wb");
    if (!bin) {printf("Error! File read_bin_6_3.bin not found\n"); return 1;}

    to_bin(file_read, bin);
    fclose(file_read);
    
    fclose(bin);
    bin = fopen("read_bin_6_3.bin", "rb+");
    if (!bin) {printf("Error! File read_bin_6_3.bin not found\n"); return 1;}
    
    fseek(bin, 0, SEEK_END);
    int record_count = ftell(bin) / sizeof(World);
    fseek(bin, 0, SEEK_SET);
    
    sort(bin, record_count);
    
    out = fopen("out6_3.txt", "w");
    if (!out) {printf("Error! File out6_3.txt not found\n"); return 1;}
    
    fseek(bin, 0, SEEK_SET);
    
    int out_num = count_countries(bin, value);
    
    fseek(bin, 0, SEEK_SET);
    
    fprintf(out, "The number of countries with population bigger than %6.2f millions: %3d\n", value, out_num);
    fprintf(out, "\nTOP 40 RICHEST COUNTRIES: \n");
    top40_richest(bin, out);
    
    fclose(out);
    fclose(bin);
    return 0;
}