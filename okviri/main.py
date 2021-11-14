import sys
from pprint import pprint

## Wishful thinking

##input = sys.stdin.read()
##line = input.strip("\n")

line1 = [""]
line2 = [""]
line3 = [""]
line4 = [""]
line5 = [""]

## Debugging
line = "ABCD"

def solve(line):
    for i in range(len(line)):
        if (i+1) % 3 != 0:
            line1.append("..#.")
            line2.append(".#.#")
            if (i) % 3 == 0 and  i != 0:
                line3.append("*." + str(line[i]) + ".")
            else:
                line3.append("#." + str(line[i]) + ".")
            line4.append(".#.#")
            line5.append("..#.")
        elif (i+1) % 3 == 0 and i != 0:
            line1.append("..*.")
            line2.append(".*.*")
            line3.append("*." + str(line[i]) + ".")
            line4.append(".*.*")
            line5.append("..*.")

    line1.append(".")
    line2.append(".")
    line4.append(".")
    line5.append(".")
    
    if len(line) % 3 == 0:
        line3.append("*")
    else:
        line3.append("#")

solve(line)

line1 = "".join(line1)
line2 = "".join(line2)
line3 = "".join(line3)
line4 = "".join(line4)
line5 = "".join(line5)

print(line1)
print(line2)
print(line3)
print(line4)
print(line5)




                
            
            









