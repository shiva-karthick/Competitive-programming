def romanToInt(s: str) -> int:
    dict = {
        "I":     1,
        "V":     5,
        "X":     10,
        "L":     50,
        "C":     100,
        "D":     500,
        "M":     1000
    }

    i = 0
    total = 0
    while (s):
        if (s[i] > s[i + 1]):
            total += dict[s[i]] - dict[s[i + 1]]
            i += 2
        else:
            total += dict[s[i]]
            i += 1
        s = s[i:]
    return total


def romanToInt_2(s: str) -> int:
    translations = {
        "I": 1,
        "V": 5,
        "X": 10,
        "L": 50,
        "C": 100,
        "D": 500,
        "M": 1000
    }
    number = 0
    s = s.replace("IV", "IIII").replace("IX", "VIIII")
    s = s.replace("XL", "XXXX").replace("XC", "LXXXX")
    s = s.replace("CD", "CCCC").replace("CM", "DCCCC")
    for char in s:
        number += translations[char]
    return number


def romanToInt_3(s: str) -> int:
    roman = {'M': 1000, 'D': 500, 'C': 100, 'L': 50, 'X': 10, 'V': 5, 'I': 1}
    z = 0
    for i in range(0, len(s) - 1):
        if roman[s[i]] < roman[s[i+1]]:
            z -= roman[s[i]]
        else:
            z += roman[s[i]]
    return z + roman[s[-1]]


def romanToInt_4(s: str) -> int:
    roman = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
    res, i = 0, 0
    for i in range(len(s)):
        curr, nxt = s[i], s[i+1:i+2]
        if nxt and roman[curr] < roman[nxt]:
            res -= roman[curr]
        else:
            res += roman[curr]
    return res


s1 = "LVIII"
s = "MCMXCIV"

print(romanToInt_3(s1))
