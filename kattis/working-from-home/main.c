#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    // input collected
    int m, p, n;
    scanf("%d %d %d", &m, &p, &n);

    int *work_days = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &work_days[i]);
    }
    // input collected

    int result = 0;
    int target = m;

    for (int i = 0; i < n; i += 1)
    {
        // target is m
        int current_work_day = work_days[i];
        int difference = current_work_day - target;

        // if difference > 0, then we need to work less
        // if difference < 0, then we need to work more
        // if difference == 0, then we hit the target
        if (difference > 0)
        {
            // adjust new target
            target = (int)ceil(target - ((p / 100.0) * difference));
            result += 1; // she achieve her target and can watch her episode
        }
        else if (difference < 0)
        {
            // printf("difference: %d\n", difference);
            // printf("%f\n", (double)ceil(((p / 100.0) * abs(difference))));
            target = (int)ceil(m + ((p / 100.0) * abs(difference)));
            // printf("target: %d\n", target);
        }
        else if (difference == 0)
        {
            result += 1;
        }
    }

    printf("%d\n", result);

    return 0;
}
