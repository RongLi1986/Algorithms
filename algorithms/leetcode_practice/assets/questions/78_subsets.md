# 78. Subsets

## Question link
(https://leetcode.com/problems/subsets/description/)

## Question Description

Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

## 解题思路
```c++
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > out;
        vector<int> sub;

        out.push_back(sub);

        findSubsets(S, 0, sub, out);

        return out;
    }

    void findSubsets(vector<int> &S, int startIndex, vector<int>& sub, vector<vector<int> >& out){
        if(startIndex == S.size()){
            return;
        }

        for(int i = startIndex; i < S.size(); i++){
            sub.push_back(S[i]);
            out.push_back(sub);
            findSubsets(S, i + 1, sub, out);
            sub.pop_back();
        }
    }
};
```