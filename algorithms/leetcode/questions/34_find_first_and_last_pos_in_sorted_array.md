# 34. Find First and Last Position of Element in Sorted Array

## Question link
(https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/)

## Question Description

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

## 解题思路

```c++
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(find_first_pos(nums, target));
        ans.push_back(find_last_pos(nums, target));
        
        return ans;
    }
    
    int find_first_pos(vector<int>& nums, int target){
        if(nums.empty()) return -1;
        int left = 0;
        int right = nums.size() - 1;
        
        while(left + 1 < right){
            int mid = (left + right) / 2;
            if(target <= nums[mid]){
                right = mid;
            }else{
                left = mid;
            }
        }
        
        if(nums[left] == target) return left;
        if(nums[right] == target) return right;
        
        return -1;
    }
    
    int find_last_pos(vector<int>& nums, int target){
        if(nums.empty()) return -1;
        int left = 0;
        int right = nums.size() - 1;
        
        while(left + 1 < right){
            int mid = (left + right) / 2;
            if(target < nums[mid]){
                right = mid;
            }else{
                left = mid;
            }
        }
        
        if(nums[right] == target) return right;
        if(nums[left] == target) return left;
        
        return -1;
    }
};
```