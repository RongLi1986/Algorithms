/*
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
Note:
You may assume that the matrix does not change.
There are many calls to sumRegion function.
You may assume that row1 ≤ row2 and col1 ≤ col2.
Subscribe to see which 
*/

#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
vector<vector<int>> sum;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if(!matrix.empty()){
            sum.resize(matrix.size());
            for(int i=0;i<sum.size();i++){
                sum[i].resize(matrix[i].size());
            }
            
            
            sum[0][0]=matrix[0][0];
            
            for(int i=1;i<matrix[0].size();i++){
                sum[0][i]=sum[0][i-1]+matrix[0][i];
            }
            
            for(int i=1;i<matrix.size();i++){
                sum[i][0]=sum[i-1][0]+matrix[i][0];
            }
            
            
            for(int i=1;i<matrix.size();i++){
                for(int j=1;j<matrix[0].size();j++){
                    sum[i][j]=matrix[i][j]+sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1];
                }
            }
        }
        
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        //cout<<row1<<col1<<row2<<col2<<endl;
        if(sum.empty()) return 0;
        //cout<<1<<endl;
        if(row1==0 && col1==0) return sum[row2][col2];
        //cout<<2<<endl;
        if(row1==0) return sum[row2][col2]-sum[row2][col1-1];
        //cout<<3<<endl;
        if(col1==0) return sum[row2][col2]-sum[row1-1][col2];
        //cout<<4<<endl;
        
        
        int result=sum[row2][col2]-sum[row1-1][col2]-sum[row2][col1-1]+sum[row1-1][col1-1];
        
        return result;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);

int main(){
    
    return 0;
}