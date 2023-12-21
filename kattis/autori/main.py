line = input()
line = line.split("-")
print(line)

print("".join(list(map(lambda s: s[0], line))))
