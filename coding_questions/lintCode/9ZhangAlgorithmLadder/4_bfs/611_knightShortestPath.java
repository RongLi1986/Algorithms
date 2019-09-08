/*
Given a knight in a chessboard (a binary matrix with 0 as empty and 1 as barrier) with a source position, 
find the shortest path to a destination position, return the length of the route. 
Return -1 if knight can not reached.


Clarification
If the knight is at (x, y), he can get to the following positions in one step:

(x + 1, y + 2)
(x + 1, y - 2)
(x - 1, y + 2)
(x - 1, y - 2)
(x + 2, y + 1)
(x + 2, y - 1)
(x - 2, y + 1)
(x - 2, y - 1)
Example
[[0,0,0],
 [0,0,0],
 [0,0,0]]
source = [2, 0] destination = [2, 2] return 2

[[0,1,0],
 [0,0,0],
 [0,0,0]]
source = [2, 0] destination = [2, 2] return 6

[[0,1,0],
 [0,0,1],
 [0,0,0]]
source = [2, 0] destination = [2, 2] return -1

*/

/*
bfs
*/

/**
 * Definition for a point.
 * public class Point {
 *     public int x, y;
 *     public Point() { x = 0; y = 0; }
 *     public Point(int a, int b) { x = a; y = b; }
 * }
 */
 


public class Solution {
    /**
     * @param grid a chessboard included 0 (false) and 1 (true)
     * @param source, destination a point
     * @return the shortest path 
     */
     
    private class pointCom {
        public Point a;
        public int level;
        public pointCom(Point a, int b) { this.a = a; level = b; }
    }
    
    public int shortestPath(boolean[][] grid, Point source, Point destination) {
        // Write your code here

        ArrayList<pointCom> queue = new ArrayList<pointCom>();
        //Point* tmp = &source
      
        //destination
        queue.add(new pointCom(source, 0));
        
        grid[source.x][source.y] = true;
        
        while(!queue.isEmpty()){
            pointCom ptrCom = queue.get(0);
            queue.remove(0);

            Point ptr = ptrCom.a;
            int x = ptr.x;
            int y = ptr.y;
            
            //System.out.println(x);
            //System.out.println(y);
            
            if(x == destination.x && y == destination.y)
                return ptrCom.level;
            
            
            if(x-2>=0 && y+1<=grid[x].length-1){ 
                if(grid[x-2][y+1]== false){
                grid[x-2][y+1]=true;
                Point tmp = new Point(x-2,y+1);
                queue.add(new pointCom(tmp, ptrCom.level+1));
                }
            }
            
            if(x+1<=grid.length-1&& y+2<=grid[x].length-1){
                if(grid[x+1][y+2]==false){
                grid[x+1][y+2]=true;
                Point tmp = new Point(x+1,y+2);
                queue.add(new pointCom(tmp, ptrCom.level+1));
                }
            }
            
            if(x-1>=0 && y-2>=0){
                if(grid[x-1][y-2]==false){
                grid[x-1][y-2]=true;
                Point tmp = new Point(x-1, y-2);
                queue.add(new pointCom(tmp, ptrCom.level+1));
                }
            }
            
            if(x+2<=grid.length-1&&y-1>=0){
                if(grid[x+2][y-1]==false){
                grid[x+2][y-1]=true;
                Point tmp = new Point(x+2,y-1);
                queue.add(new pointCom(tmp, ptrCom.level+1));
                }
            }
            
            
            //
            if(x-2>=0 && y-1>=0){ 
                if(grid[x-2][y-1]== false){
                grid[x-2][y-1]=true;
                Point tmp = new Point(x-2,y-1);
                queue.add(new pointCom(tmp, ptrCom.level+1));
                }
            }
            
            if(x-1>=0&& y+2<=grid[x].length-1){
                if(grid[x-1][y+2]==false){
                grid[x-1][y+2]=true;
                Point tmp = new Point(x-1,y+2);
                queue.add(new pointCom(tmp, ptrCom.level+1));
                }
            }
            
            if(x+1<= grid.length-1&& y-2>=0){
                if(grid[x+1][y-2]==false){
                grid[x+1][y-2]=true;
                Point tmp = new Point(x+1, y-2);
                queue.add(new pointCom(tmp, ptrCom.level+1));
                }
            }
            
            if(x+2<=grid.length-1&&y+1<=grid[x].length-1){
                if(grid[x+2][y+1]==false){
                grid[x+2][y+1]=true;
                Point tmp = new Point(x+2,y+1);
                queue.add(new pointCom(tmp, ptrCom.level+1));
                }
            }
            
        }
        
        return -1;
    }
}