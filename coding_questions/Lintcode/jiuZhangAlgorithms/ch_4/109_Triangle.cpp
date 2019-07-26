/*
Given a triangle, 
find the minimum path sum from top to bottom. 
Each step you may move to adjacent numbers on the row below.

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
*/

#include <iostream>
using namespace std;

/*
DP
for f(x, y) = min(f(x-1,y -1), f(x -1, y)) + triangle(x,y);
if( y==0) 
  f(x, y) = f(x -1, y) + triangle(x,y);
else if(y ==  colSize-1)
  f(x, y) = f(x-1,y -1) + triangle(x,y);
else
  f(x, y) = min(f(x-1,y -1), f(x -1, y)) + triangle(x,y);
*/

class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        // write your code here
        vector<vector<int> > triangleMap= triangle;
        
        for(int i=1;i<triangleMap.size();i++){
            for(int j=0;j<triangleMap[i].size();j++){
                if ( j == 0 ){
                    triangleMap[i][j] = triangleMap[i][j] + triangleMap[i-1][j];
                }else if( j == triangleMap[i].size()-1){
                    triangleMap[i][j] = triangleMap[i][j] + triangleMap[i-1][j-1];
                }else
                    triangleMap[i][j]=triangleMap[i][j] + min(triangleMap[i-1][j], triangleMap[i-1][j-1]);
            }
        }
        
        int min=INT_MAX;
        for(int i=0; i<triangleMap[triangleMap.size()-1].size();i++ ){
            if(min>triangleMap[triangleMap.size()-1][i])
                min=triangleMap[triangleMap.size()-1][i];
        }
        
        return min;
    }
};



int main(){

	return 0;
}