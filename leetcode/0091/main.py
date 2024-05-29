def numDecodings(s: str) -> int:

    # Base case
    if not s or s[0] == "0":
        return 0

    # Find the length of the string
    n = len(s)

    dp = [0] * (n + 1)  # [0, 0, 0]

    dp[0] = dp[1] = 1  # [1, 1, 0]

    for i in range(2, n + 1):
        if s[i - 1] != "0":
            dp[i] += dp[i - 1]
        if s[i - 2] == "1" or (s[i - 2] == "2" and s[i - 1] <= "6"):
            dp[i] += dp[i - 2]
    return dp[n]


print(numDecodings("123"))
