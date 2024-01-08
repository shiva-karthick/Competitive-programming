#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char c;
    int total = 0;
    int count = 0;

    // Read characters until the newline character is encountered
    while (scanf("%c", &c) == 1 && c != '\n')
    {
        // Process each character as needed
        // printf("Read character: %c\n", c);
        total += (int)c;
        // printf("Total: %d\n", total);
        count += 1;
        // printf("Count: %d\n", count);
    }

    printf("%c\n", total / count);

    return 0;
}
