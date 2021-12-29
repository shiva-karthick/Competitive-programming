#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'hourglassSum' function below.
#
# The function is expected to return an INTEGER.
# The function accepts 2D_INTEGER_ARRAY arr as parameter.
#


def hourglassSum(arr):
    result_arr = []
    total_sum = 0
    for row in range(4):
        for column in range(1, len(arr[row]) - 1):
            # Check column neighbours, and calculate others and sweep through columns
            total_sum = sum(
                [arr[row][column],
                 arr[row][column - 1],
                 arr[row][column + 1],
                 arr[row+1][column],
                 arr[row + 2][column],
                 arr[row + 2][column - 1],
                 arr[row + 2][column + 1]]
            )
            result_arr.append(total_sum)
            total_sum = 0
    return max(result_arr)


if __name__ == '__main__':

    arr = []

    for _ in range(6):
        arr.append(list(map(int, input().rstrip().split())))

    result = hourglassSum(arr)

    print(result)
