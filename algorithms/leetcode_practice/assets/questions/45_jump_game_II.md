# 45. Jump Game II

## Question link
(https://leetcode.com/problems/jump-game-ii/description/)

## Question Description

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example:

Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.
Note:

You can assume that you can always reach the last index.


## 解题思路

```c++
//greedy
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int i = 0;
        int ans = 0;
        
        while(i < nums.size()){
            int dis = nums[i];
            int next = i + dis;
            if(next >= nums.size() - 1) return ans + 1;
            
            int tmp = nums[next];
            
            for(int j = i + 1;j <= i + dis;j++){
                if(nums[j] - (next - j) >= tmp){
                    next = j;
                    tmp = nums[j];
                }
            }
            
            i = next;
            ans++;
        }
        
        return ans;
    }
};
```

```c++
//DP cannot accept
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        vector<int> dp(nums.size(), 0);
        
        for(int i = 0; i < nums.size(); i++){
            int j = i + 1;
            int jump = nums[i];
            int des = i + jump;
            if(des >= nums.size() - 1) return dp[i] + 1;
            
            while(j <= des) {
                if(dp[j] == 0){
                    dp[j] = dp[i] + 1;
                }
                j++;
            }
        }
        
        return dp[nums.size() - 1];
    }
};
```