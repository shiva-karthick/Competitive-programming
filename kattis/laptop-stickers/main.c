#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int cols, rows, stickers;
    scanf("%d %d %d", &cols, &rows, &stickers);

    char **array = malloc(rows * sizeof(int *));

    for (int i = 0; i < rows; i++)
    {
        array[i] = malloc(cols * sizeof(int));
        memset(array[i], '_', cols * sizeof(int));
    }

    char letter = 'a';

    for (int i = 0; i < stickers; i += 1)
    {

        int l, h, c, r;
        scanf("%d %d %d %d", &l, &h, &c, &r);

        for (int j = 0; j < rows; j += 1)
        {
            for (int k = 0; k < cols; k += 1)
            {
                if (j >= r && j < r + h && k >= c && k < c + l)
                {
                    array[j][k] = (char)letter;
                }
            }
        }
        letter += 1;
    }

    // print the array
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%c", array[i][j]);
        }
        printf("\n");
    }

    return 0;
}
