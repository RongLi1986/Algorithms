/*
329. Longest Increasing Path in a Matrix My Submissions Question
Total Accepted: 749 Total Submissions: 2415 Difficulty: Medium
Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Return 4
The longest increasing path is [1, 2, 6, 9].

Example 2:

nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

*/


/*
DFS+ dp
DFS scan matrix, using matrix to record path length for each item in matrix.
then find largest one
*/

#include <iostream>
#include <vector>

using namespace std;
class Solution {
private:
    int maxVal;
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty()) return 0;
        
        vector<int> tmp(matrix[0].size(),0);
        vector<vector<int> > history(matrix.size(),tmp);
        maxVal=-1;
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                dfs(matrix,history,i,j);
            }
        }
        
        /*
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                cout<<history[i][j]<<" ";
            }
            cout<<endl;
        }
        */
        
        return maxVal;
    }
    
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& history, int row, int col) {
        if(history[row][col] > 0) 
            return history[row][col];
    
        int l = 0, r = 0, u = 0, d = 0;
    
        if(row > 0) {
            if(matrix[row-1][col] > matrix[row][col]) 
                u = dfs(matrix, history, row - 1, col);
        }
        if(col > 0) {
            if(matrix[row][col-1] > matrix[row][col]) 
                l = dfs(matrix, history, row, col - 1);
        }
        if(row < matrix.size() - 1) {
            if(matrix[row+1][col] > matrix[row][col]) 
                d = dfs(matrix, history, row + 1, col);
        }
        if(col < matrix[0].size() - 1) {
            if(matrix[row][col+1] > matrix[row][col]) 
                r = dfs(matrix, history, row, col + 1);
        }
        
        //cout<<"row"<<row<<" col"<<col<<endl;
        //cout<<l<<" "<<u<<" "<<d<<" "<<r<<endl;
        
        history[row][col] = max(max(l, r), max(u, d)) + 1;
        //cout<<"history "<<history[row][col]<<endl;
        if(history[row][col]>maxVal) 
            maxVal=history[row][col];
        
        return history[row][col];
    }

};

int main(){
    
    return 0;
}
