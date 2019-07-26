/*
Number of Islands Total Accepted: 828 Total Submissions: 3524 My Submissions Question Solution 
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3
*/

/*
solution is DFS + mark Visited node:

it looks like BFS, but it use recursive, so actually is DFS
TODO: what about use iterative way to do it? (queue)

for any 1 in map, change it to 0 (means it has already marked)
and islandCount++ , then run BFS from it.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>

using namespace std;

//optimize no visit map need
//change BFS name to DFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islandCount=0;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    islandCount++;
                    DFS(grid,i,j);
                }
            }
            
        return islandCount;
    }
    
    void DFS(vector<vector<char>>& grid, int row,int col){
        if(grid[row][col]=='0') return;
        
        grid[row][col]='0';
        
        //go up
        if(row>0)
            DFS(grid,row-1,col);
        
        //go down
        if(row<grid.size()-1)
            DFS(grid,row+1,col);
        
        //go left
        if(col>0)
            DFS(grid,row,col-1);
        
        //go right
        if(col<grid[0].size()-1)
            DFS(grid,row,col+1);
        
        return;
    }
};




//use visit map
class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        if(grid.empty()) return 0;
        int nRow=grid.size();
        int nCol=grid[0].size();
        int countInland=0;
        vector<int> tmp(nCol,0);
        vector<vector<int> > visitMap(nRow,tmp);

        for(int i=0;i<nRow;i++){
            for(int j=0;j<nCol;j++){
                if(grid[i][j]=='1' && visitMap[i][j]==0){
                    countInland++;
                    //cout<<i<<" "<<j<<endl;
                    BFS(grid,visitMap,i,j);
                }

            }
        }

        return countInland;

    }

    void BFS(vector<vector<char>> &grid,vector<vector<int>> &visitMap, int i, int j){
        if(i<0||i>grid.size()-1) return;
        if(j<0||j>grid[0].size()-1) return;
        //cout<<"BFS "<<i<<" "<<j<<endl;
        

        if(grid[i][j]=='1'){
            visitMap[i][j]=1;

            if(i<grid.size()-1){
                if(visitMap[i+1][j]==0) //down
                    BFS(grid,visitMap,i+1,j);
            }
            if(i>0){
                if(visitMap[i-1][j]==0) //up
                    BFS(grid,visitMap,i-1,j);
            }
            if(j<grid[0].size()-1){
                if(visitMap[i][j+1]==0) //right
                    BFS(grid,visitMap,i,j+1);
            }
            if(j>0){
                if(visitMap[i][j-1]==0) //left
                    BFS(grid,visitMap,i,j-1);
            }

        }

        return;
    }
};

int main(){
    Solution s;
    vector<char> tmp(5,'0');
    vector<char> tmp1={'1','1','1','1','1'};
    vector<vector<char>> grid(5, tmp1);
    

    cout<<s.numIslands(grid)<<endl;

	return 0;
}