#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int count = 0;
    scanf("%d", &count);

    int *arr = (int *)malloc(count * sizeof(int));

    int sum = 0;
    for (int i = 0; i < count; i += 1)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    printf("%d\n", sum);

    return 0;
}