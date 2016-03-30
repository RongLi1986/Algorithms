/*
334. Increasing Triplet Subsequence My Submissions QuestionEditorial Solution
Total Accepted: 9137 Total Submissions: 27558 Difficulty: Medium
Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:
Return true if there exists i, j, k 
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Your algorithm should run in O(n) time complexity and O(1) space complexity.

Examples:
Given [1, 2, 3, 4, 5],
return true.

Given [5, 4, 3, 2, 1],
return false.
*/


//O(n) 
/*
keep two numbers from array: first smallest and second smallest number.
then if find another number larger than them. return true;
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.empty()) 
            return false;
        int first=INT_MAX;
        int second=INT_MAX;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=first){
                first=nums[i];
            }else if(nums[i]<=second){
                second=nums[i];
            }else{
                return true;
            }        
        }
        
        return false;
    }
};


int main(){

  return 0;
}