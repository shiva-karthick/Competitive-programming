import sys

# Think parallel, the number of printers is directly proportional to the number of statues.
# 5 printers = 5 statues

statues = int(input())
printers = 1
statuesprinted = 0
days = 0


while statuesprinted < statues:
    if (statues - statuesprinted) > printers:
        days += 1
        printers *= 2
    else:
        days += 1
        statuesprinted += printers

print(days)
