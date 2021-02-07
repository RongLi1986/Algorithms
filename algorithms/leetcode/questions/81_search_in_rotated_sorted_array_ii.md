# 81. Search in Rotated Sorted Array II

## Question link
(https://leetcode.com/problems/search-in-rotated-sorted-array-ii/)

## Question Description
You are given an integer array nums sorted in ascending order (not necessarily distinct values), and an integer target.

Suppose that nums is rotated at some pivot unknown to you beforehand (i.e., [0,1,2,4,4,4,5,6,6,7] might become [4,5,6,6,7,0,1,2,4,4]).

If target is found in the array return its index, otherwise, return -1.

Example 1:

>Input: nums = [2,5,6,0,0,1,2], target = 0
>Output: true

Example 2:

>Input: nums = [2,5,6,0,0,1,2], target = 3
>Output: false
 
Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
nums is guaranteed to be rotated at some pivot.
-104 <= target <= 104

## 解题思路
binary search

## Code
```c++
class Solution {
public:
    bool search(vector<int>& A, int target) {
    	int left = 0;
    	int right = A.size() - 1;
    	int mid;
    	while(left <= right){
    		mid = (left + right) / 2;
    		if(A[mid] == target) return true;
    		if(A[mid] > A[left]){ //rotation is in right
    			if(A[left] <= target && target < A[mid])
    				right = mid - 1;
    			else
    				left = mid + 1;
    		}else if(A[mid] < A[left]){//rotation is in left
    			if(A[right] >= target && target > A[mid])
    				left = mid + 1;
    			else
    				right = mid - 1;
    		}else
                left++; //dup case
    	}

    	return false;
    }
};
```