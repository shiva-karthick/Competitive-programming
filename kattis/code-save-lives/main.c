#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int combineDigits()
{
    char c;
    int combinedNumber = 0;

    // Read characters until a newline is encountered
    while (scanf("%c", &c) == 1 && c != '\n')
    {
        if (c >= '0' && c <= '9')
        {
            // If the character is a digit, combine it into the number
            combinedNumber = combinedNumber * 10 + (c - '0');
        }
    }

    return combinedNumber;
}

int main()
{
    int numTestCases;
    char buffer[1000];

    // Read the number of test cases
    scanf("%d", &numTestCases);

    // Consume the rest of the current line
    while (getchar() != '\n')
        ;

    for (int i = 0; i < numTestCases; i += 1)
    {
        // Read and combine digits for each line
        int combinedNumber1 = combineDigits();
        int combinedNumber2 = combineDigits();

        // printf("Combined numbers for testcase %d: %d %d\n", i + 1, combinedNumber1, combinedNumber2);

        int total = combinedNumber1 + combinedNumber2;

        // printf("Total: %d\n", total);

        // Determine the maximum number of digits (including the null terminator)
        int maxDigits = snprintf(NULL, 0, "%d", total) + 1;
        // printf("Max digits: %d\n", maxDigits);

        // Dynamically allocate memory for the string
        char *str = (char *)malloc(maxDigits * sizeof(char));

        if (str == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }

        // Convert the integer to a string
        sprintf(str, "%d", total);

        // Insert a space between each digit
        for (int i = 0; i < strlen(str); i += 1)
        {
            if (i == strlen(str) - 1)
            {
                printf("%c\n", str[i]);
            }
            else
            {
                printf("%c ", str[i]);
            }
        }

        // Don't forget to free the allocated memory
        free(str);
    }

    return 0;
}
