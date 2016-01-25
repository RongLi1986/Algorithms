/*
324. Wiggle Sort II My Submissions Question
Total Accepted: 3290 Total Submissions: 16494 Difficulty: Medium
Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example:
(1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6]. 
(2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].

Note:
You may assume all input has valid answer.

Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?

*/


/*
DFS+ dp
DFS scan matrix, using matrix to record path length for each item in matrix.
then find largest one
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.empty()) return;
        sort(nums.begin(),nums.end());
        int left=(nums.size()+1)/2;
        int right=(nums.size());
        
        vector<int> out;
        
        for(int i=0;i<nums.size();i++){
            if(i%2==0)
                out.push_back(nums[--left]);
            else
                out.push_back(nums[--right]);
        }
        
        nums=out;
    }
};


int main(){
    
    return 0;
}
