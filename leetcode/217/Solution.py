class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        # Use dictionary ?
        # Sets
        return len(nums) > len(set(nums))
