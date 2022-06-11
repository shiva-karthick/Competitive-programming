class Solution:
    def search(self, nums: list[int], target: int) -> int:
        L, H = 0, len(nums)
        while L < H:
            M = (L+H) // 2

            if (target < nums[0]) and (nums[0] < nums[M]):  # -inf
                L = M+1
            elif (target >= nums[0]) and (nums[0] > nums[M]):  # +inf
                H = M
            elif nums[M] < target:
                L = M+1
            elif nums[M] > target:
                H = M
            else:
                return M
        return -1


nums = [4, 0, 2]
target = 0

s = Solution()
print(s.search(nums, target))

# Very Important Idea
# If nums[mid] and target are "on the same side" of nums[0],
# we just take nums[mid]. Otherwise we use -infinity or +infinity as needed.

# Input: nums = [4,5,6,7,0,1,2], target = 0
# Output: 4

# L = 0 and H = 7
# M = (0 + 7) // 2 = 3
