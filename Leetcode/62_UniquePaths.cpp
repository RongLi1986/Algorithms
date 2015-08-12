/*
Unique Paths 
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
*/


#include <iostream>
using namespace std;

/*
DP solution:
Step[i][j] = Step[i-1][j] + Step[i][j-1];
Step's first row and col is 1;
return Step[m-1][n-1]
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
	//return c (m+n) n
        int step[m][n];

        for(int i=0;i<m;i++)
            step[i][0]=1;


        for(int j=0;j<n;j++)
            step[0][j]=1;

        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++){
                step[i][j]=step[i-1][j]+step[i][j-1];
            }

        return step[m-1][n-1]; 
    }
};

int main(){
	Solution s;
	//cout<<s.cacu()<<endl;
	//cout<<s.cacu(7)<<endl;
	cout<<s.uniquePaths(2,3)<<endl;

	return 0;
}