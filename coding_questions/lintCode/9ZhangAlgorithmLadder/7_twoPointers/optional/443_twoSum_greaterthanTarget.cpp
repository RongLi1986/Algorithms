/*
Two Sum - Greater than target

Given an array of integers, find how many pairs in the array such that their sum 
is bigger than a specific target number. Please return the number of pairs.

Have you met this question in a real interview? Yes
Example
Given numbers = [2, 7, 11, 15], target = 24. Return 1. (11 + 15 is the only pair)
*/

/*

*/


class Solution {
public:
    /**
     * @param nums: an array of integer
     * @param target: an integer
     * @return: an integer
     */
    int twoSum2(vector<int> &nums, int target) {
        // Write your code here
        // Write your code here
        sort(nums.begin(), nums.end());
        int left =0;
        int right = nums.size()-1;
        int ans = 0;
        
        while(left < right){
            //cout<<left<<" "<,right
            //cout<<ans<<endl;
            int sum =nums[left] + nums[right];
            if(sum<=target){
                left++;
            }else{
                int num = (right-left);
                ans +=num;
                right--;
            }
        }
        
        return ans;
    }
};
