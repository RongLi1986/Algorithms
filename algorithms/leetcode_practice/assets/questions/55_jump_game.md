# 55. Jump Game

## Question link
(https://leetcode.com/problems/jump-game/description/)

## Question Description

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

## 解题思路

```c++
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        int idx = 0;
        
        while(true){
            int jump = nums[idx];
            if(jump == 0) return false;  //cannot jump
            if(idx + jump >= nums.size() - 1) return true;  //can jump to last index
            
            //greedy loop jump and find next best index
            int k = 1;
            int m = INT_MIN;
            int next = 0;
            while(k <= jump){
                if(nums[k + idx] + k + idx > m){
                    next = k + idx;
                    m = nums[k + idx] + k + idx;
                }
                k++;
            }
            
            idx = next;
        }
    }
};
```