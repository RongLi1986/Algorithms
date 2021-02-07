# 90. Subsets II

## Question link
(https://leetcode.com/problems/subsets-ii/)

## Question Description
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:

> Input: nums = [1,2,2]
> Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Example 2:

> Input: nums = [0]
> Output: [[],[0]]

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10

## 解题思路
dfs + backtracking

## Code
```c++
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > out;
        sort(S.begin(),S.end());

        vector<int> sub;
        out.push_back(sub);

        findSubsets(S, 0, sub, out);

        return out;
    }

    void findSubsets(vector<int> &S, int startIndex, vector<int>& sub, vector<vector<int> >& out){
        if(startIndex == S.size()){
            return;
        }
        
        int i = startIndex;
        while(i < S.size()){
            sub.push_back(S[i]);
            out.push_back(sub);
            findSubsets(S, i + 1, sub, out);
            sub.pop_back();
            i++;
            while(i < S.size() && S[i] == S[i-1]) i++; //avoid duplicates
        }
    }
};
```