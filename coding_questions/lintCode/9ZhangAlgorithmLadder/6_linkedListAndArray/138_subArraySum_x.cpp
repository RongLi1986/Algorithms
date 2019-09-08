/*
Subarray Sum

 Description
 Notes
 Testcase
 Judge
Given an integer array, find a subarray where the sum of numbers is zero. Your code should return the index of the first number and the index of the last number.

 Notice

There is at least one subarray that it's sum equals to zero.

Have you met this question in a real interview? Yes
Example
Given [-3, 1, 2, -3, 4], return [0, 2] or [1, 3].
*/

/*
O(n^2) ???
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        // write your code here
        int sum=0;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            sum=nums[i];
            if(sum==0){
                res.push_back(i);
                res.push_back(i);
                return res;
            }
            for(int j=i+1;j<nums.size();j++){
                sum+=nums[j];
                if(sum==0){
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
        
        return res;
    }
};