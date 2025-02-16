from collections import defaultdict

# Read input
import sys

input_data = sys.stdin.read().strip()
lines = input_data.splitlines()

n = int(lines[0])
arr = list(map(int, lines[1].split()))

# Dictionary to track active arrows at each height
active_arrows = defaultdict(int)
arrows = 0

for height in arr:
    if active_arrows[height] > 0:
        # Use an existing arrow at this height
        active_arrows[height] -= 1
        active_arrows[height - 1] += 1
    else:
        # Fire a new arrow
        arrows += 1
        active_arrows[height - 1] += 1

print(arrows)
