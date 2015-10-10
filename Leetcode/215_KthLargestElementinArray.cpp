/*
Kth Largest Element in an Array Total Accepted: 1348 Total Submissions: 5088 My Submissions Question Solution 
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.

*/

/*
two ways.
1. sort items and find kth largest number
2. make a priority queue, put items into queue.
then pop node until queue.size==k, return queue.top()
*/

#include <iostream>
#include <vector>
#include <list>
#include <limits.h>
 
using namespace std;
 
class Solution {
public:
    int findKthLargest1(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()-k];
    }
    
    int findKthLargest(vector<int>& nums, int k){
        priority_queue<int> p;
        const int s(nums.size());
    
        for (int i = 0; i < s; ++i) p.push(nums[i]);
        while (--k) p.pop();
    
        return p.top();
    }
};

int main(){

	return 0;
}