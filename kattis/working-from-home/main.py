from math import ceil

m, p, n = map(int, input().split())

# for n integers append to list
d = []

for i in range(n):
    d.append(int(input()))

result = 0
target = m

for i in range(n):
    diff = d[i] - target
    if diff > 0:
        target = target - ceil(diff * (p / 100))
        result += 1
    elif diff < 0:
        target = ceil(m + ((p / 100) * abs(diff)))
    else:
        result += 1

print(result)
