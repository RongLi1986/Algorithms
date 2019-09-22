/*******************************************************
 200. Number of Islands


Share
Given a 2d grid map of '1's (land) and '0's (water), 
count the number of islands. An island is surrounded by water 
and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
********************************************************/


/*
UnionFind
O(n)
*/ 
class UnionFind
{
private:
    unordered_map<int, int> parent;
    int count = 0;
public:
    UnionFind(){
        
    };

    UnionFind(vector<vector<char>>& grid){
        int col = grid[0].size();
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') count++;
            }
        }

        for(int i = 0;i < grid.size();i++){
            for(int j = 0;j < grid[0].size();j++){
                if(grid[i][j] == '1'){
                    int p = i * col + j;
                    parent[p] = p;
                }
            }
        }
    }

    int find(int x){
        int p = x;
        while(p != parent[p]){
            p = parent[p]
        }
        return p;
    }

    void union(int x, int y){
        int f_x = find(x);
        int f_y = find(y);
        if(f_x != f_y){
            parent[f_x] = f_y;
            count--;
        }
    }

    bool isConnected(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);
        if(pRoot != qRoot) return false;
        else return true;
    }

};

//union find
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        int row = grid.size(), col = grid[0].size();
        UnionFind* uf = new UnionFind(grid);
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == '0') continue;
                int p = i * col + j;
                int q;
                if(i > 0 && grid[i - 1][j] == '1') {
                    q = p - col;
                    uf.union(p, q);
                }
                if(i < m - 1 && grid[i + 1][j] == '1') {
                    q = p + col;
                    uf.union(p, q);
                }
                if(j > 0 && grid[i][j - 1] == '1') {
                    q = p - 1;
                    uf.union(p, q);
                }
                if(j < n - 1 && grid[i][j + 1] == '1') {
                    q = p + 1;
                    uf.union(p, q);
                }
            }
        }
        return uf->count;
    }
};