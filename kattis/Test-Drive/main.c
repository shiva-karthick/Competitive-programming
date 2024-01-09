#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int a, b, c;
    scanf(" %d %d %d", &a, &b, &c);

    if (((b - a) * (c - b)) < 0)
    {
        printf("turned\n");
    }
    else if (abs(b - a) == abs(c - b))
    {
        printf("cruised\n");
    }
    else if (abs(b - c) > abs(a - b))
    {
        printf("accelerated\n");
    }
    else if (abs(b - c) < abs(a - b))
    {
        printf("braked\n");
    }

    return 0;
}
