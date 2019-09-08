/*
Move Zeroes

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

 Notice

You must do this in-place without making a copy of the array.
Minimize the total number of operations.
Have you met this question in a real interview? Yes
Example
Given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
*/

/*
move all non zero numbers to left and clear other part to zero
*/


class Solution {
public:
    /**
     * @param nums an integer array
     * @return nothing, do this in-place
     */
    void moveZeroes(vector<int>& nums) {
        // Write your code here
        int j = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                nums[j]=nums[i];
                j++;
            }
        }
        
        while(j<nums.size()){
            nums[j]=0;
            j++;
        }
        
        return;
    }
};