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

#include <iostream>
using namespace std;

/*
from left bottom corner to right top corner

the numbers which in same col is smaller than current one,
and the numbers which in same row is larger than current one.
*/

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        
        if(matrix.empty()) return 0;
        int sum = 0;
        int row = matrix.size()-1;
        int col = 0;
        
        while(row >= 0 && col <= matrix[0].size()-1){
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
};


int main(){

	return 0;
}