/*
Number of Islands

 Description
 Notes
 Testcase
 Judge
Given a boolean 2D matrix, 0 is represented as the sea, 1 is represented as the island. If two 1 is adjacent, 
we consider them in the same island. We only consider up/down/left/right adjacent.

Find the number of islands.


Example
Given graph:

[
  [1, 1, 0, 0, 0],
  [0, 1, 0, 0, 1],
  [0, 0, 0, 1, 1],
  [0, 0, 0, 0, 0],
  [0, 0, 0, 0, 1]
]
return 3.
*/

/*
dfs or bfs
*/

class Solution {
public:
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    int numIslands(vector<vector<bool>>& grid) {
        // Write your code here
        int islandCount=0;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==true){
                    islandCount++;
                    DFS(grid,i,j);
                }
            }
            
        return islandCount;
    }
    
    void DFS(vector<vector<bool>>& grid, int row,int col){
        if(grid[row][col]==false) return;
        
        grid[row][col]=false;
        
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
