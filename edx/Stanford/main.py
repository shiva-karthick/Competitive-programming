# n = [1, 3, 5, 2, 4, 6]
n = [7, 6, 5, 4, 3, 2]
total = 0


for i in range(len(n)):
    for j in range(len(n)):
        if i != j:
            if i < j and n[i] > n[j]:
                total += 1

print(total)
