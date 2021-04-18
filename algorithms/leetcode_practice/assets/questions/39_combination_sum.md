# 39. Combination Sum

## Question link
(https://leetcode.com/problems/combination-sum/description/)

## Question Description

Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]

## 解题思路

```c++
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        helper(candidates, target, path, 0, 0, ans);
        
        return ans;
    }
    
    void helper(vector<int>& candidates, int target, vector<int>& path, int index, int sum, vector<vector<int>>& ans){
        if(sum == target){
            ans.push_back(path);
            return;
        }
        
        int i = index;
        while(i<candidates.size()){
            if(sum + candidates[i] <= target){
                path.push_back(candidates[i]);
                helper(candidates, target, path, i, sum + candidates[i], ans);
                path.pop_back();
            }
            i++;
        }
        
        return;
    }
};
```