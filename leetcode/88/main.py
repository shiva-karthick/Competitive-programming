
def merge(nums1: list[int], m: int, nums2: list[int], n: int) -> None:
    # while n > 0:
    #     if (m <= 0) or (nums2[n-1] >= nums1[m-1]):
    #         nums1[m+n-1] = nums2[n-1]
    #         n -= 1
    #     else:
    #         nums1[m+n-1] = nums1[m-1]
    #         m -= 1
    # print(nums1)

    a, b, write_index = m-1, n-1, m + n - 1
    while b >= 0:
        if a >= 0 and nums1[a] > nums2[b]:
            # shift an element 1 step to the end in nums1 array
            nums1[write_index] = nums1[a]
            a -= 1
        else:
            # bring an element from nums2 array and write in the location of write_index
            nums1[write_index] = nums2[b]
            b -= 1

        write_index -= 1
    print(nums1)


'''
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
'''
nums1 = [1, 2, 3, 0, 0, 0]
m = 3
nums2 = [2, 5, 6]
n = 3
merge(nums1, m, nums2, n)
