#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

struct digit
{
    int count;
    int number;
};

int main()
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char *s = "a11472o5t6";

    // Create an array of 10 digits:
    struct digit digits[10];

    // Initialize the array:
    for (int i = 0; i < 10; i += 1)
    {
        digits[i].count = 0;
        digits[i].number = i;
    }

    // Iterate through the string using a for loop:
    for (int i = 0; s[i] != '\0'; i += 1)
    {
        int temp = 0;
        if (isdigit(s[i]))
        {
            int temp = s[i] - '0';
            digits[temp].count += 1;
        }
    }

    // print the digits array:
    for (int i = 0; i < 10; i += 1)
    {
        printf("%d ", digits[i].count);
    }

    return 0;
}