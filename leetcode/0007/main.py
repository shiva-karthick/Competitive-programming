def reverse(x: int) -> int:
    # sign = [1, -1][x < 0]
    sign = 1 if x > 0 else -1
    rst = sign * int(str(abs(x))[::-1])
    return rst if -(2**31)-1 < rst < 2**31 else 0


def reverse_2(x: int) -> int:
    # if x is negative, return False.
    # if x is positive and last digit is 0, that also cannot form a palindrome, return False.
    if x < 0 or (x > 0 and x % 10 == 0):
        return False

    result = 0
    while x > result:
        result = result * 10 + x % 10
        x = x // 10

    return True if (x == result or x == result // 10) else False


print(reverse_2(-123))
