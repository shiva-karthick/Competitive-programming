import java.util.Arrays;
import java.util.stream.Stream;

public class Main {
    public static void merge(int[] nums1, int m, int[] nums2, int n) {
        /* i = m + n - 1 represents the write_index pointer
         *  a = len(a) - 1
         *  b = len(b) - 1
         *  Time Complexity: O(n+m)
         *  Space Complexity: O(1) */
        for (int i = m + n - 1, a = m - 1, b = n - 1; i >= 0 && b >= 0; i--) {
            if (a >= 0 && nums1[a] > nums2[b]) {
                nums1[i] = nums1[a--];
            } else {
                nums1[i] = nums2[b--];
            }
        }
    }

    public static void main(String[] args) {
        int[] nums1 = {1, 2, 3, 0, 0, 0};
        int[] nums2 = {2, 5, 6};
        int m = nums1.length;
        int n = nums2.length;

        merge(nums1, m, nums2, n);
    }
}