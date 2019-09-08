/*
 3Sum Closest

 Description
 Notes
 Testcase
 Judge
Given an array S of n integers, find three integers in S such that the sum is 
closest to a given number, target. Return the sum of the three integers.

 Notice

You may assume that each input would have exactly one solution.

Have you met this question in a real interview? Yes
Example
For example, given array S = [-1 2 1 -4], and target = 1. The sum that 
is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution {
public:    
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> nums, int target) {
        // write your code here
        sort(nums.begin(), nums.end());
        int minAns =INT_MAX;
        int res = 0;
        for(int i=0;i<nums.size();i++){
            int left = i+1;
            int right = nums.size()-1;
            while(left<right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum==target){
                    return target;
                }else if(sum<target){
                    if(abs(sum-target)<minAns){
                        minAns = abs(sum-target);
                        res = sum;
                    }
                    
                    left++;
                }else{
                    if(abs(sum-target)<minAns){
                        minAns = abs(sum-target);
                        res = sum;
                    }
                    
                    right--;
                }
            }
        }
        
        return res;
    }
};
