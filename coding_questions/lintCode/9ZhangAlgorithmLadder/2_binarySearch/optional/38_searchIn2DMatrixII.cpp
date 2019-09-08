/*
Write an efficient algorithm that searches for a value in an m x n matrix, return the occurrence of it.

This matrix has the following properties:

Integers in each row are sorted from left to right.
Integers in each column are sorted from up to bottom.
No duplicate integers in each row or column.
Have you met this question in a real interview? Yes
Example
Consider the following matrix:

[
  [1, 3, 5, 7],
  [2, 4, 7, 8],
  [3, 5, 9, 10]
]
Given target = 3, return 2.
*/

int searchMatrixII(int[][] matrix, int target) {
    // write your code here
    int sum = 0;
    int row = matrix.length-1;
    int col = 0;

    while(row >= 0 && col <= matrix[0].length-1){
        if(matrix[row][col]==target){
            sum++;
            row--;
            col++;
        }else if(matrix[row][col]<target){
            col++;
        }else{
            row--;
        }
    }

    return sum;
}