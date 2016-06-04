/*
Given a m x n grid filled with non-negative numbers, 
find a path from top left to bottom right which minimizes 
the sum of all numbers along its path.
*/

#include <iostream>
using namespace std;

/*
create a map m X n
for each block, it means min sum value from start to here.
for (0,0) it is 1, first col f(x, 0) += f(x-1, 0) and fisrt row f(0,y) += f(0, y-1) 
and for f(x, y) = min(f(x-1, y) ,f(x, y-1)) + local(x,y);
*/

class Solution {
public:
    /**
     * @param grid: a list of lists of integers.
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int> > &grid) {
        // write your code here
        // wirte your code here
        if(grid.empty()) return 0;
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<int> > map(row, vector<int>(col,0));
        
        map[0][0]=grid[0][0];
        
        for(int i = 1;i < row;i++){
           map[i][0]+=map[i-1][0] + grid[i][0];
        }
        
        for(int j = 1;j < col;j++){
           map[0][j]+=map[0][j-1] + grid[0][j];
        }
        
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                map[i][j] = min(map[i-1][j],map[i][j-1]) + grid[i][j];
            }
        }
       
        return map[row-1][col-1];
    }
};


int main(){

	return 0;
}