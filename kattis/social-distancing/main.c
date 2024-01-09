#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// helper function to check if a value is in an array
bool checkInArray(int *arr, int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    // read input
    int noChairs, noPeopleFilledUp;
    scanf("%d %d", &noChairs, &noPeopleFilledUp);

    int *chairs = malloc(sizeof(int) * noPeopleFilledUp);

    for (int i = 0; i < noPeopleFilledUp; i++)
    {
        scanf("%d", &chairs[i]);
    }
    // end read input

    int noFound = 0;
    for (int i = 1; i <= noChairs;)
    {
        if (checkInArray(chairs, noPeopleFilledUp, i)) // the current seat is filled up
        {
            i += 2;
            if (i > noChairs + 1)
            {
                break;
            }
        }
        else if (!checkInArray(chairs, noPeopleFilledUp, i - 1) && !checkInArray(chairs, noPeopleFilledUp, i + 1)) // left and right is empty
        {
            noFound += 1;

            noPeopleFilledUp += 1;
            chairs = realloc(chairs, sizeof(int) * noPeopleFilledUp);
            chairs[noPeopleFilledUp - 1] = i;

            i += 2;
            if (i > noChairs + 1)
            {
                break;
            }
        }
        else
        {
            i += 1;
            if (i > noChairs + 1)
            {
                break;
            }
        }
    }

    printf("%d\n", noFound);

    return 0;
}
