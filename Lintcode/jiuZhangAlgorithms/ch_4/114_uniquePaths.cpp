/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
*/

#include <iostream>
using namespace std;

/*
create a map m X n
for each block, it means total paths which could make robot to here.
for (0,0) it is 1, first col f(x, 0) = f(x-1, 0) and fisrt row f(0,y) = f(0, y-1) 
and for f(x, y) = f(x-1, y) + f(x, y-1);
*/

class Solution {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        // wirte your code here
        vector<int> tmp(n,0);
        vector<vector<int> > pathMap(m,tmp);
        
        for(int i=0;i<n;i++){
            pathMap[0][i]=1;
        }
        
        for(int i=0;i<m;i++){
            pathMap[i][0]=1;
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                pathMap[i][j]=pathMap[i-1][j]+pathMap[i][j-1];
            }
        }
        
        return pathMap[m-1][n-1];
    }
};

int main(){

	return 0;
}