#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    char continent[14];
    char country[30];
    float population;
    float gpd;
} World;

void correct_enter(float &value, float num);
void to_bin(FILE* file, FILE* bin);
void sort(FILE* bin, int count);
void top40_richest(FILE* bin, FILE* out);
int count_countries(FILE* bin, float value);
