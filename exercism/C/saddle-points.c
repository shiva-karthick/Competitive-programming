#include "../header-files/common.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint-gcc.h>

#define max(a, b) \
    ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

typedef struct
{
    uint16_t row;
    uint16_t column;
} saddle_point_t;

typedef struct
{
    uint16_t count;
    saddle_point_t points[];
} saddle_points_t;

typedef struct
{
    size_t count;
    uint8_t elements[];
} vector_t;

void free_saddle_points(saddle_points_t *to_free)
{
    free(to_free);
}

vector_t *get_row(int rows, int cols, uint8_t matrix[rows][cols], int row)
{
    /* malloced the vector, lets place the items */
    vector_t *vector = malloc(sizeof(vector_t) + cols * sizeof(uint8_t));
    (*vector).count = cols;
    for (int i = 0; i < cols; i += 1)
    {
        (*vector).elements[i] = matrix[row][i];
    }

    return vector;
}

vector_t *get_col(int rows, int cols, uint8_t matrix[rows][cols], int col)
{
    /* malloced the vector, lets place the items */
    vector_t *vector = malloc(sizeof(vector_t) + rows * sizeof(uint8_t));
    (*vector).count = rows;
    for (int i = 0; i < rows; i += 1)
    {
        (*vector).elements[i] = matrix[i][col];
    }

    return vector;
}

uint8_t get_max(vector_t *vector)
{
    /* Find the maximum element in vector */
    uint8_t max = vector->elements[0];
    if (vector->count == 1)
    {
        free(vector);
        return max;
    }
    for (int i = 1; i < (int)vector->count; i += 1)
    {
        if (vector->elements[i] > max)
            max = vector->elements[i];
    }
    free(vector);
    return max;
}

uint8_t get_min(vector_t *vector)
{
    /* Find the minimum element in vector */
    uint8_t min = vector->elements[0];
    if (vector->count == 1)
    {
        free(vector);
        return min;
    }
    for (int i = 1; i < (int)vector->count; i += 1)
    {
        if (vector->elements[i] < min)
            min = vector->elements[i];
    }
    free(vector);
    return min;
}

saddle_points_t *saddle_points(int rows, int cols, uint8_t matrix[rows][cols])
{
    int max_points = cols < rows ? cols : rows;
    uint8_t max, min;
    saddle_point_t points[max_points];
    int count = 0;

    for (int i = 0; i < rows; i += 1)
    {
        max = get_max(get_row(rows, cols, matrix, i));
        for (int j = 0; j < cols; j += 1)
        {
            min = get_min(get_col(rows, cols, matrix, j));
            /* Go through every element in the matrix to check if its the max of every row and the min of every column */
            if (max == min)
            {
                points[count].row = i + 1;
                points[count].column = j + 1;
                count += 1;
            }
        }
    }

    saddle_points_t *ptr = malloc(sizeof(saddle_points_t) + count * sizeof(saddle_point_t));

    ptr->count = count;

    for (int i = 0; i < count; i += 1)
    {
        ptr->points[i] = points[i];
    }

    return ptr;
}

int main(int argc, char const *argv[])
{
    /* Test Case 1 */
    uint8_t matrix[3][3] = {{9, 8, 7}, {5, 3, 2}, {6, 6, 7}};
    size_t expected_count = 1;
    saddle_point_t expected_points[] = {{2, 1}};
    /*  */

    saddle_points_t *actual = saddle_points(3, 3, matrix);
    printf("Actual Count: %d\n", actual->count);

    free_saddle_points(actual);

    return 0;
}
