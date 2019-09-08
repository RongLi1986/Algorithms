/*
Given an integer array, find the top k largest numbers in it.
*/


/*
should use pq
*/

class Solution {
public:
    /*
     * @param nums an integer array
     * @param k an integer
     * @return the top k largest numbers in array
     */
    vector<int> topk(vector<int>& nums, int k) {
        // Write your code here
        sort(nums.begin(), nums.end());
        reverse(nums.begin(),nums.end());
        if(k>nums.size())
            return nums;
        vector<int> res;
        for(int i=0;i<k;i++){
            res.push_back(nums[i]);
        }
        
        return res;
    }
};
