/*
Dungeon Game 

The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.


Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.

-2 (K)  -3      3
-5      -10     1
10      30      -5 (P)

Notes:

The knight's health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.
*/


/*
this is 2D DP question

transfer equation is: 
    lifeNeed[row][col]= max(1,(min(life[row+1][col],life[row][col+1])-dungeon[row][col]))
    lifeNeed[lastRow][lastCol]=1;
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
 
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if(dungeon.empty()) return 0;
        int row=dungeon.size();
        int col=dungeon[0].size();
        vector<int> tmp(col,0);
        vector<vector<int> > lifeMap(row,tmp);
        
        int life=1;
        //inital most left col
        for(int i=row-1;i>=0;i--){
            lifeMap[i][col-1]=max(1,(life-dungeon[i][col-1]));
            life=lifeMap[i][col-1];
        }
        
        life=1;
        //inital last row
        for(int i=col-1;i>=0;i--){
            lifeMap[row-1][i]=max(1,(life-dungeon[row-1][i]));
            life=lifeMap[row-1][i];
        }
        
        
        //build lifeMap
        for(int i=row-2;i>=0;i--){
            for(int j=col-2;j>=0;j--){
                life=min(lifeMap[i+1][j],lifeMap[i][j+1]);
                lifeMap[i][j]=max(1,(life-dungeon[i][j]));
            }
        }
        
    
        return lifeMap[0][0];
    }
}; 


class Solution_old {
public:
    int calculateMinimumHP(vector<vector<int> >& dungeon) {
        if(dungeon.empty()) return 0;
        int row=dungeon.size();
        int col=dungeon[0].size();
 
        vector<vector<int> > need(row,vector<int>(col,0));
 
 
        //back tracking
        need[row-1][col-1]=max(-dungeon[row-1][col-1]+1,1);
        
 
        //row=row-1;
        for(int i=col-2;i>=0;i--){ 
            need[row-1][i]=max(-dungeon[row-1][i]+need[row-1][i+1],1);
        }
 
        //col=col-1
        for(int i=row-2;i>=0;i--){ 
            need[i][col-1]=max(-dungeon[i][col-1]+need[i+1][col-1],1);  
        }
 
        for(int i=row-2;i>=0;i--){
            for(int j=col-2;j>=0;j--){
                if(need[i+1][j]>=need[i][j+1]){
                    need[i][j]=max(-dungeon[i][j]+need[i][j+1],1);        
                }else{
                    need[i][j]=max(-dungeon[i][j]+need[i+1][j],1);     
                }
            }
        }
        
        /* 
        for(int i=0;i<need.size();i++){
            for(int j=0;j<need[0].size();j++){
                cout<<need[i][j]<<" ";
            }
            cout<<endl;
        }
        */
         
        return need[0][0];
    }
};
 
int main(){
    /*
    vector<int> row1={1,-3,-3};
    vector<int> row2={0,-2,0};
    vector<int> row3={-3,-3,-3};
 
    vector<vector<int> > dungeon;
    dungeon.push_back(row1);
    dungeon.push_back(row2);
    dungeon.push_back(row3);
 
    Solution s;
    cout<<s.calculateMinimumHP(dungeon)<<endl;
    */
    return 0;
}