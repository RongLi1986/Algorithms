/*
Move Zeroes My Submissions Question Solution 
Total Accepted: 6677 Total Submissions: 15304 Difficulty: Easy
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/


/*
this solution need extra memory. build tmp vector
scan input vector, and push non zero number into tmp vector
then clear input vector, and copy tmp vector into input vector.
*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> tmp;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                tmp.push_back(nums[i]);
                nums[i]=0;
            }
        }
        
        for(int i=0;i<tmp.size();i++){
            nums[i]=tmp[i];
        }
        
        return;
    }
};

int main(){



    return 0;
}