# 57. Insert Interval

## Question link
(https://leetcode.com/problems/insert-interval/description/)

## Question Description

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

## 解题思路
see 56 merge sort 

```c++
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        intervals.push_back(newInterval);
        
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