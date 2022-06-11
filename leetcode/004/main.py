# my python cheat
# def findMedianSortedArrays(nums1, nums2):
#     big_list = []
#     big_list = sorted(nums1 + nums2)
#     if (len(big_list) % 2 == 0):
#         med = len(big_list) // 2
#         print((big_list[med] + big_list[med - 1]) / 2)
#     else:
#         print(big_list[len(big_list) // 2])
#     print(big_list)

class Solution:
    def __init__(self):
        pass

    def findMedianSortedArrays(self, A, B):
        l = len(A) + len(B)  # total length of 2 lists
        if l % 2 == 1:  # odd numbers
            return self.kth(A, B, l // 2)
        else:  # even numbers
            return (self.kth(A, B, l // 2) + self.kth(A, B, l // 2 - 1)) / 2.

    def kth(self, a, b, k):  # a = A, b = B, k = l // 2
        if not a:
            return b[k]
        if not b:
            return a[k]
        ia, ib = len(a) // 2, len(b) // 2
        ma, mb = a[ia], b[ib]

        # when k is bigger than the sum of a and b's median indices
        if ia + ib < k:
            # if a's median is bigger than b's, b's first half doesn't include k
            if ma > mb:
                return self.kth(a, b[ib + 1:], k - ib - 1)
            else:
                return self.kth(a[ia + 1:], b, k - ia - 1)
        # when k is smaller than the sum of a and b's indices
        else:
            # if a's median is bigger than b's, a's second half doesn't include k
            if ma > mb:
                return self.kth(a[:ia], b, k)
            else:
                return self.kth(a, b[:ib], k)


nums1 = [1, 2, 5]
nums2 = [3, 4]

s = Solution()
print(s.findMedianSortedArrays(nums1, nums2))
