#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    // swap 2 values using the pointer method; give me a test
    int a = 5;
    int b = 10;

    int *ptr_a = &a;
    int *ptr_b = &b;

    int temp = *ptr_a;
    *ptr_a = *ptr_b;
    *ptr_b = temp;

    printf("After swapping: a = %d, b = %d\n", *ptr_a, *ptr_b);

    return 0;
}
