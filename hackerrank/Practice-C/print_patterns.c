#include "/home/shankar/Shiva/Competitive-programming/header-files/common.h"

int main()
{
    static const int n = 5;
    static const int levels = n - 1;         /* 4 levels */
    static const int rows = n + (n - 1);     /* 9 rows */
    static const int row_size = n + (n - 1); /* 9 columns */

    int nn = n;
    int iterations = row_size;

    int matrix[rows][row_size];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < row_size; j++)
        {
            matrix[i][j] = 0;
        }
    }

    /* printf("levels: %d\n", levels); */
    for (int l = 0; l < levels; l += 1)
    {

        for (int i = 0 + l; i < iterations; i += 1)
        {
            matrix[iterations - 1][i] = nn;
            printf("%d %d\n", iterations - 1, i);
        }
        for (int i = 0 + l; i < iterations; i += 1)
        {
            matrix[l][i] = nn;
        }
        for (int i = 0; i < iterations - l; i += 1)
        {
            matrix[i + l][iterations - 1] = nn;
        }
        for (int i = 0; i < iterations - l; i += 1)
        {
            matrix[iterations - 1 - i][l] = nn;
        }

        /* place in the 1 */
        matrix[(rows - 1) / 2][(rows - 1) / 2] = 1;

        /* printf("iterations: %d\n", iterations); */
        iterations -= 1;
        nn -= 1;
    }

    for (int i = 0; i < rows; i += 1)
    {
        for (int j = 0; j < row_size; j += 1)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
