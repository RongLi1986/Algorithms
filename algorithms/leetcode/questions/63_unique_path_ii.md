# 63. Unique Paths II

## Question link
(https://leetcode.com/problems/unique-paths-ii/description/)

## Question Description

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

![Image](https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png)

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:

Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

## 解题思路

matrix DP questions

```c++
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1) return 0;
        
        vector<vector<int> > map(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(), 0));//col];
        map[0][0] = 1;
        
        for(int i = 1;i < obstacleGrid.size(); i++){
            if(obstacleGrid[i][0] == 1){
                map[i][0] = 0;
                break;
            }else{
                map[i][0] = 1;
            }
        }
        
        for(int i = 1;i < obstacleGrid[0].size(); i++){
            if(obstacleGrid[0][i]==1){
                map[0][i] = 0;
                break;
            }else{
                map[0][i] = 1;
            }
        }
        
        for(int i = 1;i < obstacleGrid.size(); i++){
            for(int j = 1;j < obstacleGrid[0].size(); j++){
                if(obstacleGrid[i][j] == 1)
                    map[i][j] = 0;
                else
                    map[i][j] = map[i][j-1] + map[i-1][j];
            }
        }
        
        return map[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }
};
```