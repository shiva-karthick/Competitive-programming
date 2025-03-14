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
    print(f"v: {v}")
    first = v[0]
    last = v[-1]
    for i in range(min(len(first), len(last))):
        if first[i] != last[i]:
            return ans
        else:
            ans += first[i]
    return ans


"""
What is the concept?
This code implements the longestCommonPrefix function that takes a list of strings v as input and returns the longest common prefix of all the strings. Here is an explanation of how the code works:

1. Initialize an empty string ans to store the common prefix.
2. Sort the input list v lexicographically. This step is necessary because the common prefix should be common to all the strings, so we need to find the common prefix of the first and last string in the sorted list.
3. Iterate through the characters of the first and last string in the sorted list, stopping at the length of the shorter string.
4. If the current character of the first string is not equal to the current character of the last string, return the common prefix found so far.
5. Otherwise, append the current character to the ans string.
Return the ans string containing the longest common prefix.
Note that the code assumes that the input list v is non-empty, and that all the strings in v have at least one character. If either of these assumptions is not true, the code may fail.

"""
