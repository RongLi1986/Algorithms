# 80. Remove Duplicates from Sorted Array II

## Question link
(https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/)

## Question Description

Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,0,1,1,1,1,2,3,3],

Your function should return length = 7, with the first seven elements of nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.

It doesn't matter what values are set beyond the returned length.

## 解题思路
```c++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int i = 1;
        int j = 1;
        int cnt =  1;
        int prev = nums[0];
        while(i < nums.size()){
            if(nums[i] != prev) {
                prev = nums[i]; 
                cnt = 1;
            }else{
                cnt++;
                if(cnt >= 3){
                    i++;
                    continue;
                }
            }
            swap(nums, i, j);
            i++;
            j++;

        }
        
        return j;
    }
    
    void swap(vector<int>& nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};


int removeDuplicates(vector<int>& nums) {
    int n = nums.size(), count = 0;
    for (int i = 2; i < n; i++)
        if (nums[i] == nums[i - 2 - count]) count++;
        else nums[i - count] = nums[i];
    return n - count;
}

```