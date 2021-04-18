# 73. Set Matrix Zeroes

## Question link
(https://leetcode.com/problems/set-matrix-zeroes/description/)

## Question Description

Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
Example 2:

Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

## 解题思路
do it in place

```c++
// use O(m + n) space
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> row;
        unordered_set<int> col;
        
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] == 0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        
        for(auto itr = row.begin(); itr != row.end(); itr++){
            for(int j = 0; j < matrix[*itr].size(); j++){
                matrix[*itr][j] = 0;
            }
        }
        
        for(auto itr = col.begin(); itr != col.end(); itr++){
            for(int i = 0; i < matrix.size(); i++){
                matrix[i][*itr] = 0;
            }
        }
        
        return;
    }
};

// use O(1) space
class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int cflag = 0;
        int rflag = 0;
        
        // do it in place : store data in mat
        for(int i = 0; i < mat.size(); i++){
            if(mat[i][0] == 0){
                    cflag = 1;
            }
        }
        
        for(int j = 0; j < mat[0].size(); j++){
            if(mat[0][j] == 0){
                    rflag = 1;
            }
        }
        
        // mark 0 in first row and col
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[i].size(); j++){
                if(mat[i][j] == 0){
                    mat[i][0] = 0;
                    mat[0][j] = 0;
                }
            }
        }
        
        // set zero
        for(int i = 1; i < mat.size(); i++){
            for(int j = 1; j < mat[i].size(); j++){
                if(mat[i][0] == 0 || mat[0][j] == 0){
                    mat[i][j] = 0;
                }
            }
        }
        
        //set zero in first col and row
        if(rflag == 1){
            for(int j = 0; j < mat[0].size(); j++){
                mat[0][j] = 0;
            }
        }
        
        if(cflag == 1){
            for(int i = 0; i < mat.size(); i++){
                mat[i][0] = 0;
            }
        }
        
        
        return;
    }
};
```