# 64. Minimum Path Sum

## Question link
(https://leetcode.com/problems/minimum-path-sum/description/)

## Question Description

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.

## 解题思路

matrix DP questions

```c++
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int row = grid.size();
        int col = grid[0].size();
        
        int costMap[row][col];
        costMap[0][0] = grid[0][0];
        
        for(int i = 1; i < row; i++){
            costMap[i][0] = costMap[i-1][0]+grid[i][0];
        }
        
        for(int i = 1; i < col;i++){
            costMap[0][i] = costMap[0][i-1] + grid[0][i];
        }
        
        for(int i = 1;i < row;i++){
            for(int j = 1;j < col;j++){
                costMap[i][j] = min(costMap[i-1][j],costMap[i][j-1])+grid[i][j];
            }
        }
        
        return costMap[row-1][col-1];
    }
};
```