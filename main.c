#include "memo.c"
#include "money_to_words.c"

int main() {
  load_cache(); // Load cache from file at the start

  long cents;
  char output[1000];

  printf("Enter an amount in cents (press Ctrl+D to exit):\n");

  // Take input until EOF (Ctrl+D / Ctrl+Z)
  while (scanf("%ld", &cents) == 1) {
    money_to_words(cents, output);
    printf("%s\n", output);
  }

  printf("\nFin\n");
  return 0;
}
