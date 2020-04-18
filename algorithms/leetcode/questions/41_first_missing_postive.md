# 41. First Missing Positive

## Question link
(https://leetcode.com/problems/first-missing-positive/description/)

## Question Description

Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3
Example 2:

Input: [3,4,-1,1]
Output: 2
Example 3:

Input: [7,8,9,11,12]
Output: 1

Your algorithm should run in O(n) time and uses constant extra space.

## 解题思路
put all nums into set. trace max number.

```c++
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s;
        int maxNum = 0;       
        for(int i = 0;i < nums.size();i++){
            maxNum = (nums[i] > maxNum) ? nums[i] : maxNum;
            s.insert(nums[i]);
        }

        for(int i = 0;i < maxNum;i++){
            if(s.find(i+1) == s.end()){
              if(i != maxNum)
                return i + 1;
            }
        }
        
        return maxNum + 1;
    }
};
```