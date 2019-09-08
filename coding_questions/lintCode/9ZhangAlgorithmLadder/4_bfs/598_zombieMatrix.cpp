/*
Zombie in Matrix

Given a 2D grid, each cell is either a wall 2, a zombie 1 or people 0 (the number zero, one, two).Zombies 
can turn the nearest people(up/down/left/right) into zombies every day, but can not through wall. How long
will it take to turn all people into zombies? Return -1 if can not turn all people into zombies.

Given a matrix:

0 1 2 0 0
1 0 0 2 1
0 1 0 0 0
return 2
*/

/*
bfs
*/

class Zombie{
public:
    int x;
    int y;
    Zombie(int a, int b){
        x = a;
        y = b;
    }
};

class Solution {
public:
    /**
     * @param grid  a 2D integer grid
     * @return an integer
     */
    int zombie(vector<vector<int>>& grid) {
        // Write your code here
        int people = 0;
        int days = 1;
        deque<Zombie*> queue;
        Zombie* dump = new Zombie(INT_MAX,INT_MAX);
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    people++;
                }
                
                if(grid[i][j]==1){
                    Zombie* tmp = new Zombie(i, j);
                    queue.push_back(tmp);
                }
            }
        }
        queue.push_back(dump);
        
        while(1){
            Zombie* tmp = queue.front();
            queue.pop_front();
            
            
            int x = tmp->x;
            int y = tmp->y;
            //cout<<x<<" "<<y<<endl;
            if(x == INT_MAX){
                days++;
                queue.push_back(tmp);
                if(queue.size()==1)
                    break;
                continue;
            }
            
            if(x!=0 && grid[x-1][y] == 0 ){
                grid[x-1][y] = 1;
                Zombie* tmp = new Zombie(x-1, y);
                queue.push_back(tmp);
                people--;
            }
            
            
            if(y!=0 && grid[x][y-1] == 0 ){
                grid[x][y-1] = 1;
                Zombie* tmp = new Zombie(x, y-1);
                queue.push_back(tmp);
                people--;
            }
            
            if(x!= grid.size()-1 && grid[x+1][y] == 0 ){
                grid[x+1][y] = 1;
                Zombie* tmp = new Zombie(x+1, y);
                queue.push_back(tmp);
                people--;
            }
            
            if(y!= grid[x].size()-1 && grid[x][y+1] == 0 ){
                grid[x][y+1] = 1;
                Zombie* tmp = new Zombie(x, y+1);
                queue.push_back(tmp);
                people--;
            }
            
            if(people == 0 )
                return days;
        }
        
        return -1;
        
    }
};