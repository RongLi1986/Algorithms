/*
N-Queens Total Accepted: 30362 Total Submissions: 114511 My Submissions Question Solution 
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

//replace by array 
class Solution{
private:
    vector<vector<string> > out;
    
    int* rowSet;
    int* colSet;
    int* diagSetPos;
    int* diagSetNeg;
public:
    vector<vector<string> > solveNQueens(int n) {
        if(n<=0) return out;
        
        //inital broad array
        rowSet=new int[n];
        colSet=new int[n];
        diagSetPos=new int[2*n-1];
        diagSetNeg=new int[2*n-1];
        
        for(int i=0;i<n;i++){
            rowSet[i]=0;
            colSet[i]=0;
        }
        
        for(int i=0;i<2*n-1;i++){
            diagSetPos[i]=0;
            diagSetNeg[i]=0;
        }

        vector<string> tmp;
        string str(n,'.');
        
        checkQueen(0,n,tmp,str);

        //release mem
        delete rowSet;
        delete colSet;
        delete diagSetPos;
        delete diagSetNeg;

        return out;
    }

    void checkQueen(int row, int size, vector<string> tmp, string &str){
        if(row==size) {
            out.push_back(tmp);
            return;
        }

        for(int i=0;i<size;i++){
            if(validPos(row,i,size)){
                str[i]='Q';
                tmp.push_back(str);
                str[i]='.';

                rowSet[row]=1;
                colSet[i]=1;
                diagSetPos[row+i]=1;
                diagSetNeg[row-i+size-1]=1;   
                
                checkQueen(row+1,size,tmp,str);
                
                rowSet[row]=0;
                colSet[i]=0;
                diagSetPos[row+i]=0;
                diagSetNeg[row-i+size-1]=0;

                tmp.pop_back();
            }
        }
    }

    bool validPos(int row, int col, int size){
        if(rowSet[row]==1){
            return false;
        }
        if(colSet[col]==1){
            return false;
        }
        if(diagSetPos[row+col]==1){
            return false;
        }
        if(diagSetNeg[row-col+size-1]==1){
            return false;
        }
        return true;
    }
};


//not fast
class Solution_old {
private:
	unordered_set<int> rowSet;
	unordered_set<int> colSet;
	unordered_set<int> diagSetPos;
	unordered_set<int> diagSetNeg;

    vector<vector<string> > out;
public:
    vector<vector<string> > solveNQueens(int n) {
        if(n<=0) return out;
        vector<string> tmp;
        string str(n,'.');
        checkQueen(0,n,tmp,str);
    	return out;
    }

    void checkQueen(int row, int size, vector<string> &tmp, string &str){
    	if(row>=size) {
            out.push_back(tmp);
    		return;
    	}
    	for(int i=0;i<size;i++){
    		if(validPos(row,i,size)){
                str[i]='Q';
                tmp.push_back(str);
    			str[i]='.';

                rowSet.insert(row);
    			colSet.insert(i);
    			diagSetPos.insert(row+i);
    			diagSetNeg.insert(row-i);	
    			checkQueen(row+1,size,tmp,str);
    			rowSet.erase(row);
    			colSet.erase(i);
    			diagSetPos.erase(row+i);
    			diagSetNeg.erase(row-i);
                
                tmp.pop_back();
    		}
    	}
    }

    bool validPos(int row, int col, int size){
    	if(rowSet.find(row)!=rowSet.end()){
    		return false;
    	}
    	if(colSet.find(col)!=colSet.end()){
    		return false;
    	}
    	
    	if(diagSetPos.find(row+col)!=diagSetPos.end()){
    		return false;
    	}
    	if(diagSetNeg.find(row-col)!=diagSetNeg.end()){
    		return false;
    	}
    	
    	return true;
    }
};

int main(){
	Solution s;	//for(int i=0;i<10;i++)
    vector<vector<string> > out=s.solveNQueens(4);

    for(int i=0;i<out.size();i++)
        for(int j=0;j<out[i].size();j++)
            cout<<out[i][j]<<endl;
	//string str(5,'.');
    //cout<<str<<endl;
    return 0;
}