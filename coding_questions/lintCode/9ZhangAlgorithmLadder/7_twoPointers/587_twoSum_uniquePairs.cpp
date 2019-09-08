/*
Two Sum - Unique pairs

 Description
 Notes
 Testcase
 Judge
Given an array of integers, find how many unique pairs in the array such that their sum is equal to a specific target number. Please return the number of pairs.

Have you met this question in a real interview? Yes
Example
Given nums = [1,1,2,45,46,46], target = 47
return 2

1 + 46 = 47
2 + 45 = 47
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
    int twoSum6(vector<int> &nums, int target) {
        // Write your code here
        sort(nums.begin(), nums.end());
        int res =0;
        
        int left = 0;
        int right = nums.size() - 1;
        
        while(left < right){
            //cout<<left<<" "<<right<<endl;
            int sum = nums[left] + nums[right];
            //cout<<sum<<endl;
            if(sum == target){
               res++;
               if(left!=nums.size()-1){
                    while(nums[left]==nums[left+1]){
                        left++;
                    }
                    left++;
                }
                //cout<<"kk"<<endl;
            }else if(sum>target ){
                if(right!=0){
                    while(nums[right]==nums[right-1]){
                        right--;
                    }
                    right--;
                }
                
            }else{
                if(left!=nums.size()-1){
                    while(nums[left]==nums[left+1]){
                        left++;
                    }
                    left++;
                }
            }
        }
        
        return res;
    }
};
