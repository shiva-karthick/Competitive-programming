import sys

"""
The Time Limit Exceeded (TLE) issue occurs because your implementation uses a
nested loop, making it inefficient for large inputs.

Specifically:
> For each balloon, the inner loop iterates over the rest of the array,
leading to a worst-case time complexity of  O(n^2) .

To fix this, we need to optimize the algorithm to reduce redundant checks.
"""

# First read the input and store them in a list
input_data = sys.stdin.read().strip()
lines = input_data.splitlines()

n = int(lines[0])
arr = list(map(int, lines[1].split()))
checked = [False] * len(arr)

arrows = 0

for i in range(len(arr)):
    if checked[i]:  # Skip already popped balloons
        continue

    arrows += 1  # Shoot a new arrow
    height = arr[i]
    left_pointer = i

    # Iterate to simulate the arrow hitting balloons at decreasing heights
    for j in range(left_pointer + 1, len(arr)):
        if arr[j] == height - 1 and not checked[j]:
            checked[j] = True
            height -= 1  # Decrease the arrow height
        elif height == 1:  # Stop if arrow reaches height 1
            break

print(arrows)
