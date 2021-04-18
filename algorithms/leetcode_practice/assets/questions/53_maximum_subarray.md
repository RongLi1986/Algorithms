# 53. Maximum Subarray

## Question link
(https://leetcode.com/problems/maximum-subarray/description/)

## Question Description

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.


## 解题思路


```c++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);  //the array with max sum with end nums[i]
        
        dp[0] = nums[0];
        int res = dp[0];
        
        for(int i = 1;i<n;i++){
            dp[i] = nums[i] + (dp[i-1] < 0 ? 0 : dp[i-1]);
            res = max(res, dp[i]);
        }
        
        return res;
    }
};
```