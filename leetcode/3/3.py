'''
Need 3 temporary variables to find the longest substring: start, maxLength,
and usedChars.
Start by walking through string of characters, one at a time.
Check if the current character is in the usedChars map, this would mean we
have already seen it and have stored it's corresponding index.
If it's in there and the start index is <= that index, update start
to the last seen duplicate's index+1. **This will put the start index at just
past the current value's last seen duplicate.** This allows us to have the
longest possible substring that does not contain duplicates.
If it's not in the usedChars map, we can calculate the longest substring
seen so far. Just take the current index minus the start index. If that
value is longer than maxLength, set maxLength to it.
Finally, update the usedChars map to contain the current value that we just
finished processing.
'''


class Solution:
    # def lengthOfLongestSubstring(self, s):
    #     start = maxLength = 0
    #     usedChar = {}

    #     for i in range(len(s)):
    #         print("Iteration number = {}".format(i))
    #         if s[i] in usedChar and start <= usedChar[s[i]]:
    #             start = usedChar[s[i]] + 1
    #             print("start = {}".format(start))
    #         else:
    #             maxLength = max(maxLength, i - start + 1)

    #         usedChar[s[i]] = i
    #         print("usedChar = {}".format(usedChar))
    #         print("===")
    #     return maxLength

    # def lengthOfLongestSubstring(self, s: str) -> int:
    #     seen = {}
    #     l = 0
    #     output = 0
    #     for r in range(len(s)):
    #         """
    #         There are two cases if s[r] in seen:
    #         case1: s[r] is inside the current window, we need to change the window by moving left pointer to seen[s[r]] + 1.
    #         case2: s[r] is not inside the current window, we can keep increase the window
    #         """

    #         if s[r] not in seen:
    #             # + 1 is to compensate the 0-indexed
    #             output = max(output, r-l+1)
    #         else:
    #             if seen[s[r]] < l:
    #                 output = max(output, r-l+1)
    #             else:
    #                 l = seen[s[r]] + 1
    #         seen[s[r]] = r
    #     return output

    # def lengthOfLongestSubstring(self, s: str) -> int:
    #     """
    #     :type s: str
    #     :rtype: int abcabcbb
    #     """

    #     if len(s) == 0:
    #         return 0
    #     seen = {}
    #     left, right = 0, 0
    #     longest = 1

    #     while right < len(s):
    #         if s[right] in seen:
    #             left = max(left, right)
    #         longest = max(longest, right - left + 1)
    #         seen[s[right]] = right
    #         right += 1
    #         print(left, right, longest)
    #         print(seen)
    #     return longest

    def lengthOfLongestSubstring(self, s: str) -> int:
        seen = {}
        mx = left = 0
        for right, c in enumerate(s):
            if c in seen:
                left = max(left, seen[c] + 1)
            seen[c] = right
            mx = max(mx, right-left+1)
        return mx


s = Solution()
print(s.lengthOfLongestSubstring("abcabcbb"))
