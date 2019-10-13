/*
360. Sliding Window Median

Description
Given an array of n integer, and a moving window(size k), move the window at each iteration from the start of the array, 
find the median of the element inside the window at each moving. (If there are even numbers in the array, 
return the N/2-th number after sorting the element in the window. )

Example
Example 1:

Input:
[1,2,7,8,5]
3
Output:
[2,7,7]

Explanation:
At first the window is at the start of the array like this `[ | 1,2,7 | ,8,5]` , return the median `2`;
then the window move one step forward.`[1, | 2,7,8 | ,5]`, return the median `7`;
then the window move one step forward again.`[1,2, | 7,8,5 | ]`, return the median `7`;


Example 2:

Input:
[1,2,3,4,5,6,7]
4
Output:
[2,3,4,5]

Explanation:
At first the window is at the start of the array like this `[ | 1,2,3,4, | 5,6,7]` , return the median `2`;
then the window move one step forward.`[1,| 2,3,4,5 | 6,7]`, return the median `3`;
then the window move one step forward again.`[1,2, | 3,4,5,6 | 7 ]`, return the median `4`;
then the window move one step forward again.`[1,2,3,| 4,5,6,7 ]`, return the median `5`;

O(nlog(n)) time
*/

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of the element inside the window at each moving
     */
    vector<int> medianSlidingWindow(vector<int> &nums, int k) {
        // write your code here
        vector<int> result;
        int n = nums.size();
        if (n == 0)
            return result;
        
        // using set as hash heap
        multiset<int> max, min;
        for (int i = 0; i < k; ++i)
            max.insert(nums[i]);

        //initial sliding window
        for (int i = 0; i < k/2; ++i) {
            min.insert(*max.rbegin());
            max.erase(max.lower_bound(*max.rbegin()));
        }
        
        //update window and find median number for each window
        for (int i = k; i < n; ++i) {
            result.push_back(*max.rbegin());

            // update window
            if (max.find(nums[i-k]) != max.end()) {
                max.erase(max.find(nums[i-k]));
                max.insert(nums[i]);
            } else {
                min.erase(min.find(nums[i-k]));
                min.insert(nums[i]);
            }
            
            // balance heap
            if (max.size() > 0 && min.size() > 0 && *max.rbegin() > *min.begin()) {
                int tmp = *max.rbegin();
                max.erase(max.lower_bound(*max.rbegin()));
                max.insert(*min.begin());
                min.erase(min.begin());
                min.insert(tmp);
            }
        }

        //update last result
        result.push_back(*max.rbegin());

        return result;
    }
};