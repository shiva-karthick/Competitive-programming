#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    char *string1 = calloc(4, sizeof(char));
    char *string2 = calloc(4, sizeof(char));

    scanf("%s", string1);
    scanf(" %s", string2);

    int count = 0;
    for (int i = 0; i < 4; i += 1)
    {
        if (string1[i] != string2[i])
        {
            count += 1;
        }
    }

    printf("%d \n", (int)pow(2, count));

    return 0;
}
