# 77. Combinations

## Question link
(https://leetcode.com/problems/combinations/description/)

## Question Description

Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]


## 解题思路

```c++
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > out;
        vector<int> path;
        helper(path, 1, n, k, out);

        return out;
    }

    void helper(vector<int>& path, int index, int n, int k, vector<vector<int> >& out){
    	if(k == 0) {
    		out.push_back(path);
            return;
    	}

    	for(int i = index; i <= n; i++){
	    	path.push_back(i);
	    	helper(path, i + 1, n, k - 1, out);
	    	path.pop_back();
    	}

    	return;
    }
};
```