public class Main {

    int binarySearch_template_1(int[] nums, int target) {
        if (nums == null || nums.length == 0)
            return -1;

        int left = 0, right = nums.length - 1;
        while (left <= right) {
            // Prevent (left + right) overflow
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // End Condition: left > right
        return -1;
    }

    public static int search(int[] nums, int target) {
        /*
        * Input: nums = [4,5,6,7,0,1,2], target = 0
        * Output:4 */
        int start = 0; // start = 0
        int end = nums.length - 1; // end = 6 nums.length = 7
        while (start <= end) {
            int mid = start + (end - start) / 2;
            System.out.printf("mid = %d \n", mid);
            if (target == nums[mid]) {
                return mid;
            } else if (nums[mid] >= nums[start]) {
                if (nums[start] <= target && target < nums[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        int nums[] = {4,5,6,7,0,1,2};
        int target = 0;
        search(nums, target);
    }
}