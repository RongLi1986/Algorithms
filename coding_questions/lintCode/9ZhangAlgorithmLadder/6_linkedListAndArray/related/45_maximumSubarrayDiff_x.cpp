/*
Maximum Subarray Difference

Given an array with integers.

Find two non-overlapping subarrays A and B, which |SUM(A) - SUM(B)| is the largest.

Return the largest difference.

 Notice

The subarray should contain at least one number

Have you met this question in a real interview? Yes
Example
For [1, 2, -3, 1], return 6.
*/

/*

*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two
     *          Subarrays
     */
    int maxDiffSubArrays(vector<int> nums) {
        // write your code here
        // write your code here
        //int globalLeft = INT_MIN;
        int localLeft = nums[0];
        vector<int> leftLarge(nums.size(), INT_MIN);
        vector<int> rightSmall(nums.size(), INT_MAX);
        leftLarge[0]=nums[0];
        for(int i = 1;i<nums.size()-1;i++){
            leftLarge[i] = max(nums[i],max(nums[i]+localLeft, leftLarge[i-1]));
            localLeft = max(nums[i],localLeft + nums[i]);
            //cout<<leftLarge[i]<<" ";
        }
        //cout<<endl;
        
        //int globalRight = INT_MIN;
        int localRight = 0;
        //rightSmall : max sum of i+1 to last 
        for(int i=nums.size()-2;i>=0;i--){
            rightSmall[i] = min(nums[i+1],min(nums[i+1]+localRight, rightSmall[i+1]));
            localRight = min(nums[i+1],localRight + nums[i+1]);
            //cout<<rightSmall[i]<<" ";
        }
        //cout<<endl;
        
        
        //reverse
        localLeft = nums[0];
        vector<int> leftSmall(nums.size(), INT_MAX);
        vector<int> rightLarge(nums.size(), INT_MIN);
        leftSmall[0] = nums[0];
        for(int i = 1;i<nums.size()-1;i++){
            leftSmall[i] = min(nums[i],min(nums[i]+localLeft, leftSmall[i-1]));
            localLeft = min(nums[i],localLeft + nums[i]);
            //cout<<leftSmall[i]<<" ";
        }
        //cout<<endl;
        
        //int globalRight = INT_MIN;
        localRight = 0;
        //rightSmall : max sum of i+1 to last 
        for(int i=nums.size()-2;i>=0;i--){
            rightLarge[i] = max(nums[i+1],max(nums[i+1]+localRight, rightLarge[i+1]));
            localRight = max(nums[i+1],localRight + nums[i+1]);
            //cout<<rightLarge[i]<<" ";
        }
        //cout<<endl;
        
        
        int res = INT_MIN;
        for(int i=0;i<nums.size()-1;i++){
            //cout<< leftLarge[i] - rightSmall[i]<<endl;
            
            //cout<< rightLarge[i] - leftSmall[i] <<endl;
            
            int tmp = max((leftLarge[i] - rightSmall[i]),(rightLarge[i] - leftSmall[i]));
            if(tmp>res)
                res = tmp;
        }
        
        return res;
        
    }
};
