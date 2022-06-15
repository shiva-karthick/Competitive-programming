for i in range(int(input())):
    print("%d is looped times" % (i))
    a = list(map(int, input().split()))
    n, m = a[0], a[1]  # n + 1 benches and m = initial energy
    benches = list(map(int, input().split()))

    energy = sum(benches)

    if energy <= m:
        print(0)
    else:
        print(energy - m)

# input
'''
3
3 1
1 2 1
4 5
3 3 5 2
5 16
1 2 3 4 5
'''

# output
'''
3
8
0
'''
