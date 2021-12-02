## Babelfish
import sys

dictionary = {}
flag = True

for line in sys.stdin:
    if flag:
        if line == "\n":
            flag = False
        else:
            s = line.split()
            dictionary[s[1]] = s[0]
    else:
        if line.strip() in dictionary:
            print(dictionary[line.strip()])
        else:
            print("eh")

