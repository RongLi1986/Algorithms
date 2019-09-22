/*******************************************************
477 Surrounded Regions

Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O''s into 'X''s in that surrounded region.

Example
Example 1:

Input:
  X X X X
  X O O X
  X X O X
  X O X X
Output:
  X X X X
  X X X X
  X X X X
  X O X X
********************************************************/

/*
DFS
*/ 

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if(board.size()<3 || board[0].size()<3) return;
        fillBorders(board, 'O', 'Y');
        replace(board, 'O', 'X');
        fillBorders(board, 'Y', 'O');
    }
    
    void fill(vector<vector<char>> &board, int i, int j, char target, char c) {
        int m = board.size(), n = board[0].size();
        if(i<0 || j<0 || i>=m || j>=n || board[i][j] != target) return;
        stack<pair<int,int>> s;
        s.push(make_pair(i,j));
        
        while(!s.empty()) {
            i = s.top().first;
            j = s.top().second;
            s.pop();
            board[i][j] = c;
            if(i>0 && board[i-1][j]==target) s.push(make_pair(i-1,j));
            if(i<m-1 && board[i+1][j]==target) s.push(make_pair(i+1,j));
            if(j>0 && board[i][j-1]==target) s.push(make_pair(i,j-1));
            if(j<n-1 && board[i][j+1]==target) s.push(make_pair(i,j+1));
        }
    }
    
    void fillBorders(vector<vector<char>> &board, char target, char c) {
        int m = board.size(), n = board[0].size();
        for(int i=0; i<m; i++) {
            if(board[i][0]==target) fill(board, i, 0, target, c);
            if(board[i][n-1]==target) fill(board, i, n-1, target, c);
        }
        
        for(int j=1; j<n-1; j++) {
            if(board[0][j]==target) fill(board, 0, j, target, c);
            if(board[m-1][j]==target) fill(board, m-1, j, target, c);
        }
    }
    
    
    void replace(vector<vector<char>> &board, char target, char c) {
        int m = board.size(), n = board[0].size();
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j]==target)
                    board[i][j] = c;
            }
        }
    }
};