line = input()
line = line.split("-")
print("".join(list(map(lambda s : s[0], line))))
