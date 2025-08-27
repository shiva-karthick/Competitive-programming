## Find the minimum number of operations required
import sys

for line in sys.stdin:
    ab = line.split()
    a = int(ab[0])
    b = int(ab[1])

    ## 3 rules for recursion
    ## Identify the base case
    ## Must have a recursive case
    ## Problem must be simplified at each recursion

    ## Keep track of recursion count
    count = 0
    # pyrefly: ignore  # bad-assignment
    while a != b:              
        if a > b:
            if a % 2 == 0: ## shows a is an even number
                a = a / 2
            else:
                a += 1
            count += 1
        elif b > a: 
            a += 1
            count += 1
    print(count)
