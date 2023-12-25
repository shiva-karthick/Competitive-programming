#include "../header-files/common.h"
#include <stdbool.h>

bool is_armstrong_number(int candidate)
{
    int sum = 0;
    int temp = candidate;
    int length = 0;
    while (temp > 0)
    {
        length++;
        temp /= 10;
    }
    printf("length: %d\n", length);
    temp = candidate;
    for (size_t i = 0; i < length; ++i)
    {
        sum += pow(temp % 10, length);
        temp /= 10;
    }
    return true ? sum == candidate : false;
}

int main(int argc, char const *argv[])
{
    printf("is_armstrong_number(153): %d\n", is_armstrong_number(153));
    return 0;
}
