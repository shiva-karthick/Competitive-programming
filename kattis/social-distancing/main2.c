#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    // read input
    int s, n;
    scanf("%d %d", &s, &n);

    int *seats = calloc(s, sizeof(int));
    int *not_empty = calloc(n, sizeof(int));

    for (int i = 0; i < n; i += 1)
    {
        scanf("%d", &not_empty[i]);
    }
    // end read input

    // fill up the seats
    for (int i = 0; i < n; i += 1)
    {
        seats[not_empty[i] - 1] = 1;
    }

    // for (int i = 0; i < s; i += 1)
    // {
    //     printf("%d", seats[i]);
    // }

    int count = 0;

    for (int i = 0; i < s; i += 1)
    {
        if (i == 0)
        {
            if ((seats[i + 1] == 0) && (seats[i] != 1) && (seats[s - 1] != 1))
            {
                count += 1;
                seats[i] = 1;
            }
        }
        else if (i == s - 1)
        {
            if ((seats[i] == 0) && (seats[i - 1] != 1) && (seats[0] != 1))
            {
                count += 1;
                seats[i] = 1;
            }
        }
        else
        {
            if ((seats[i] == 0) && (seats[i - 1] != 1) && (seats[i + 1] != 1))
            {
                count += 1;
                seats[i] = 1;
            }
        }
    }

    printf("%d\n", count);
    return 0;
}