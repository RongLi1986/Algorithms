/*
Minimum Path Sum 
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

/*
DP:
Min[i][j] = min(Min[i-1][j], Min[i][j-1]) +A[i][j];
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
	int pathSum;

public:
	//recrusive
    int minPathSum(vector<vector<int> > &grid) {
        pathSum=0;
        
        int out=minPathSumWithIndex(grid,grid.size()-1,grid[0].size()-1);

        return out;
    }

    int minPathSumWithIndex(vector<vector<int> > &grid, int mRow, int mCol){
    	if(mRow==0&&mCol==0){
    		pathSum+=grid[mRow][mCol];
    	}else if(mRow==0){
    		pathSum+=grid[mRow][mCol]+minPathSumWithIndex(grid,mRow,mCol-1);
    	}else if(mCol==0){
        	pathSum+=grid[mRow][mCol]+minPathSumWithIndex(grid,mRow-1,mCol);    
    	}else{
	    	pathSum+=grid[mRow][mCol]+min(minPathSumWithIndex(grid,mRow-1,mCol),minPathSumWithIndex(grid,mRow,mCol-1));	    	
    	}

    	return pathSum;
    } 

    //DP iterative
    int minPathSum(vector<vector<int> > &grid) {
    	int row=grid.size();
    	int col=grid[0].size();

    	int minArray[row][col];

    	minArray[0][0]=grid[0][0];

    	int i=1;
    	int j=1;
    	for(i;i<row;i++)
    		minArray[i][0]=minArray[i-1][0]+grid[i][0];

    	for(j;j<col;j++)
    		minArray[0][j]=minArray[0][j-1]+grid[0][j];

    	for(i=1;i<row;i++)
    		for(j=1;j<col;j++){
    			minArray[i][j]=min(minArray[i-1][j],minArray[i][j-1])+grid[i][j];
    		}

    	return minArray[row-1][col-1];
    }
};