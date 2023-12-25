#include "../../header-files/common.h"

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **floodFill(int **image, int imageSize, int *imageColSize, int sr, int sc, int color, int *returnSize, int **returnColumnSizes)
{
    *returnSize = imageSize; /* returnSize is a pointer dereferenced to hold a value */
    *returnColumnSizes = malloc(sizeof(int) * imageSize);
    for (int i = 0; i < imageSize; i++)
        (*returnColumnSizes)[i] = imageColSize[i];

    /* print  */

    return image;
}

int main(int argc, char const *argv[])
{
    int image[3][3] = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int imageSize = 3;
    int imageColSize[3] = {3, 3, 3};
    static const int sr = 1;
    static const int sc = 1;
    static const int color = 2;

    /* int **result = floodFill(image, imageSize, imageColSize, sr, sc, color, NULL, NULL); */
    {
        int imageColSize[] = {3, 3, 3};
        // Allocate memory for the original image
        int **originalImage = (int **)malloc(imageSize * sizeof(int *));
        for (int i = 0; i < imageSize; i++)
        {
            originalImage[i] = (int *)malloc(*imageColSize * sizeof(int));
        }

        // Populate the original image with values
        for (int i = 0; i < imageSize; i++)
        {
            for (int j = 0; j < *imageColSize; j++)
            {
                originalImage[i][j] = 5;
            }
        }

        // Print the original image
        printf("Original image:\n");
        for (int i = 0; i < imageSize; i++)
        {
            for (int j = 0; j < *imageColSize; j++)
            {
                printf("%d ", originalImage[i][j]);
            }
            printf("\n");
        }

        // Free memory
        for (int i = 0; i < imageSize; i++)
        {
            free(originalImage[i]);
        }
        free(originalImage);
    }

    // Free memory (remember to release all allocated memory)
    // ... (deallocate image, returnColumnSizes, and result)

    return 0;
}
