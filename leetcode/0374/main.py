# Problem 374
#My rule of thumb when it comes to binary search:

#Include ALL possible answers when initialize lo & hi
#Don't overflow the mid calculation
#Shrink boundary using a logic that will exclude mid
#Avoid infinity loop by picking the correct mid and shrinking logic
#Always think of the case when there are 2 elements left

class Solution:
    def guessNumber(self, n: int) -> int:
        low = 1
        high = n
        while (low <= high):
            mid = low + (high - low) // 2
            # pyrefly: ignore  # unknown-name
            res = guess(mid)
            if res == 0:
                return mid
            elif res < 0:
                high = mid - 1
            else:
                low = mid + 1
        return -1
