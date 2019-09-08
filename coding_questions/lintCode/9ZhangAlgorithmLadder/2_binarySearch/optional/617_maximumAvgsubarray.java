/*
Maximum Average Subarray

Given an array with positive and negative numbers, find the maximum average 
subarray which length should be greater or equal to given length k.

 Notice

It's guaranteed that the size of the array is greater or equal to k.

Have you met this question in a real interview? Yes
Example
Given nums = [1, 12, -5, -6, 50, 3], k = 3

Return 15.667 // (-6 + 50 + 3) / 3 = 15.667



*/

public class Solution {
    /**
     * @param nums an array with positive and negative numbers
     * @param k an integer
     * @return the maximum average
     */
    public double maxAverage(int[] nums, int k) {
        // Write your code here
        double l = Integer.MAX_VALUE, r = Integer.MIN_VALUE;
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            if (nums[i] < l)
                l = nums[i];
            if (nums[i] > r)
                r = nums[i];
        }

        double[] sum = new double[n + 1];
        sum[0] = 0;
        while (r - l >= 1e-6) {
            double mid = (l + r) / 2.0;

            double min_pre = 0;
            boolean check = false;
            for (int i = 1; i <= n; ++i) {
                sum[i] = sum[i - 1] + nums[i - 1] - mid;
                if (i >= k && sum[i] - min_pre >= 0) {
                    check = true;
                    break;
                }
                if (i >= k)
                    min_pre = Math.min(min_pre, sum[i - k + 1]);
            }
            if (check)
                l = mid;
            else
                r = mid;
        }

        return l;
    }
}