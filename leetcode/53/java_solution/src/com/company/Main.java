package com.company;

public class Main {
    public static int maxSubArray(int[] A) {
        int n = A.length;
        int[] dp = new int[n]; // dp[i] means the maximum subarray ending with A[i];
        dp[0] = A[0];

        int max = dp[0];

        for (int i = 1; i < n; i++) {
            dp[i] = A[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
            max = Math.max(max, dp[i]);
        }

        return max;
    }

    public static int maxSubArray2(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        int max = nums[0];
        int sum = nums[0];

        for (int i = 1; i < nums.length; i++) {
            if (sum < 0) {
                sum = nums[i];
            } else {
                sum += nums[i];
            }
            max = Math.max(max, sum);
        }
        return max;
    }


    public static int maxSubArray_no_DP(int[] nums) {
        if (nums == null || nums.length == 0)
            return 0;
        int runSum = nums[0];
        int result = runSum;
        for (int end = 1; end < nums.length; end++) {
            runSum = runSum + nums[end] >= nums[end] ? runSum + nums[end] : nums[end];
            result = Math.max(runSum, result);
        }
        return result;
    }


    public static void main(String[] args) {
        int[] nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        int[] test_case2 = {5, 4, -1, 7, 8};
        System.out.println(maxSubArray2(nums));
    }
}
