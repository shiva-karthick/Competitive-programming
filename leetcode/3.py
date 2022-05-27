'''
Need 3 temporary variables to find the longest substring: start, maxLength,
and usedChars.
Start by walking through string of characters, one at a time.
Check if the current character is in the usedChars map, this would mean we
have already seen it and have stored it's corresponding index.
If it's in there and the start index is <= that index, update start
to the last seen duplicate's index+1. This will put the start index at just
past the current value's last seen duplicate. This allows us to have the
longest possible substring that does not contain duplicates.
If it's not in the usedChars map, we can calculate the longest substring
seen so far. Just take the current index minus the start index. If that
value is longer than maxLength, set maxLength to it.
Finally, update the usedChars map to contain the current value that we just
finished processing.
'''


class Solution:
    # @return an integer
    def lengthOfLongestSubstring(self, s):
        start = maxLength = 0
        usedChar = {}

        for i in range(len(s)):
            if s[i] in usedChar and start <= usedChar[s[i]]:
                start = usedChar[s[i]] + 1
            else:
                maxLength = max(maxLength, i - start + 1)

            usedChar[s[i]] = i

        return maxLength


s = Solution()
print(s.lengthOfLongestSubstring("abcabcbb"))
