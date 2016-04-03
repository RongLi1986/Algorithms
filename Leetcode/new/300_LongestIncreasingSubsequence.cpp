/*
300. Longest Increasing Subsequence My Submissions QuestionEditorial Solution
Total Accepted: 23570 Total Submissions: 68980 Difficulty: Medium
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?
*/

/*
dp:
f[] means the LIS for ith's number.

initial all f[]'s items = 1

for each f[i] = max( f[j] && nums[i]>nums[j])  (j from 0 to i-1)

return max(f[])
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> f(nums.size(), 1);
        
        for(int i=1;i<nums.size();i++){
            int max=1;
            for(int j=0;j<i;j++)
             if(nums[j]<nums[i] && max<=f[j]){
                 //cout<<"ll "<<f[i]<<endl;
                 max=f[j]+1;
             }
             f[i]=max;
        }
        
        int maxRes=0;
        for(int i=0;i<f.size();i++){
            //cout<<f[i]<<" ";
            if(maxRes<f[i]){
                maxRes=f[i];
            }    
        }
        //cout<<endl;
        
        return maxRes;
    }
};

int main(){

	return 0;
}