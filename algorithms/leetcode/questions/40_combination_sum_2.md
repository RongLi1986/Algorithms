# 40. Combination Sum 2

## Question link
(https://leetcode.com/problems/combination-sum-ii/description/)

## Question Description

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]

## 解题思路
avoid duplicate results


```c++
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, path, 0, 0, ans);
        
        return ans;
    }
    
    void helper(vector<int>& candidates, int target, vector<int>& path, int index, int sum, vector<vector<int>>& ans){
        if(sum == target){
            ans.push_back(path);
            return;
        }
        
        int i = index;
        while(i < candidates.size()){
            if(sum + candidates[i] <= target){
                path.push_back(candidates[i]);
                helper(candidates, target, path, i + 1, sum + candidates[i], ans);
                path.pop_back();
                //avoid duplicate result
                while(i < candidates.size() - 1 && candidates[i] == candidates[i + 1]) i++;
            }
            i++;
        }
        
        return;
    }
};
```