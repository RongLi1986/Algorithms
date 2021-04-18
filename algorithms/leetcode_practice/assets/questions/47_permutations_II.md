# 47 Permutations II

## Question link
(https://leetcode.com/problems/permutations-ii/description/)

## Question Description

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

## 解题思路
permutations + (sort array and avoid duplicate)

```c++
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        vector<int> tmp;
        vector<vector<int> > out;
        vector<int> map(nums.size(), 0);
        sort(nums.begin(), nums.end());
        recursivePermute(nums, tmp, map, out);
        
        return out;
    }
    
    void recursivePermute(vector<int>& nums, vector<int>& tmp, vector<int> map, vector<vector<int> >& out){
        if(tmp.size() == nums.size()){
            out.push_back(tmp);
        }
        int i = 0;
        while(i < nums.size()){
            if(map[i] == 0){
                map[i] = 1;
                tmp.push_back(nums[i]);
                recursivePermute(nums, tmp, map, out);
                tmp.pop_back();
                map[i] = 0;
                while(i < nums.size() - 1 && nums[i] == nums[i+1]) i++;   
            }
            i++;
        }
    } 
};
```