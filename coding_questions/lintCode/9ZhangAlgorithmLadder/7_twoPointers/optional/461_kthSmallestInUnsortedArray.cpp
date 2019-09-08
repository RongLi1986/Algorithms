/*
Kth Smallest Numbers in Unsorted Array

Find the kth smallest numbers in an unsorted integer array.

Have you met this question in a real interview? Yes
Example
Given [3, 4, 1, 2, 5], k = 3, the 3rd smallest numbers are [1, 2, 3].
*/

/*
try to do it in O(n)
*/

class Solution {
public:
    /*
     * @param k an integer
     * @param nums an integer array
     * @return kth smallest element
     */
    int kthSmallest(int k, vector<int> nums) {
        // write your code here
        sort(nums.begin(),nums.end());
        
        return nums[k-1];
    }
};