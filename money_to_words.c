#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Converts number to words
void number_to_words(long num, char *buffer) {
  if (num == 0) {
    strcpy(buffer, "zero");
    return;
  }

  buffer[0] = '\0';
  int group = 0;
  char temp[1000];

  while (num > 0) {
    if (num % 1000 != 0) {
      char part[200] = "";
      int n = num % 1000;
      if (n >= 100) {
        strcat(part, ones[n / 100]);
        strcat(part, " hundred ");
        n %= 100;
      }
      if (n >= 20) {
        strcat(part, tens[n / 10]);
        strcat(part, " ");
        n %= 10;
      }
      if (n > 0) {
        strcat(part, ones[n]);
      }
      if (group > 0) {
        strcat(part, " ");
        strcat(part, thousands[group]);
      }
      sprintf(temp, "%s %s", part, buffer);
      strcpy(buffer, temp);
    }
    num /= 1000;
    group++;
  }
}

// Converts input in cents to words
void money_to_words(long cents, char *result) {
  if (cents <= CACHE_LIMIT && cache[cents] != NULL) { // Check cache
    strcpy(result, cache[cents]);
    return;
  }

  long dollars = cents / 100;
  int remaining_cents = cents % 100;
  char dollar_part[1000] = "";
  char cent_part[500] = "";

  number_to_words(dollars, dollar_part);
  number_to_words(remaining_cents, cent_part);

  sprintf(result, "%ld = %s dollars and %s cents", cents, dollar_part,
          cent_part);

  // Store result
  if (cents <= CACHE_LIMIT) {
    cache[cents] = strdup(result);
    save_cache_entry(cents, result);
  }
}
