# 37. Sudoku Solver

## Question link
(https://leetcode.com/problems/sudoku-solver/)

## Question Description
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

Example 1:

> ![Image](https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png)

> Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
> Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]

Explanation: The input board is shown above and the only valid solution is shown below:

> ![Image](https://upload.wikimedia.org/wikipedia/commons/thumb/3/31/Sudoku-by-L2G-20050714_solution.svg/250px-Sudoku-by-L2G-20050714_solution.svg.png)

Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit or '.'.
It is guaranteed that the input board has only one solution.

## 解题思路
dfs

## Code
```c++
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solveSudokuRecursive(board, 0, 0);
    } 

    bool solveSudokuRecursive(vector<vector<char>>& board, int row, int col){
        if(row == 9) return true;

        if(board[row][col] != '.'){
            if(col == 8)
                return solveSudokuRecursive(board, row + 1, 0);
            else
               return solveSudokuRecursive(board, row, col + 1);
        }

        for(int k = 1; k < 10; k++){
            board[row][col] = '0' + k;
            if(isValid(board, row, col)){
                if(col == 8){
                    if(solveSudokuRecursive(board, row + 1, 0))
                        return true;  
                }else{ 
                    if(solveSudokuRecursive(board, row, col + 1))
                        return true;
                }
            }
        }

        board[row][col] = '.';
        return false;

    }

    bool isValid(vector<vector<char>> &board, int irow, int icol) {
        char val = board[irow][icol];
        if(val - '0' < 1 || val - '0' > 9) return false;
        
        // check row & col
        for(int i = 0; i < 9; i++) {
            if(board[irow][i] == val && i != icol) return false;
            if(board[i][icol] == val && i != irow) return false;
        }
        
        //check 3x3 box
        int irow0 = irow / 3 * 3;
        int icol0 = icol / 3 * 3;
        for(int i = irow0; i < irow0 + 3; i++) {
            for(int j = icol0; j < icol0 + 3; j++) {
                if(board[i][j] == val && (i != irow || j != icol)) 
                    return false;
            }
        }
        
        return true;
    }
};
```

## Time Complexity Analysis
Running time  : 
running space : 