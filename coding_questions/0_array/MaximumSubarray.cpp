/*
Question
Given an array of integers, find a contiguous subarray which has the largest sum.
Example
Given the array [−2,2,−3,4,−1,2,1,−5,3], the contiguous subarray [4,−1,2,1] has the largest sum = 6.
*/

/*
solution:
Use Dynamic Programming
maxSubArray(A, i) = maxSubArray(A, i - 1) > 0 ? maxSubArray(A, i - 1) : 0 + A[i];
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
            int ret = dp[0];
            dp[0] = A[0];

            for(int i = 1; i < A.size(); i++){
                dp[i] = (dp[i-1] > 0) ? dp[i-1] + A[i] : A[i]; 
                ret = max(ret, dp[i]);
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
    vector<int> t1 = {1,-4,4,8,-9};
    int expect = 12;
    int r = s->func(t1);  
    cout << "expect is: " << expect << ", result is: " << r << endl;

    cout << endl;
    cout << "test case 2" << endl;
    t1 = {1,2,5,-2,8,9,-4,4,-9};
    expect = 23;
    r = s->func(t1);  
    cout << "expect is: " << expect << ", result is: " << r << endl;

    cout << "#################### tests done ###########################"<<endl;

    return 0;
}



