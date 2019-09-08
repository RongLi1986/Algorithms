/*
Two Sum - Input array is sorted

 Description
 Notes
 Testcase
 Judge
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

Example
Given nums = [2, 7, 11, 15], target = 9
return [1, 2]
*/

/*

*/

class Solution {
public:
    /*
     * @param nums an array of Integer
     * @param target = nums[index1] + nums[index2]
     * @return [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        vector<int> res;
        
        int left = 0;
        int right =nums.size()-1;
        //cout<<"ll"<<endl;
        while(left<right){
            int sum = nums[left] + nums[right];
            if(sum == target){
                res.push_back(left + 1);
                res.push_back(right + 1);
                break;
            }else if(sum>target ){
                right--;
            }else{
                left++;
            }
        }
        //cout<<"kk"<<endl;
        return res;
    }
};