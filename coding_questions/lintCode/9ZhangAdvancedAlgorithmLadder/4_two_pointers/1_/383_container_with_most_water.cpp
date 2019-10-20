/*
383. Container With Most Water

Description

Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Example 1:

Input: [1, 3, 2]
Output: 2
Explanation:
Selecting a1, a2, capacity is 1 * 1 = 1
Selecting a1, a3, capacity is 1 * 2 = 2
Selecting a2, a3, capacity is 2 * 1 = 2
Example 2:

Input: [1, 3, 2, 2]
Output: 4
Explanation:
Selecting a1, a2, capacity is 1 * 1 = 1
Selecting a1, a3, capacity is 1 * 2 = 2
Selecting a1, a4, capacity is 1 * 3 = 3
Selecting a2, a3, capacity is 2 * 1 = 2
Selecting a2, a4, capacity is 2 * 2 = 4
Selecting a3, a4, capacity is 2 * 1 = 2

[3, 3, 1, 1, 2]

*/

#include <iostream>
#include <vector>
#include <map>
//#include <algorithm>

using namespace std;

/*

*/ 

class Solution {
public:
    /**
     * @param S: A list of integers
     * @return: An integer
     */
    int computerArea(int left, int right, vector<int>& heights){
        return (right - left) * min(heights[left], heights[right]);
    }
    int maxArea(vector<int> &S) {
        // write your code here
        int left = 0, ans = 0;
        int right = S.size() - 1;
        
        
        while(left < right){
            ans = max(ans, computerArea(left, right, S));
            if(S[left] <= S[right]){
                left++;
            }else{
                right--;
            }
        }
        
        return ans;
    }
};