#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char buffer[100];
    int n, p;
    char str[100];

    if (fgets(buffer, 100, stdin) != NULL)
    {
        sscanf(buffer, "%d %d", &n, &p);
    }

    printf("%d\n", p);

    return 0;
}
