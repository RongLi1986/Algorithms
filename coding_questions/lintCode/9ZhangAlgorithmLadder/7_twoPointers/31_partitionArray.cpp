/*
Partition Array

Given an array nums of integers and an int k, partition the array 
(i.e move the elements in "nums") such that:

All elements < k are moved to the left
All elements >= k are moved to the right
Return the partitioning index, i.e the first index i nums[i] >= k.

Notice

You should do really partition in array nums instead of just counting the numbers 
of integers smaller than k.

If all elements in nums are smaller than k, then return nums.length

Have you met this question in a real interview? Yes
Example
If nums = [3,2,2,1] and k=2, a valid answer is 1.
*/

/*

*/

class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        if(nums.empty()) return 0;
        
        int i = 0;
        int j = nums.size() - 1;
        
        while(i<j){
            if(nums[i] >= k){
                int tmp = nums[j];
                nums[j] = nums[i];
                nums[i] = tmp;
                j--;
            }else{
                i++;
            }
        }
        
        if(nums[i]>=k)
            return i;
        else
            return i+1;
    }
};