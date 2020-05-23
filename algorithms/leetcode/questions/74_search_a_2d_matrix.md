# 74. Search a 2D Matrix

## Question link
(https://leetcode.com/problems/search-a-2d-matrix/description/)

## Question Description

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
Example 2:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false

## 解题思路

```c++
class Solution {
public:
    //O(m + n)
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        if(mat.size() == 0) return false;
        int i = 0;
        int j = mat[0].size() - 1;
        
        while( i < mat.size() && j >= 0){
            if(mat[i][j] == target)
                return true;
            else if(mat[i][j] < target){
                i++;
            }else{
                j--;
            }
        }
        
        return false;
    }
};
```