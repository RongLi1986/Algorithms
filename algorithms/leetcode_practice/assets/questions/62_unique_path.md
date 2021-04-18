# 62. Unique Paths

## Question link
(https://leetcode.com/problems/unique-paths/description/)

## Question Description


A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 7 x 3 grid. How many possible unique paths are there?

 ![Image](https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png)

Example 1:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right


Example 2:

Input: m = 7, n = 3
Output: 28
 
Constraints:
1 <= m, n <= 100
It's guaranteed that the answer will be less than or equal to 2 * 10 ^ 9.

## 解题思路

matrix DP questions

```c++
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > pathNums(m,vector<int>(n, 0));
        pathNums[0][0] = 1;
        
        for(int i = 1;i < n; i++)
            pathNums[0][i] = 1;
        
        for(int i = 1;i < m; i++)
            pathNums[i][0] = 1;
            
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                pathNums[i][j] = pathNums[i-1][j] + pathNums[i][j-1];
            }
        }
        
        return pathNums[m-1][n-1];
    }
};
```