/*
Maximum Subarray

Given an array of integers, find a contiguous subarray which has the largest sum.

 Notice

The subarray should contain at least one number.

Have you met this question in a real interview? Yes
Example
Given the array [−2,2,−3,4,−1,2,1,−5,3], the contiguous subarray [4,−1,2,1] has the largest sum = 6.
*/

/*
O(n^2) ???
*/

class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        // write your code here
        if(nums.empty()) return 0;
        if(nums.size()==1) return nums[0];
        int sum=0;
        int start=0;
        int maxSum=nums[0];
        while(start<nums.size()){
            if(sum>0){
                sum+=nums[start];
            }else{
                sum=nums[start];
            }
            
            if(sum>maxSum)
                maxSum=sum;
            
            start++;
        }
        
        return maxSum;
    }
};

