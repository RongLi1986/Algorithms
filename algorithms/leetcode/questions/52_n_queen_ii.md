# 51. N-Queens

## Question link
(https://leetcode.com/problems/n-queens/description/)

## Question Description

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

![Image](https://assets.leetcode.com/uploads/2018/10/12/8-queens.png)

Given an integer n, return the number of distinct solutions to the n-queens puzzle.

Example:

Input: 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]


## 解题思路
dfs + backtracking

```c++
class Solution {
public:
    int totalNQueens(int n) {
        int ret = 0;
        std::vector<std::string> nQueens(n, std::string(n, '.'));
        solveNQueens(ret, nQueens, 0, n);
        return ret;
    }

private:
    void solveNQueens(int &res, std::vector<std::string> &nQueens, int row, int &n) {
        if (row == n) {
            res++;
            return;
        }
        for (int col = 0; col != n; ++col)
            if (isValid(nQueens, row, col, n)) {
                nQueens[row][col] = 'Q';
                solveNQueens(res, nQueens, row + 1, n);
                nQueens[row][col] = '.';
            }
    }
    
    bool isValid(std::vector<std::string> &nQueens, int row, int col, int &n) {
        //check if the column had a queen before.
        for (int i = 0; i != row; ++i)
            if (nQueens[i][col] == 'Q')
                return false;
        //check if the 45° diagonal had a queen before.
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
            if (nQueens[i][j] == 'Q')
                return false;
        //check if the 135° diagonal had a queen before.
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
            if (nQueens[i][j] == 'Q')
                return false;
        return true;
    }
};
```