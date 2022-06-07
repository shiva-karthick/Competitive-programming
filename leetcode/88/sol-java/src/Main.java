import java.util.Arrays;

public class Main {
    public static void merge_1(int[] nums1, int m, int[] nums2, int n) {
        int tail1 = m - 1, tail2 = n - 1, finished = m + n - 1;
        while (tail1 >= 0 && tail2 >= 0) {
            nums1[finished--] = (nums1[tail1] > nums2[tail2]) ?
                    nums1[tail1--] : nums2[tail2--];
        }

        while (tail2 >= 0) { //only need to combine with remaining nums2, if any
            nums1[finished--] = nums2[tail2--];
        }

        System.out.println(Arrays.toString(nums1));
    }

    public static void merge_2(int[] nums1, int m, int[] nums2, int n){

    }

    public static void main(String[] args) {
        int[] nums1 = {1, 2, 3, 0, 0, 0};
        int[] nums2 = {2, 5, 6};
        int m = nums1.length;
        int n = nums2.length;

        // merge_1(nums1, m, nums2, n);
    }
}