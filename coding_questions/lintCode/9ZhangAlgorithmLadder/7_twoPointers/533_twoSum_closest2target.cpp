/*
Two Sum - Closest to target

Given an array nums of n integers, find two integers in nums such that the sum is closest to a given number, target.

Return the difference between the sum of the two integers and the target.

Have you met this question in a real interview? Yes
Example
Given array nums = [-1, 2, 1, -4], and target = 4.

The minimum difference is 1. (4 - (2 + 1) = 1).


*/

/*

*/

class Solution {
public:
    /**
     * @param nums an integer array
     * @param target an integer
     * @return the difference between the sum and the target
     */
    int twoSumCloset(vector<int>& nums, int target) {
        // Write your code here
        sort(nums.begin(), nums.end());
        
        int i=0;
        int j=nums.size()-1;
        int minVal = INT_MAX;
        while(i<j){
            if(abs(target-(nums[i]+nums[j])) < minVal)
                minVal = abs(target-(nums[i]+nums[j]));
            
            if(target < (nums[i]+nums[j])){
                j--;
            }else if(target > (nums[i]+nums[j])){
                i++;
            }else{
                return 0;
            }
        }
        
        return minVal;
    }
};