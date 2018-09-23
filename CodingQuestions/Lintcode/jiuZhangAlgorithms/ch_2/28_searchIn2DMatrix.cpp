/*
Write an efficient algorithm that searches for a value in an m x n matrix.

This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.


Consider the following matrix:

[
    [1, 3, 5, 7],
    [10, 11, 16, 20],
    [23, 30, 34, 50]
]
Given target = 3, return true.
*/

#include <iostream>
using namespace std;

/*
convert 2d matrix into a 1d array + binary search
O(lgn)
 */

class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        if(matrix.empty()) return false;
        
        int left = 0;
        int right = matrix.size()*matrix[0].size()-1;
        
        while (left <= right) {
            int mid = ( left + right) / 2;
            
            //convert 1d array to 2d array
            int row = mid/matrix[0].size();
            int col = mid%matrix[0].size();
            
            if( matrix[row][col] == target ) {
                return true;
            }else if( matrix[row][col] < target )
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        return false;
    }
};

int main(){

	return 0;
}