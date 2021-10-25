numbers = input()
alphabets = input()
l = []
result = []

# combine individual string into a single string
numbers = numbers.split(" ")

# convert a list of string to int
for x in numbers:
    l.append(int(x))

l.sort()

for a in alphabets:
    if a == "C":
        result.append(l[2])
    elif a == "B":
        result.append(l[1])
    else:
        result.append(l[0])

for _ in result:
    print(_, end=" ")
