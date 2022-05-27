package com.company;

import java.util.HashSet;
import java.util.Set;

public class Main {

    class Solution {
        public static boolean containsDuplicate(int[] nums) {
            final Set<Integer> distinct = new HashSet<Integer>();
            for (int num : nums) {
                if (distinct.contains(num)) {
                    return true;
                }
                distinct.add(num);
            }
            System.out.println(distinct);
            return false;
        }
    }


    public static void main(String[] args) {
        int[] nums = {1, 2, 3, 4};
        System.out.println(Solution.containsDuplicate(nums));
    }
}
