/*Search a 2D Matrix II Total Accepted: 2114 Total Submissions: 7159 My Submissions Question Solution 
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
*/

/*
normal solution is O(n*lgn)

but it has a solution: O(m+n)
for each row compare last value with target.
if target > last value.  row ++
else col --

本质：如果target小于当前行和列的value。。一定小于后面行的相同列的值！
*/

#include <iostream>
using namespace std;

//0(m+n)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(), n=matrix[0].size(), i=0, j=n-1;
        while (i<m && j>=0) {
            if (matrix[i][j]==target) return true;
            else if (matrix[i][j]<target) i++;
            else j--;
        }
        return false;
    }
};

//O(n*lgn)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i=0;i<matrix.size();i++){
            if(target>=matrix[i][0]&&target<=matrix[i][matrix[i].size()-1]){
                //cout<<i<<endl;
                int left=0;
                int right=matrix[i].size()-1;
                while(left<=right){
                    int mid=(left+right)/2;
                    if(matrix[i][mid]==target) 
                        return true;
                    if(matrix[i][mid]>target)
                        right=mid-1;
                    else
                        left=mid+1;
                }
            }
        }
                    
        return false;
    }
};

int main(){

	return 0;
}