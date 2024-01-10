#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int w;
  scanf("%d", &w);

  if (w == 2) {
    printf("NO");
  } else if (w % 2) {
    // Odd number
    printf("NO");
  } else {
    printf("YES");
  }
}
