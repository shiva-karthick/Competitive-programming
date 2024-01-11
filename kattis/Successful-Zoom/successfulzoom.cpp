#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <assert.h>

int main(int argc, char const *argv[])
{
    // read input
    int n;
    scanf("%d", &n);

    int *array = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    // end read input

    // find the longest increasing subsequence
    int k = 1; // For even numbers, k >= (n / 2) + 1, when n = 7, "Abort"
               // For even numbers, k >= (n / 2) + 1, when n = 8, "Abort"

    int pair = 0;
    bool check = false;

    // try for every number from k = 1 to k >= (n / 2) + 1
    while (k < (n / 2) + 1)
    {
        for (int i = k - 1; i < n; i += k)
        {
            // check for array out of bounds error
            if (i + k >= n)
            {
                break;
            }
            if (array[i] < array[i + k])
            {
                check = true;
                pair += 1;
            }
            else if (array[i] > array[i + k])
            {
                check = false;
                break;
            }
        }
        if (check)
        {
            printf("%d\n", k);
            break;
        }
        k += 1;
    }
    if (k >= (n / 2) + 1)
    {
        printf("ABORT!\n");
    }

    return 0;
}