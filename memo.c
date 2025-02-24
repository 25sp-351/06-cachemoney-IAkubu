#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CACHE_LIMIT 150000
#define CACHE_FILE "cache.txt"

// Memo
char *cache[CACHE_LIMIT + 1] = {NULL};

// Number to word mappings
const char *ones[] = {"",        "one",       "two",      "three",
                      "four",    "five",      "six",      "seven",
                      "eight",   "nine",      "ten",      "eleven",
                      "twelve",  "thirteen",  "fourteen", "fifteen",
                      "sixteen", "seventeen", "eighteen", "nineteen"};
const char *tens[] = {"",      "",      "twenty",  "thirty", "forty",
                      "fifty", "sixty", "seventy", "eighty", "ninety"};
const char *thousands[] = {"", "thousand", "million", "billion"};

// Function to load cache from file
void load_cache() {
    FILE *file = fopen(CACHE_FILE, "r");
    if (!file)
        return;

    long key;
    char value[500];
    while (fscanf(file, "%ld = %[^\n]\n", &key, value) == 2) {
        if (key <= CACHE_LIMIT) {
            cache[key] = strdup(value);
        }
    }
    fclose(file);
}

// Function to save to the cache file
void save_cache_entry(long key, const char *value) {
    FILE *file = fopen(CACHE_FILE, "a"); // Append mode to add new entries
    if (!file)
        return;

    fprintf(file, "%ld = %s\n", key, value);
    fclose(file);
}
