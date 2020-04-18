# 46. Permutations

## Question link
(https://leetcode.com/problems/permutations/description/)

## Question Description

Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

## 解题思路

```c++
class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<int> tmp;
        vector<vector<int> > out;
        vector<int> map(nums.size(), 0);

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
            }
            i++;
        }
    } 
};
```