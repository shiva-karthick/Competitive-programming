package com.company;

public class Main {

    public static int maxProfit(int[] prices) {
        int maxCur = 0, maxSoFar = 0;
        for (int i = 1; i < prices.length; i++) {
            maxCur = Math.max(0, maxCur += prices[i] - prices[i - 1]);
            maxSoFar = Math.max(maxCur, maxSoFar);
        }
        return maxSoFar;
    }

    public int maxProfit2(int[] prices) {
        int res = 0;
        if (prices.length < 2)
            return res;
        int min = prices[0];
        for (int p : prices) {
            if (p > min)
                res = Math.max(res, p - min);
            if (p < min)
                min = p;
        }
        return res;
    }

    public static void main(String[] args) {
        int[] prices = {7, 1, 5, 3, 6, 4};
        System.out.println(maxProfit(prices));
    }
}
