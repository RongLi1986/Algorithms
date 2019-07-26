/*
Range Sum Query - Immutable My Submissions Question
Total Accepted: 7991 Total Submissions: 33062 Difficulty: Easy
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.
Subscribe to see which companies asked this question

Show Tags
Show Similar Problems
*/

#include <iostream>
#include <vector>

using namespace std;

class NumArray {
vector<int> sum;
public:
    NumArray(vector<int> &nums) {
        if (!nums.empty()){
            sum.resize(nums.size());
            sum[0]=nums[0];
            for(int i=1;i<nums.size();i++){
                sum[i]=nums[i]+sum[i-1];
            }
        }
    }

    int sumRange(int i, int j) {
        if(i==0) return sum[j];
        return sum[j]-sum[i-1];
    }
};

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
int main(){
    
    return 0;
}