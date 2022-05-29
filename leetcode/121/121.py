class Solution:
    def maxProfit(self, prices) -> int:
        res = 0
        if len(prices) < 2:
            return res
        minimum = prices[0]
        for p in prices:
            if p > minimum:
                res = max(res, p - minimum)
            elif p < minimum:
                minimum = p
        return res
