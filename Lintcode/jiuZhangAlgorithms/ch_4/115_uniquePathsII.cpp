/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.
*/

#include <iostream>
using namespace std;

/*
create a map m X n
for each block, it means total paths which could make robot to here.
for (0,0) it is 1, first col f(x, 0) = f(x-1, 0) and fisrt row f(0,y) = f(0, y-1) 
and for f(x, y) = f(x-1, y) + f(x, y-1);

for obstacles it == 0 
*/

class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */ 
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // wirte your code here
        int n = obstacleGrid[0].size();
        int m = obstacleGrid.size();
        
        vector<int> tmp(n,0);
        vector<vector<int> > pathMap(m,tmp);
        
        for(int i=0;i<n;i++){
            if(obstacleGrid[0][i]!=1)
                pathMap[0][i]=1;
            else
                break;
        }
        
        for(int i=0;i<m;i++){
            if(obstacleGrid[i][0]!=1)
                pathMap[i][0]=1;
            else
                break;
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]!=1)
                    pathMap[i][j]=pathMap[i-1][j]+pathMap[i][j-1];
                else
                    pathMap[i][j]=0;
            }
        }
        
        return pathMap[m-1][n-1];
    }
};

int main(){

	return 0;
}