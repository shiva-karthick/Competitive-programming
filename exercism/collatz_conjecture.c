#include "../header-files/common.h"

int steps(int start)
{
    int steps = 0;
    // Edge case
    if (start == 1)
        return 0;
    if (start == 0 || start < 0)
        return -1;

    while (start != 1)
    {
        if (start % 2 == 0) // even
        {
            start = start / 2;
            steps += 1;
        }
        else if (start % 2 == 1) // odd
        {
            start = (3 * start) + 1;
            steps += 1;
        }
    }
    return steps;
}

int main(int argc, char const *argv[])
{
    printf("Steps: %d\n", steps(-15));
    return 0;
}
