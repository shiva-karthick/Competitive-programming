#include <stdio.h>
#include <stdlib.h>
#include "/home/shankar/Shiva/Competitive-programming/include/common.h"

int main(int argc, char const *argv[])
{
    char *buffer = calloc(100, sizeof(char));

    if (fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        printf("%s", buffer);
    }

    return 0;
}
