/*
362. Sliding Window Maximum

Description
Given an array of n integer with duplicate number, and a moving window(size k), 
move the window at each iteration from the start of the array, 
find the maximum number inside the window at each moving.

Example 1:

Input:
[1,2,7,7,8]
3
输出:
[7,7,8]

Explanation：
At first the window is at the start of the array like this `[|1, 2, 7| ,7, 8]` , return the maximum `7`;
then the window move one step forward.`[1, |2, 7 ,7|, 8]`, return the maximum `7`;
then the window move one step forward again.`[1, 2, |7, 7, 8|]`, return the maximum `8`;


Example 2:

Input:
[1,2,3,1,2,3]
5
Output:
[3,3]

Explanation:
At first, the state of the window is as follows: ` [,2,3,1,2,1 | , 3] `, a maximum of ` 3 `;
And then the window to the right one. ` [1, | 2,3,1,2,3 |] `, a maximum of ` 3 `;


o(n) time and O(k) memory
*/

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The maximum number inside the window at each moving.
     */
    
    void inQueue(deque<int> &Q, int num) {
        // maintain queue with incremental
        while (!Q.empty() && Q.back() < num) {
            Q.pop_back();
        }
        Q.push_back(num);
    }
    
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        deque<int> Q;
        vector<int> result;
        
        // build monotone queue and keep max in front
        for (int i = 0; i < k - 1; i++) {
            inQueue(Q, nums[i]);
        }
        
        for (int i = k - 1; i < nums.size(); i++) {
            inQueue(Q, nums[i]);
            result.push_back(Q.front());
            if (Q.front() == nums[i - k + 1]) {
                Q.pop_front();
            }
        }
        
        return result;
    }
};