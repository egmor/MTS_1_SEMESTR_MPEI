#include "library_miri6_3.h"

void correct_enter(float &value, float num) { 
    scanf("%f", &value); 
    while (value < num) { 
        printf("Input error! Enter the value >= %.f: ", num); 
        scanf("%f", &value); 
    } 
    return; 
} 

void to_bin(FILE* file, FILE* bin) {
    World countries;
    while (fscanf(file, "%13s %29s %f %f", 
        countries.continent,
        countries.country,
        &countries.population,
        &countries.gpd) == 4) {
        fwrite(&countries, sizeof(World), 1, bin);
        fscanf(file, "%*[^\n]");
    }
    return;
}

void sort(FILE* bin, int count) {
    bool swapped = true;
    int i = 0;
    World country1, country2;
    
    while (i < count && swapped) {
        swapped = false;
        for (int j = 0; j < count - i - 1; j++) {
            fseek(bin, j * sizeof(World), SEEK_SET);
            fread(&country1, sizeof(World), 1, bin);
            fread(&country2, sizeof(World), 1, bin);
            if (country1.gpd < country2.gpd) {
                fseek(bin, j * sizeof(World), SEEK_SET);
                fwrite(&country2, sizeof(World), 1, bin);
                fwrite(&country1, sizeof(World), 1, bin);
                swapped = true;
            }
        }
        if (swapped) { i++; }
    }
    return;
}

void top40_richest(FILE* bin, FILE* out) {
    char continent[14], country[30];
    float population, gpd;
    for (int i = 1; i < 41; i++) {
        fread(continent, sizeof(continent), 1, bin);
        fread(country, sizeof(country), 1, bin);
        fread(&population, sizeof(population), 1, bin);
        fread(&gpd, sizeof(gpd), 1, bin);
        fprintf(out, "%2d Place: %29s| Continent: %13s| Population (per millions people): %7.4f| GPD (per billions USD): %7.4f|\n",
                i, country, continent, population, gpd);
    }
    return;
}

int count_countries(FILE* bin, float value) {
    World country;
    int count = 0;
    fseek(bin, 0, SEEK_SET);
    
    while (fread(&country, sizeof(World), 1, bin)) {
        if (country.population > value) {
            count++;
        }
    }
    
    fseek(bin, 0, SEEK_SET);
    return count;
}
