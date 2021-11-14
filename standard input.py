import sys
 
for line in sys.stdin:
    if line != '\n':
        ab = line.split()
        a = int(ab[0])
        b = int(ab[1])
    else:
        break

print(abs(a-b))
