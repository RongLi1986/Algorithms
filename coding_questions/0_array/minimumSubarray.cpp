/*
https://www.lintcode.com/problem/minimum-subarray/description
Description
Given an array of integers, find the subarray with smallest sum.
Return the sum of the subarray.
Note:
The subarray should contain one integer at least.

Example
For[1, -1, -2, 1], return-3.
*/

/*
solution:
Kadane's Algorithm
Use Dynamic Programming
maxSubArray(A, i) = maxSubArray(A, i - 1) < 0 ? maxSubArray(A, i - 1) : 0 + A[i];
*/

#include "../include/header.hpp"

class Solution {
    public:
        /**
         * @param nums1 an integer array
         * @return an integer
         */
        int func(vector<int> A) {
            if(A.empty()) return 0;
            vector<int> dp(A.size(), 0);
            
            dp[0] = A[0];
            int ret = dp[0];

            for(int i = 1; i < A.size(); i++){
                dp[i] = min(dp[i-1] + A[i] , A[i]); 
                ret = min(ret, dp[i]);
            }

            return ret;
        }
};

//test
int main(){
    Solution* s = new Solution();

    //wirte your test case in here
    cout << "##################### test begining #######################"<<endl; 
    
    cout << "test case 1" << endl;
    vector<int> t1 = {1,4,8,9,6,7,2,1};
    int expect = 1;
    int r = s->func(t1);  
    cout << "expect is: " << expect << ", result is: " << r << endl;

    cout << endl;
    cout << "test case 2" << endl;
    t1 = {1,2,5,-2,8,9,-4,4,-9};
    expect = -9;
    r = s->func(t1);  
    cout << "expect is: " << expect << ", result is: " << r << endl;

    cout << "#################### tests done ###########################"<<endl;

    return 0;
}



