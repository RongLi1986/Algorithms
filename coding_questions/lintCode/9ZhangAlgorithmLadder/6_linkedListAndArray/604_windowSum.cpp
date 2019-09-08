/*
Window Sum

Given an array of n integer, and a moving window(size k), move the window at each iteration from the start of the array, 
find the sum of the element inside the window at each moving.

Example
For array [1,2,7,8,5], moving window size k = 3. 
1 + 2 + 7 = 10
2 + 7 + 8 = 17
7 + 8 + 5 = 20
return [10,17,20]
*/

/*
merge
*/

class Solution {
public:
    /**
     * @param nums a list of integers.
     * @return the sum of the element inside the window at each moving
     */
    vector<int> winSum(vector<int> &nums, int k) {
        // write your code here
        
        vector<int> ans;
        if(k==0)
            return ans;
        
        for(int i = 0;i < nums.size()-k + 1;i++){
            int sum = 0;
            if(ans.empty()){ //first
                for(int j=i;j<i+k;j++){
                    sum += nums[j];
                }
            }else{
                sum = ans[ans.size()-1];
                sum+= nums[i+k-1];
                sum-= nums[i-1];
            }
            ans.push_back(sum);
        }
        
        return ans;
    }
};
