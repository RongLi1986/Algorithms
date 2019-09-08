/*Build Post Office II

Given a 2D grid, each cell is either a wall 2, an house 1 or empty 0 (the number zero, one, two), find a place to build a post office so that the sum of the distance from the post office to all 
the houses is smallest.

Return the smallest sum of distance. Return -1 if it is not possible.

 Notice

You cannot pass through wall and house, but can pass through empty.
You only build post office on an empty.

Example
Given a grid:

0 1 0 0 0
1 0 0 2 1
0 1 0 0 0
return 8, You can build at (1,1). (Placing a post office at (1,1), the distance that post office to all the house sum is smallest.)
*/

/*
bfs
*/

class Solution {
public:
    /**
     * @param grid a 2D grid
     * @return an integer
     */
    struct InfoNode {
        int sum, time;
        InfoNode() :
            sum(0), time(0) {}
    };
    int EMPTY = 0;
    int HOUSE = 1;
    int WALL = 2;
    int m, n;
    // delta directions
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int shortestDistance(vector<vector<int>>& grid) {
       m = grid.size();
       if (m == 0)
           return -1;
       n = grid[0].size();
       if (n == 0)
           return -1;
            
       int numHouse = 0;
       vector<vector<InfoNode>> mapInfo(m, vector<InfoNode>(n, InfoNode()));
       for (int i = 0; i < m; ++i)
           for (int j = 0; j < n; ++j)
               if (grid[i][j] == HOUSE) {
                   numHouse++;
                   bfsHelper(grid, i, j, mapInfo);
               }
       
       int minDistanceSum = INT_MAX;
       for (int i = 0; i < m; ++i)
           for (int j = 0; j < n; ++j)
               if (grid[i][j] == EMPTY && mapInfo[i][j].time == numHouse)
                   minDistanceSum = min(minDistanceSum, mapInfo[i][j].sum);
       
       if (minDistanceSum == INT_MAX)
           return -1;
       return minDistanceSum;
    }
    void bfsHelper(vector<vector<int>>& grid, int x, int y, 
                vector<vector<InfoNode>>& mapInfo) {
       vector<vector<bool>> visited(m, vector<bool>(n, false));
       queue<Point> toVisit;
       toVisit.push(Point(x, y));
       
       int distance = 0;
       while (!toVisit.empty()) {
           int currentSize = toVisit.size();
           for (int i = 0; i < currentSize; ++i) {
               Point p = toVisit.front();
               toVisit.pop();
               
               if (grid[p.x][p.y] == EMPTY) {
                   mapInfo[p.x][p.y].time++;
                   mapInfo[p.x][p.y].sum += distance;
               }
               
               for (int j = 0; j < 4; ++j) {
                   int x = p.x + dx[j];
                   int y = p.y + dy[j];
                   
                   if (x < 0 || x >= m || y < 0 || y >= n)
                    continue;
                   
                   if (grid[x][y] == EMPTY && !visited[x][y]) {
                       visited[x][y] = true;
                       toVisit.push(Point(x, y));
                   }
               }
           }
           distance++;
       }  
    }
};