/*
Two Sum - Less than or equal to target

 Description
 Notes
 Testcase
 Judge
Given an array of integers, find how many pairs in the array such that their sum is less than or equal to a specific target number. Please return the number of pairs.

Have you met this question in a real interview? Yes
Example
Given nums = [2, 7, 11, 15], target = 24. 
Return 5. 
2 + 7 < 24
2 + 11 < 24
2 + 15 < 24
7 + 11 < 24
7 + 15 < 25
*/

/*

*/

class Solution {
public:
    /**
     * @param nums an array of integer
     * @param target an integer
     * @return an integer
     */
    int twoSum5(vector<int> &nums, int target) {
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
                int num = (right-left);
                ans +=num;
                left++;
            }else{
                right--;
            }
        }
        
        return ans;
    }
};
