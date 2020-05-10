# 56. Merge Intervals

## Question link
(https://leetcode.com/problems/merge-intervals/description/)

## Question Description

Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

## 解题思路
sort list and merge it.

```c++
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(intervals.empty()) return res;

        // sort list by start value
        sort(intervals.begin(), intervals.end(),
             [this](const vector<int>& a, const vector<int>& b) -> bool{ return a[0] < b[0]; }
            );

        int i = 1;  // for intervals travsal, start from 1 since we push first element in out;
        int j = 0;  // for out travals
        res.push_back(intervals[0]);
        
        while(i < intervals.size()){
            if(res[j][1] >= intervals[i][0]){
               if(res[j][1] < intervals[i][1]){
                  res[j][1] = intervals[i][1];
               }
            }else{ //no overlap
               res.push_back(intervals[i]);
               j++;
            }
            i++;
        }

        return res;
    }
};
```