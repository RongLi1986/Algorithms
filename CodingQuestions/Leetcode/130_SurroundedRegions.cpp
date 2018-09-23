/*
Surrounded Regions Total Accepted: 25802 Total Submissions: 176501 My Submissions Question Solution 
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/


/*
run BFS from 'O' points in four edge of board. change each visited 'O' to 'Y'
then replace left 'O' to 'X' (these points are surrounded by X), and 'Y' to 'O'

tips: for large data set, recursive BFS will cause stack overflow.
so it need iterative BFS.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char> > &board) {
        int RowSize=board.size();
        if(RowSize==0) return;  //for []
        int ColSize=board[0].size();
        
        //mark Y
        //row scan and col scan
        for(int i=0;i<RowSize;i++){
            BFS(board,i,0);
            BFS(board,i,ColSize-1);
        }
        for(int j=0;j<ColSize;j++){
            BFS(board,0,j);
            BFS(board,RowSize-1,j);
        }
        
        //change board O to X and Y to O
        for(int j=0;j<RowSize;j++){
            for(int i=0;i<ColSize;i++){
                if(board[j][i]=='O')
                    board[j][i]='X';
                if(board[j][i]=='Y')
                    board[j][i]='O';
            }
        }
        
        return;
    }
    
    //it must be iterative's BFS
    void BFS(vector<vector<char> > &board, int i, int j){
        int rowNum = board.size(), colNum = board[0].size();
        if(i<0 || j<0 || i>=rowNum || j>=colNum || board[i][j]!='O') return;
        stack<pair<int,int>> s;
        s.push(make_pair(i,j));
        int x,y;
        while(!s.empty()) {
            x = s.top().first;
            y = s.top().second;
            s.pop();
            board[x][y] = 'Y';
            if(x>0 && board[x-1][y]=='O') s.push(make_pair(x-1,y));
            if(x<rowNum-1 && board[x+1][y]=='O') s.push(make_pair(x+1,y));
            if(y>0 && board[x][y-1]=='O') s.push(make_pair(x,y-1));
            if(y<colNum-1 && board[x][y+1]=='O') s.push(make_pair(x,y+1));
        }

        return;
    }
    
};

class Solution_old {
private:
    enum direction {up, right, down, left};
public:
    
    void solve(vector<vector<char> > &board) {
        int RowSize=board.size();
        if(RowSize==0) return;  //for []
        
        int ColSize=board[0].size();
        

        vector<vector<int> > record(RowSize,vector<int> (ColSize,0));
        direction u=up;
        direction d=down;
        direction l=left;
        direction r=right;
        //inital board  up down
        for(int i=1;i<ColSize-1;i++){
        	if(board[0][i]=='O'){
        		record[0][i]=1;
        		BFS(board,record,1,i,d);
        	}


        	if(board[RowSize-1][i]=='O'){
        		record[RowSize-1][i]=1;
        		BFS(board,record,RowSize-2,i,u);
        	}
        }

        //inital board  left right
        for(int j=1;j<RowSize-1;j++){
        	if(board[j][0]=='O'){
        		record[j][0]=1;
        		BFS(board,record,j,1,r);
        	}

        	if(board[j][ColSize-1]=='O'){
        		record[j][ColSize-1]=1;
        		BFS(board,record,j,ColSize-2,l);
        	}
        }
        
        //change board
        for(int j=1;j<RowSize-1;j++)
        	for(int i=1;i<ColSize-1;i++){
        		if(board[j][i]=='O'&& record[j][i]==0)
        			board[j][i]='X';
        	}

        return;
    }

    void BFS(vector<vector<char> > &board, vector<vector<int> > &record, int rowNum, int colNum, direction in){
    	if(rowNum>=board.size() || rowNum<=0) return;
    	if(colNum>=board[0].size() || colNum<=0) return;

        direction u=up;
        direction d=down;
        direction l=left;
        direction r=right;

    	if(board[rowNum][colNum]=='O'&&record[rowNum][colNum]==0){
    		record[rowNum][colNum]=1;
    		if(in!=up){
    			BFS(board,record,rowNum+1,colNum,u);
                BFS(board,record,rowNum,colNum+1,l);
                BFS(board,record,rowNum,colNum-1,r);
            }
    		if(in!=down){
    			BFS(board,record,rowNum-1,colNum,d);
                BFS(board,record,rowNum,colNum+1,l);
                BFS(board,record,rowNum,colNum-1,r);
            }
    		if(in!=right){
    			BFS(board,record,rowNum-1,colNum,d);
                BFS(board,record,rowNum,colNum-1,r);
                BFS(board,record,rowNum+1,colNum,u);
            }
    		if(in!=left){
                BFS(board,record,rowNum-1,colNum,d);
                BFS(board,record,rowNum+1,colNum,u);
                BFS(board,record,rowNum,colNum-1,r);

            }
    	}

    	return;
    }
};


int main(){
    
    vector<vector<char> > board;
    /*
    vector<char> tmp={'X','X','X','X'};
    vector<char> tmp1={'X','O','O','X'};
    vector<char> tmp2={'X','X','O','X'};

    board.push_back(tmp2);
    board.push_back(tmp1);
    board.push_back(tmp1);
    board.push_back(tmp);
    */

    Solution s;
    s.solve(board);

    /*
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
	*/
    return 0;
}