/*
UniquePathII
Follow up for "Unique Paths":
Now consider if some obstacles are added to the grids. 
How many unique paths would there be?
An obstacle and empty space is marked as 1 and 0 respectively in the grid.
For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/


/*
DP: same with last question
but we need to check obstacle, if it == 1
our value should be zero;
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int sizeRow=obstacleGrid.size();
        int sizeCol=obstacleGrid[0].size();

        int step[sizeRow][sizeCol];

        if(obstacleGrid[0][0]==1)
            step[0][0]=0;
        else
            step[0][0]=1;

        for(int i=1;i<sizeRow;i++)
            if(obstacleGrid[i][0]==1)
                step[i][0]=0;
            else
                step[i][0]=step[i-1][0]; //tricky point


        for(int j=1;j<sizeCol;j++)
            if(obstacleGrid[0][j]==1)
                step[0][j]=0;
            else
                step[0][j]=step[0][j-1];

        for(int i=1;i<sizeRow;i++)
            for(int j=1;j<sizeCol;j++){

                if(obstacleGrid[i][j]==1)
                    step[i][j]=0;
                else
                    step[i][j]=step[i-1][j]+step[i][j-1];
            }

        return step[sizeRow-1][sizeCol-1]; 

    }
};

int main(){
	Solution s;
    vector<int> a={0,1,0};
    vector<int> b={0,0,0};
    vector<vector<int> > obstacleGrid;
    obstacleGrid.push_back(b);
    obstacleGrid.push_back(a);
    obstacleGrid.push_back(b);
	cout<<s.uniquePathsWithObstacles(obstacleGrid)<<endl;
	return 0;
}