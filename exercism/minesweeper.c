
#include "../header-files/common.h"

int isNullTerminated(const char *str)
{
    if (str == NULL)
    {
        // Handle the case where the pointer is NULL
        return 0;
    }

    // Iterate through the characters until the null character is encountered
    for (int i = 0; str[i] != '\0'; i++)
    {
        // If we reach the end of the string without finding '\0', it is not null-terminated
        if (i == 255)
        { // Set a maximum length to prevent infinite loops
            return 0;
        }
    }

    // If the loop completes, the string is null-terminated
    return 1;
}

char **annotate(const char **minefield, const size_t rows)
{
    if (rows == 0)
        return NULL;
    char **annotated = calloc(rows + 1, sizeof(*annotated));

    size_t row_len = strlen(minefield[0]);
    for (size_t row = 0; row < rows; row++)
        annotated[row] = calloc(row_len + 1, sizeof(char)); /* Rememeber to include the NULL terminating character */

    for (size_t row = 0; row < rows; row++)
    {
        for (size_t col = 0; col < row_len; col++)
        {
            annotated[row][col] = minefield[row][col];
            if (minefield[row][col] == '*')
                continue;
            size_t mines = 0;
            for (int inc_x = -1; inc_x <= 1; inc_x++)
            {
                size_t x = row + inc_x;

                if (x >= rows)
                    continue;
                for (int inc_y = -1; inc_y <= 1; inc_y++)
                {
                    size_t y = col + inc_y;

                    if (y >= row_len)
                        continue;
                    if (minefield[x][y] == '*')
                        mines++;
                }
            }
            if (mines > 0)
                annotated[row][col] = mines + '0';
        }
    }
    return annotated;
}

void free_annotation(char **annotation)
{
    // Used for showing the matrix on screen
    for (int i = 0; annotation[i] != NULL; i++)
    {
        printf("%s\n", annotation[i]);
    }
}

int main(int argc, char const *argv[])
{
    const char *minefield_1[] = {
        " *  * ",
        "  *   ",
        "    * ",
        "   * *",
        " *  * ",
        "      "};
    const char *expected[] = {

        "1*22*1",
        "12*322",
        " 123*2",
        "112*4*",
        "1*22*2",
        "111111"

    };

    /* char **actual = annotate(minefield_1, LEN(minefield_1));
    free_annotation(actual); */

    char **actual = annotate(minefield_1, LEN(minefield_1));
    for (int i = 0; actual[i] != NULL; i++)
    {
        printf("%s\n", actual[i]);
    }

    return 0;
}
