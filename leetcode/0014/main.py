def longestCommonPrefix(strs: list[str]) -> str:
    # Base case
    if not strs:
        return ""
    if len(strs) == 1:
        return strs[0]

    # Find the shortest string
    shortest = min(strs, key=len)  # -> 'a'

    for i, char in enumerate(shortest):
        for other in strs:  # Go through all the strings
            if other[i] != char:
                return shortest[:i]
    return shortest


def longestCommonPrefix2(v: list[str]) -> str:
    ans = ""
    v = sorted(v)
    first = v[0]
    last = v[-1]
    for i in range(min(len(first), len(last))):
        if first[i] != last[i]:
            return ans
        ans += first[i]
    return ans


"""
0123
flow

what are the cases in which it will fail?

"""
