# 79. Word Search

## Question link
(https://leetcode.com/problems/word-search/description/)

## Question Description

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.

Constraints:

board and word consists only of lowercase and uppercase English letters.
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3

## 解题思路
dfs matrix

```c++
class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        int r = board.size();
        int c = board[0].size();

        if(r * c < word.size()) return false;

        vector<vector<int> > visit(r, vector<int>(c, 0));

        for(int i = 0; i < r; i++){
            for(int j = 0;j < c; j++){
                if(board[i][j] == word[0]){
                    if(checkNext(board,r,c,visit,word,0, i, j))
                        return true;
                }
            }
        }
    
        return false;
    }

    bool checkNext(vector<vector<char> > &board, int rLen, int cLen, vector<vector<int> > &visit, string& word, int index, int row, int col){
        if((row < 0 || row >= rLen) || (col < 0 || col >= cLen) 
           || visit[row][col] == 1 || board[row][col] != word[index]){
            return false;
        }
           
        if(index == word.size() - 1) return true;
        
        visit[row][col] = 1;
        
        vector<vector<int> > dirs = {{1,0},{0,1},{-1,0},{0,-1}};
        
        for(int i = 0; i < 4; i++){
            if(checkNext(board, rLen, cLen, visit, word, index + 1, row + dirs[i][0], col + dirs[i][1]))
                return true;
        }
        
        visit[row][col] = 0;

        return false;
    }
};
```