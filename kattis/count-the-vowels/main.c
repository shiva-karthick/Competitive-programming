#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

  // Go through every char, check if the char is a alpha character. If so, check
  // if its a vowel, count += 1

  char c;
  int count = 0;
  while (scanf("%c", &c) != EOF) {
    if (strchr("aeiouAEIOU", c) != NULL) {
      count += 1;
    }
  }
  printf("%d\n", count);

  return 0;
}
