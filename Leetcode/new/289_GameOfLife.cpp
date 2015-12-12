/*
Game of Life My Submissions Question
Total Accepted: 8603 Total Submissions: 26713 Difficulty: Medium
According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state.

Follow up: 
Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

*/

/*
how to do it in place??
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
vector<vector<int> > copyBoard;
public:
    void gameOfLife(vector<vector<int>>& board) {
        //conner case 
        if(board.empty()) return;
        
        //copy contents into copyBoard
        copyBoard.resize(board.size());
        for(int i=0;i<copyBoard.size();i++){
            copyBoard[i].resize(board[i].size());
            copyBoard[i]=board[i];
        }
        
        if(board.size()==1){
            if(board[0].size()==1) { //only one must die
                board[0][0]=0;
                return;
            }else{  //only one row
                for(int i=0;i<board[0].size();i++){
                    int sum=0;
                    if(i==0){ //first one{
                        sum=copyBoard[0][i+1];
                    }else if(i==board[0].size()-1){ //last one
                        sum=copyBoard[0][i-1];
                    }else{
                        sum=copyBoard[0][i-1]+copyBoard[0][i+1];
                    }
                
                    
                    if(board[0][i]==1){ //live cell
                        if(sum==2||sum==3){
                            board[0][i]=1;
                        }else{
                            board[0][i]=0;
                        }
                    }else{ //dead cell
                        if(sum==3){
                            board[0][i]=1;
                        }else{
                            board[0][i]=0;
                        }
                    }
                }
            }
            
            return;
            
        }
        
        if(board[0].size()==1){ //only one col
            for(int i=0;i<board.size();i++){
                int sum=0;
                if(i==0){ //first one{
                    sum=copyBoard[i+1][0];
                }else if(i==board.size()-1){ //last one
                    sum=copyBoard[i-1][0];
                }else{
                    sum=copyBoard[i-1][0]+copyBoard[i+1][0];
                }
            
                
                if(board[i][0]==1){ //live cell
                    if(sum==2||sum==3){
                        board[i][0]=1;
                    }else{
                        board[i][0]=0;
                    }
                }else{ //dead cell
                    if(sum==3){
                        board[i][0]=1;
                    }else{
                        board[i][0]=0;
                    }
                }
            }
            
            return;
        }
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                int sum=0;
                if(i==0){ //first row
                    if(j==0){ //first col
                    //check three
                        sum=copyBoard[i+1][j]+copyBoard[i][j+1]+copyBoard[i+1][j+1];
                    }else if(j==board[i].size()-1){ //last col
                    //check three
                        sum=copyBoard[i+1][j]+copyBoard[i][j-1]+copyBoard[i+1][j-1];
                    }else{ //others
                    //check five    
                        sum=copyBoard[i+1][j]+copyBoard[i][j-1]+copyBoard[i+1][j-1]+copyBoard[i][j+1]+copyBoard[i+1][j+1];
                    }
                }else if(i==board.size()-1){ //last row
                    if(j==0){ //first col
                    //check three
                        sum=copyBoard[i-1][j]+copyBoard[i][j+1]+copyBoard[i-1][j+1];
                    }else if(j==board[i].size()-1){ //last col
                    //check three
                        sum=copyBoard[i-1][j]+copyBoard[i][j-1]+copyBoard[i-1][j-1];
                    }else{ //others
                    //check five
                        sum=copyBoard[i-1][j]+copyBoard[i][j-1]+copyBoard[i-1][j-1]+copyBoard[i][j+1]+copyBoard[i-1][j+1];
                    }
                }else{  //others
                    if(j==0){ //first col
                    //check five
                        sum=copyBoard[i-1][j]+copyBoard[i-1][j+1]+copyBoard[i][j+1]+copyBoard[i+1][j+1]+copyBoard[i+1][j];
                    }else if(j==board[i].size()-1){ //last col
                    //check six 
                        sum=copyBoard[i-1][j]+copyBoard[i-1][j-1]+copyBoard[i][j-1]+copyBoard[i+1][j-1]+copyBoard[i+1][j];
                    }else{ //others
                    //check 8   
                        sum=copyBoard[i-1][j]+copyBoard[i-1][j-1]+copyBoard[i][j-1]+copyBoard[i+1][j-1]+copyBoard[i+1][j]+
                        copyBoard[i-1][j+1]+copyBoard[i][j+1]+copyBoard[i+1][j+1];
                    }
                }
                
                if(board[i][j]==1){ //live cell
                    if(sum==2||sum==3){
                        board[i][j]=1;
                    }else{
                        board[i][j]=0;
                    }
                }else{ //dead cell
                    if(sum==3){
                        board[i][j]=1;
                    }else{
                        board[i][j]=0;
                    }
                }
            }
        }
        
        return;
    }
};

int main(){
    
    return 0;
}