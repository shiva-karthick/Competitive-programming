#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <assert.h>

// Wishful thinking, breaking the problem down into smaller pieces

// Function to remove adjacent repeated letters
void removeAdjacentRepeatedLetters(char *word)
{
    int i, j;
    int len = strlen(word);

    for (i = 0, j = 1; j < len; j++)
    {
        if (word[i] != word[j])
        {
            i++;
            // printf("i : %d, %c\n", i, word[i]);
            word[i] = word[j];
            // printf("i : %d, %c\n", i, word[i]);
            // printf("---\n");
        }
    }

    word[i + 1] = '\0';
}

// Function to remove vowels except the first and last letter
void removeInnerVowels(char *word)
{
    int len = strlen(word);

    if (len <= 2)
    {
        // No inner vowels to remove in words of length 2 or less
        return;
    }

    int i, j;
    for (i = 1, j = 1; j < len - 1; j++)
    {
        if (strchr("aeiouAEIOU", word[j]) == NULL)
        {
            word[i] = word[j];
            i++;
        }
    }
    // printf("i : %d, j : %d\n", i, j);
    word[i] = word[j];
    word[i + 1] = '\0';
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);

    char **array = malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++)
    {
        array[i] = malloc(100 * sizeof(char));
        scanf("%s", array[i]);
    }
    // end of input

    // print out the char array
    for (int i = 0; i < n; i++)
    {
        char tmp[100];
        strcpy(tmp, array[i]);

        removeAdjacentRepeatedLetters(tmp);
        removeInnerVowels(tmp);

        printf("%s", tmp);
        if (i != n - 1)
        {
            printf(" ");
        }
    }

    return 0;
}
